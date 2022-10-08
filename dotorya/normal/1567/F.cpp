#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(i) i.begin(), i.end()
typedef long long ll;
using namespace std;
 
const int BMAX = 505, MAX = 505000;
char B[BMAX][BMAX];
int A[BMAX][BMAX];
vector<int> G[MAX], SCC[MAX], S;;
int V[MAX], fin[MAX], sccn, dfsn;
 
int GetSCC(int cur) {
	// Prerequsites: const int MAX / int visit[MAX], fin[MAX], sccn, dfsn / vector<int> graph[MAX], SCC[MAX], S
	// Decompose SCC: fin[n] is SCC number
	S.push_back(cur);
	int res = V[cur] = ++dfsn;
	for (int& next : G[cur]) {
		if (!V[next]) res = min(res, GetSCC(next));
		else if (!fin[next]) res = min(res, V[next]);
	}
	if (V[cur] == res) {
		sccn++;
		while (1) {
			int t = S.back(); S.pop_back();
			fin[t] = sccn;
			SCC[sccn].push_back(t);
			if (t == cur) break;
		}
	}
	return res;
}
 
void AddOr(int u, int v) {
	G[u ^ 1].push_back(v);
	G[v ^ 1].push_back(u);
}
 
void AddXor(int u, int v) {
	AddOr(u, v);
	AddOr(u ^ 1, v ^ 1);
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, flag = 1;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> B[i][j];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (B[i][j] == '.') continue;
			vector<int> t;
			for (int k = 0; k < 4; ++k) {
				int ny = i + "2101"[k] - '1', nx = j + "1012"[k] - '1';
				if (B[ny][nx] == '.') t.push_back(ny * M + nx);
			}
			if (t.size() % 2) flag = 0;
			else if (t.empty()) A[i][j] = -1; 
			else {
				AddXor(t[0] * 2, t[1] * 2);
				A[i][j] = 5;
				if (t.size() == 4) {
					AddXor(t[2] * 2, t[3] * 2);
					A[i][j] += 5;
				}
			}
		}
	}
if(!flag) {
cout<<"NO\n";
return 0;
}
	for (int i = 1; i <= N * M * 2; ++i) if (!V[i]) GetSCC(i);
	for (int i = 0; i < N * M * 2; i += 2) {
		if (fin[i] == fin[i ^ 1]) flag = 0;
		int t = i / 2;
		int x = t % M, y = t / M;
		if (A[y][x] != 0) continue;
		A[y][x] = (fin[i] > fin[i ^ 1] ? 1 : 4);
	}
	if (flag) {
		cout << "YES\n";
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (B[i][j] == '.' && A[i][j] == 0) A[i][j] = 1;
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (B[i][j] == 'X' && A[i][j] == -1) A[i][j] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cout << A[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else cout << "WTF\n";
	return 0;
}