#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int C = 26;

int qu, m, pos[MAXN], nxt[MAXN][C], sz, f[MAXN];
string t[MAXN];
vector<int> adj[MAXN];
bool in[MAXN];

int insert(string &s){
	int cur = 0;
	for (char c:s){
		int x = int(c - 'a');
		if (!nxt[cur][x])
			nxt[cur][x] = ++sz;
		cur = nxt[cur][x];
	}
	return cur;
}

int q[MAXN];
void buildAho(){
	int h = 0, t = 0;
	for (int w = 0; w < C; w++)
		if (nxt[0][w])
			q[t++] = nxt[0][w];

	while (t^h){
		int v = q[h++];
		for (int w = 0; w < C; w++)
			if (nxt[v][w]){
				f[nxt[v][w]] = nxt[f[v]][w];
				q[t++] = nxt[v][w];
			}
			else
				nxt[v][w] = nxt[f[v]][w];
	}

	for (int i = 1; i <= sz; i++)
		adj[f[i]].push_back(i);
}

#define tm klajdsf
int st[MAXN], ft[MAXN], tm;

void dfs(int v){
	st[v] = tm++;
	for (int u:adj[v])
		dfs(u);
	ft[v] = tm;
}

int fen[MAXN];
void add(int v, int val){for (v++; v<MAXN; v+=v&-v) fen[v] += val;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v) ret += fen[v];
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> qu >> m;
	for (int i = 0; i < m; i++){
		cin >> t[i];
		pos[i] = insert(t[i]);
		in[i] = true;
	}
	buildAho();
	dfs(0);
	for (int i = 0; i < m; i++)
		add(st[pos[i]], 1), add(ft[pos[i]], -1);

	while (qu--){
		char t; cin >> t;
		if (t == '?'){
			long long ans = 0;
			int cur = 0;
			string s; cin >> s;
			for (char c:s){
				int x = int(c - 'a');
				cur = nxt[cur][x];
				ans += get(st[cur]+1);
			}
			cout << ans << "\n";
		}
		else if (t == '-'){
			int id; cin >> id, id--;
			if (in[id]){
				in[id] = false;
				add(st[pos[id]], -1), add(ft[pos[id]], 1);
			}
		}
		else if (t == '+'){
			int id; cin >> id, id--;
			if (!in[id]){
				in[id] = true;
				add(st[pos[id]], 1), add(ft[pos[id]], -1);
			}
		}
	}
	return 0;
}