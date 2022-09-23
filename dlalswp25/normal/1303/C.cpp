#include <bits/stdc++.h>

using namespace std;

char S[205];
vector<int> adj[30];
bool vst[30];
vector<char> ans;

void dfs(int x) {
	ans.push_back(x + 'a');
	vst[x] = true;
	for(int i : adj[x]) {
		if(vst[i]) continue;
		dfs(i);
	}
} 

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ans.clear();
		for(int i = 0; i < 26; i++) { adj[i].clear(); vst[i] = false; }
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		for(int i = 1; i < N; i++) {
			int a = S[i] - 'a';
			int b = S[i + 1] - 'a';
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for(int i = 0; i < 26; i++) {
			sort(adj[i].begin(), adj[i].end());
			adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
		}

		bool ok = true;
		for(int i = 0; i < 26; i++) if(adj[i].size() > 2) ok = false;
		if(!ok) { puts("NO"); continue; }

		for(int i = 0; i < 26; i++) {
			if(vst[i]) continue;
			if(adj[i].size() < 2) dfs(i);
		}
		for(int i = 0; i < 26; i++) if(!vst[i]) ok = false;
		if(!ok) { puts("NO"); continue; }
		puts("YES");
		for(char i : ans) printf("%c", i); puts("");
	}

	return 0;
}