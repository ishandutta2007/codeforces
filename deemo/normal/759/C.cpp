#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int SQ = 320;

int n, rem[MAXN], val[MAXN], cc[MAXN];
bool in[MAXN], tp[MAXN];
vector<int>	vec[MAXN];

void refresh(int pos){
	int id = pos/SQ;
	int l = id*SQ;
	vec[id].resize(0);
	cc[id] = 0;
	for (int i = l; i < n && i < l + SQ; i++)
		if (in[i]){
			if (!tp[i]){
				if (vec[id].size())
					vec[id].pop_back();
				else
					cc[id]++;
			}
			else
				vec[id].push_back(val[i]);
		}
}

pair<int, int>	sec[MAXN];
int sz;
int get(){
	sz = 0;
	for (int i = 0, id = 0; i < n; i += SQ, id++){
		int rem = cc[id];
		while (rem && sz){
			int g = min(rem, sec[sz - 1].S);
			rem -= g;
			sec[sz - 1].S -= g;
			if (sec[sz - 1].S == 0)	sz--;
		}

		if (vec[id].size())
			sec[sz++] = {id, vec[id].size()};
	}

	if (!sz)
		return -1;
	return vec[sec[sz - 1].F][sec[sz - 1].S-1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int t, type;	cin >> t >> type;	t--;
		if (type){
			tp[t] = 1;
			cin >> val[t];
		}
		in[t] = 1;
		refresh(t);
		cout << get() << "\n";
	}
	return 0;
}