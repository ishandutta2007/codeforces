#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 200005LL

using namespace std;

//map<pair<int, int>, int> M;
//map<long long, int> M;
//set<long long> adj;
set<int> adj[200005];
set<int> S;
int cnt = 0;
vector<int> V;
queue<int> q;
bool visited[200005];
//set<pair<int, int> > adj;

/*
void DFS(int now) {
	//printf("%d\n", now);
	cnt++;
	S.erase(S.find(now));
	for(set<int>::iterator it = S.begin(); it != S.end(); ) {
		if((*it) == now) continue;
		int next = (*it);
		//printf("%d %d\n", now, next);
		//if(M[make_pair(now, next)] || M[make_pair(next, now)]) { it++; continue; }

			long long chk1 = min(now, next), chk2 = max(now, next);
			if(adj.find(MAXN * chk1 + chk2) != adj.end()) { it++; continue; }
		DFS(next);
		S.insert(next);
		it = S.find(next); it++;
		if(it == S.end()) { S.erase(next); break; }
		int tmp = (*it);
		S.erase(next); it = S.find(tmp);
	}
}*/

void BFS(int v) {
	while(!q.empty()) q.pop();
	q.push(v); visited[v] = true; cnt++;
	S.erase(S.find(v));
	while(!q.empty()) {
		int now = q.front(); q.pop();
		//printf("%d\n", now);
		for(set<int>::iterator it = S.begin(); it != S.end(); ) {
			if((*it) == now) { it++; continue; }
			int next = (*it);
			long long chk1 = min(now, next), chk2 = max(now, next);
			//if(adj.find(MAXN * chk1 + chk2) != adj.end()) { it++; continue; }
			if(adj[chk1].find(chk2) != adj[chk1].end()) { it++; continue; }

			//if(M[MAXN * chk1 + chk2]) { it++; continue; }
			//if(M[MAXN * now + next]) { it++; continue; }
			//if(M[make_pair(now, next)]) { it++; continue; }
			//if(adj.find(make_pair(now, next)) != adj.end()) { it++; continue; }
			//printf("%d %d\n", now, next);
			visited[next] = true; q.push(next); cnt++;
			it = S.find(next); it++;
			if(it == S.end()) { S.erase(next); break; }
			int tmp = (*it);
			S.erase(next); it = S.find(tmp);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int N, Q; scanf("%d %d", &N, &Q);

	for(int i = 0; i < Q; i++) {
		int a, b; scanf("%d %d", &a, &b); //M[make_pair(a, b)]++; M[make_pair(b, a)]++;
		//adj.insert(make_pair(a, b)); adj.insert(make_pair(b, a));
		if(a < b) adj[a].insert(b); //adj.insert(MAXN * a + b); //M[MAXN * a + b]++;
		else adj[b].insert(a); //adj.insert(MAXN * b + a); // M[MAXN * b + a]++;
		//M[MAXN * a + b]++; M[MAXN * b + a]++;
	}

	for(int i = 1; i <= N; i++) S.insert(i);

	int ans = 0;

	for(int i = 1; i <= N; i++) {
		if(visited[i]) continue;
		ans++; cnt = 0;
		BFS(i); V.push_back(cnt);
	}
	if(S.size()) return 0;
	/*
	while(!S.empty()) {
		cnt = 0;
		set<int>::iterator it = S.begin();
		int now = *it;
		ans++; DFS(now);
		V.push_back(cnt);
	}*/
	printf("%d\n", ans);
	sort(V.begin(), V.end());
	for(int i = 0; i < V.size(); i++) {
		printf("%d ", V[i]);
	}
	return 0;
}