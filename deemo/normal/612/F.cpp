#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<cassert>

using namespace std;

const int MAXN = 2e3 + 10;

int n, m, vec[MAXN], sec[MAXN];
int d[MAXN][MAXN], par[MAXN][MAXN];
vector<int>	gec[MAXN];
bool mark[MAXN][MAXN];

int solve(int pos, int cur){
	if (mark[pos][cur])	
		return	d[pos][cur];
	mark[pos][cur] = 1;
	if (cur == m)	return	d[pos][cur] = 0;
	
	d[pos][cur] = 1e9;
	int sz = gec[cur].size(), val = cur;
	int ind = lower_bound(gec[val].begin(), gec[val].end(), pos) - gec[val].begin();
	ind %= sz;
	for (int i = ind, c = 0; c < sz; i = (i + 1) % sz, c++){
		int tt = 0;
		if (gec[val][i] >= pos){
			tt += gec[val][i] - pos;
			if (c != sz - 1){
				if (i == sz - 1)
					tt += n - (n - gec[val][i] + gec[val][0]);
				else
					tt += n - (gec[val][i + 1] - gec[val][i]);
			}
		}
		else{
			tt += n - pos + gec[val][i];
			if (c != sz - 1)
				tt += n - (gec[val][i + 1] - gec[val][i]);
		}

		int nid;
		if (c == sz - 1)	nid = i;
		else nid = (i + 1) % sz;

		if (d[pos][cur] > tt + solve(gec[val][nid], cur + 1)){
			d[pos][cur] = tt + solve(gec[val][nid], cur + 1);
			par[pos][cur] = i + 1;
		}
	}
	
	if (gec[val][ind] != pos)
		ind = (ind + sz - 1) % sz;
	for (int i = ind, c = 0; c < sz; i = (i + sz - 1) % sz, c++){
		int tt = 0;
		if (gec[val][i] > pos){
			tt += n - (gec[val][i] - pos);
			if (c != sz - 1)
				tt += n - (gec[val][i] - gec[val][i - 1]);
		}
		else{
			tt += pos - gec[val][i];
			if (c != sz - 1){
				if (i)
					tt += n - (gec[val][i] - gec[val][i - 1]);
				else
					tt += n - (gec[val][i] + n - gec[val][sz - 1]);
			}
		}

		int nid;
		if (c == sz - 1)	nid = i;
		else nid = (i + sz - 1) % sz;

		if (d[pos][cur] > tt + solve(gec[val][nid], cur + 1)){
			d[pos][cur] = tt + solve(gec[val][nid], cur + 1);
			par[pos][cur] = -(i + 1);
		}
	}
	return	d[pos][cur];
}

void show(int pos, int cur){
	if (cur == m)	return;
	int nxt = par[pos][cur], val = cur, sz = gec[cur].size();	
	int ind = lower_bound(gec[val].begin(), gec[val].end(), pos) - gec[val].begin();
	ind %= sz;
	if (nxt >= 0){
		nxt--;
		int tp = pos, mv = 0;
		for (int i = ind; mv < sz; i = (i + 1) % sz){
			cout << "+";
			if (gec[val][i] >= tp)
				cout << gec[val][i] - tp << "\n";
			else
				cout << n - (tp - gec[val][i]) << "\n";
			tp = gec[val][i];
			mv++;
			if (i == nxt)	break;
		}
		for (int i = (ind + sz - 1) % sz; mv < sz && i != nxt; i = (i + sz - 1) % sz){
			cout << "-";
			mv++;
			if (gec[val][i] <= tp)
				cout << tp - gec[val][i] << "\n";
			else
				cout << n - (gec[val][i] - tp) << "\n";
			tp = gec[val][i];
		}
		show(tp, cur + 1);
	}
	else{
		if (gec[val][ind] != pos)
			ind = (ind + sz - 1) % sz;

		nxt = -nxt;
		nxt--;
		int tp = pos, mv = 0;
		for (int i = ind; mv < sz; i = (i + sz - 1) % sz){
			cout << "-";
			mv++;
			if (gec[val][i] <= tp)
				cout << tp - gec[val][i] << "\n";
			else
				cout << n - (gec[val][i] - tp) << "\n";
			tp = gec[val][i];
			if (i == nxt)	break;
		}
		for (int i = (ind + 1) % sz; mv < sz && i != nxt; i = (i + 1) % sz){
			cout << "+";
			mv++;
			if (gec[val][i] >= tp)
				cout << gec[val][i] - tp << "\n";
			else
				cout << n - (tp - gec[val][i]) << "\n";
			tp = gec[val][i];
		}
		show(tp, cur + 1);
	}
}

int main(){
	memset(par, -1, sizeof(par));
	int s;	cin >> n >> s;	s--;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	memcpy(sec, vec, sizeof(vec));
	sort(sec, sec + n);
	m = unique(sec, sec + n) - sec;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vec[i] == sec[j]){
				vec[i] = j;
				break;
			}
	for (int i = 0; i < n; i++)
		gec[vec[i]].push_back(i);
	cout << solve(s, 0) << "\n";
	show(s, 0);
	return	0;
}