#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int C = 26 + 2;
const int SQ = 540;
const int MAXN = 3e5 + 10;

#define F first
#define S second

int tr[C][MAXN], sz, mark[MAXN], cnt[MAXN];

void insert(string &s){
	int cur = 0;
	cnt[cur]++;
	for (char ch:s){
		if (!tr[ch - 'a'][cur])
			tr[ch - 'a'][cur] = ++sz;
		cur = tr[ch - 'a'][cur];
		cnt[cur]++;
	}
	mark[cur]++;
}

void erase(string &s){
	int cur = 0;
	cnt[cur]--;
	for (char ch:s){
		cur = tr[ch - 'a'][cur];
		cnt[cur]--;
	}
	mark[cur]--;
}

int q[MAXN], f[MAXN], nxt[C][MAXN];
vector<int>	adj[MAXN];

void plant(){
	for (int i = 0; i < MAXN; i++)	adj[i].clear();
	memset(f, 0, sizeof(f));
	memset(nxt, 0, sizeof(nxt));

	int h = 0, t = 0;
	for (int w = 0; w < C; w++)
		if (tr[w][0])
			q[t++] = tr[w][0], nxt[w][0] = tr[w][0];

	while (h < t){
		int v = q[h++];
		adj[f[v]].push_back(v);
		for (int w = 0; w < C; w++)
			if (tr[w][v]){
				f[tr[w][v]] = nxt[w][f[v]];
				nxt[w][v] = tr[w][v];
				q[t++] = tr[w][v];
			}
			else
				nxt[w][v] = nxt[w][f[v]];
	}
}

int val[MAXN];

void go(int v, int sm = 0){
	sm += mark[v];
	val[v] = sm;
	for (int u:adj[v])
		go(u, sm);
}

ll getAho(string &s){
	plant();
	memset(val, 0, sizeof(val));
	go(0);

	ll ret = 0;
	int cur = 0;
	for (int i = 0; i < (int)s.size(); i++){
		cur = nxt[s[i] - 'a'][cur];
		ret += val[cur];
	}
	return ret;
}

ll get(string &s){
	ll ret = 0;
	int n = s.size();
	for (int i = 0; i < n; i++){
		int cur = 0;
		for (int j = i; j < n; j++){
			if (!tr[s[j] - 'a'][cur])	break;
			cur = tr[s[j] - 'a'][cur];
			ret += mark[cur];
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;	cin >> m;
	while (m--){
		int type;	cin >> type;
		if (type == 1){
			string s;	cin >> s;
			insert(s);
		}
		if (type == 2){
			string s;	cin >> s;
			erase(s);
		}
		if (type == 3){
			string s;	cin >> s;
			if (s.size() >= SQ)
				cout << getAho(s) << endl;
			else
				cout << get(s) << endl;
		}
	}
	return 0;
}