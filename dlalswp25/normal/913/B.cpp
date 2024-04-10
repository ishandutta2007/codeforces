#include <stdio.h>
#include <vector>

using namespace std;

vector<int> adj[1005];
bool leaf[1005];

int main() {
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int a; scanf("%d", &a);
		adj[a].push_back(i);
	}
	for(int i = 2; i <= n; i++) if(adj[i].size() == 0) leaf[i] = true;
		bool ok = true;
	for(int i = 1; i <= n; i++) {
		if(leaf[i]) continue;
		int cnt = 0;
		for(int j = 0; j < adj[i].size(); j++) {
			int now = adj[i][j];
			if(leaf[now]) cnt++;
		}
		if(cnt < 3) ok = false;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}