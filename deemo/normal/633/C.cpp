#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;
const int XX = 1e6 + 10;
const int C = 'a' - 'A';

int n, m, f[MAXM];
int p[MAXM], tr[XX][30], ss[XX], sz;
bool can[MAXM], done[XX];
string s, t[MAXM];

void insert(int ind){
	int cur = 0;
	for (int i = 0; i < t[ind].size(); i++){
		char ch = t[ind][i];
		if (ch < 'a')	ch += 'a' - 'A';
		if (tr[cur][ch - 'a'] == 0)
			tr[cur][ch - 'a'] = ++sz;
		cur = tr[cur][ch - 'a'];
	}
	done[cur] = 1, ss[cur] = ind;
}

void show(int rem){
	if (rem == 0)	return;
	show(rem - (int)t[p[rem]].size());
	cout << t[p[rem]] << " ";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> m;
	for (int i = 0; i < m; i++){
		cin >> t[i];
		insert(i);
	}
	
	can[0] = 1;
	for (int i = 0; i < (int)s.size(); i++){
		int cur = 0, j = i;
		while (j >= 0){
			cur = tr[cur][s[j] - 'a'];
			if (cur == 0 || (can[j] && done[cur]))	break;
			j--;
		}
		if (j >= 0 && cur && done[cur] && can[j])
			can[i + 1] = 1, p[i + 1] = ss[cur];
	}
	show(n);
	cout << "\n";
	return	0;
}