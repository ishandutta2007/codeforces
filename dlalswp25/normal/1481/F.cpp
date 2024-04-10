#include <bits/stdc++.h>

using namespace std;

const int BSZ = 500;

int N, X;
vector<int> adj[101010];
vector<int> ds[101010];
vector<int> vs[101010];
int dep[101010];
int D[101010];
int path[101010];
int cnt[101010];
bool chk[101010];
char ans[101010];
int mx;
int id;

map<int, int> mp;

void dfs(int v) {
	mx = max(mx, dep[v]);
	cnt[dep[v]]++;
	vs[dep[v]].push_back(v);
	for(int i : adj[v]) {
		dep[i] = dep[v] + 1;
		dfs(i);
	}
}

int main() {
	scanf("%d%d", &N, &X);

	for(int i = 2; i <= N; i++) {
		int p; scanf("%d", &p);
		adj[p].push_back(i);
	}

	dep[1] = 1; dfs(1);

	D[0] = 1;
	for(int i = 1; i <= mx; i++) {
		mp[cnt[i]]++;
		ds[cnt[i]].push_back(i);
	}
	for(auto& i : mp) {
		for(int j = 0; j < i.first; j++) {
			int lft = 0;
			for(int k = j; k <= N; k += i.first) {
				if(D[k]) lft = i.second;
				//else if(lft && k >= i.first && D[k - i.first]) {
				else if(lft) {
					D[k] = 1; lft--;
					path[k] = ds[i.first][lft];
				}
			}
		}
	}

	if(D[X]) {
		printf("%d\n", mx);
		int now = X;
		while(now) {
			chk[path[now]] = true;
			now -= cnt[path[now]];
		}
		for(int i = 1; i <= N; i++) printf("%c", chk[dep[i]] ? 'a' : 'b'); puts("");
		return 0;
	}

	int A = X, B = N - X;
	for(int i = 1; i <= mx; i++) {
		if(A >= cnt[i]) {
			for(int j : vs[i]) ans[j] = 'a';
			A -= cnt[i];
		}
		else if(B >= cnt[i]) {
			for(int j : vs[i]) ans[j] = 'b';
			B -= cnt[i];
		}
		else if(A > B) {
			for(int j : vs[i]) {
				if(adj[j].size()) { A--; ans[j] = 'a'; }
			}
			for(int j : vs[i]) {
				if(adj[j].size()) continue;
				if(A) { A--; ans[j] = 'a'; }
				else { B--; ans[j] = 'b'; }
			}
		}
		else {
			for(int j : vs[i]) {
				if(adj[j].size()) { B--; ans[j] = 'b'; }
			}
			for(int j : vs[i]) {
				if(adj[j].size()) continue;
				if(B) { B--; ans[j] = 'b'; }
				else { A--; ans[j] = 'a'; }
			}
		}
	}

	printf("%d\n", mx + 1);
	printf("%s\n", ans + 1);

	return 0;
}