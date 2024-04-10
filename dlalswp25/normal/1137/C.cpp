#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

vector<int> adj[101010];

int dp[101010][55];
int A[101010];
int B[101010];
bool vst[101010][55];
int N, M, D;

bool chk[101010];
int com[101010];
vector<int> ST;
int cid;
char S[101010][55];

int ok[101010];
int t;

queue<pii> q;
vector<pii> v;

int bfs(int s, int d, vector<pii>& v) {
	int ret = 0;
	q.push({s, d});
	vst[s][d] = true;
	while(q.size()) {
		v.push_back(q.front());
		int now = q.front().first;
		int nd = q.front().second;
		q.pop();
		if(S[now][nd] == '1' && ok[now] != t) {
			ok[now] = t; ret++;
		}
		for(int i : adj[now]) {
			if(com[i] != com[now]) continue;
			if(vst[i][(nd + 1) % D]) continue;
			vst[i][(nd + 1) % D] = true;
			q.push({i, (nd + 1) % D});
		}
	}
	return ret;
}

int f(int now, int d) {
	vector<pii> v;
	if(dp[now][d] != -1) return dp[now][d];
	t++;
	int cur = bfs(now, d, v);
	int mx = 0;
	for(pii i : v) {
		for(int j : adj[i.first]) {
			if(com[j] == com[i.first]) continue;
			mx = max(mx, f(j, (i.second + 1) % D));
		}
	}
	while(v.size()) {
		dp[v.back().first][v.back().second] = cur + mx;
		v.pop_back();
	}
	return cur + mx;
}

void dfs(int now) {
	chk[now] = true;
	for(int i : adj[now]) if(!chk[i]) dfs(i);
	ST.push_back(now);
}
void dfs2(int now, int c) {
	com[now] = c;
	for(int i : adj[now]) if(!com[i]) dfs2(i, c);
}

int main() {
	scanf("%d%d%d", &N, &M, &D);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		adj[A[i]].push_back(B[i]);
	}
	for(int i = 1; i <= N; i++) scanf("%s", S[i]);

	for(int i = 1; i <= N; i++) if(!chk[i]) dfs(i);
	for(int i = 1; i <= N; i++) adj[i].clear();
	reverse(ST.begin(), ST.end());
	for(int i = 1; i <= M; i++) adj[B[i]].push_back(A[i]);
	for(int i : ST) if(!com[i]) {
		cid++; dfs2(i, cid);
	}
	for(int i = 1; i <= N; i++) for(int j = 0; j < D; j++) {
		dp[i][j] = -1;
	}
	for(int i = 1; i <= N; i++) adj[i].clear();
	for(int i = 1; i <= M; i++) adj[A[i]].push_back(B[i]);

	printf("%d\n", f(1, 0));

	return 0;
}