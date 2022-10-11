#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Debug = 1;
int N, M; bool used[609][609];

int ask(vector<int>S) {
	if (S.size() == 0) return 0;

	cout << "? " << S.size() << endl;
	for (int i = 0; i < S.size(); i++) { if (i) cout << " "; cout << S[i]; } cout << endl;
	
	if (Debug == 1) {
		int v; cin >> v;
		return v;
	}
	if (Debug == 2) {
		int cnt = 0;
		for (int i = 0; i < S.size(); i++) {
			for (int j = i + 1; j < S.size(); j++) {
				if (used[S[i]][S[j]] == true) cnt++;
			}
		}
		return cnt;
	}
	return -1;
}

int col[609], par[609]; bool useds[609]; vector<int>G[609];

void dfs(int pos) {
	useds[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		if (useds[G[pos][i]] == true) continue;
		par[G[pos][i]] = pos;
		dfs(G[pos][i]);
	}
}

vector<int> path(int u, int v) {
	for (int i = 1; i <= N; i++) { useds[i] = false; par[i] = -1; }
	dfs(u);

	vector<int>E; int cx = v;
	while (cx >= 1) {
		E.push_back(cx);
		cx = par[cx];
	}
	return E;
}

void solve() {
	vector<bool>I(N + 1, false);

	queue<int>Q; Q.push(1); I[1] = true;
	while (!Q.empty()) {
		int pos = Q.front();
		vector<int>A; for (int i = 1; i <= N; i++) { if (I[i] == false) A.push_back(i); }
		vector<int>B = A; B.push_back(pos);

		int B1 = ask(B) - ask(A);
		if (B1 == 0) Q.pop();
		else {
			while (A.size() >= 2) {
				vector<int>C; for (int i = 0; i < A.size() / 2; i++) C.push_back(A[i]);
				vector<int>D = C; D.push_back(pos);
				int D1 = ask(D) - ask(C);
				if (D1 == 0) { vector<int>E; for (int i = A.size() / 2; i < A.size(); i++) E.push_back(A[i]); A = E; }
				else { A = C; }
			}
			col[A[0]] = (col[pos] ^ 1);
			G[pos].push_back(A[0]);
			G[A[0]].push_back(pos);
			Q.push(A[0]); I[A[0]] = true;
		}
	}

	vector<int>L1, L2;
	for (int i = 1; i <= N; i++) { if (col[i] == 0) L1.push_back(i); else L2.push_back(i); }
	int D1 = ask(L1);
	int D2 = ask(L2);

	if (D1 == 0 && D2 == 0) {
		cout << "Y " << L1.size() << endl;
		for (int i = 0; i < L1.size(); i++) { if (i) cout << " "; cout << L1[i]; } cout << endl;
	}
	else {
		vector<int>T = L1;
		if (D1 == 0) T = L2;

		while (T.size() >= 3) {
			vector<int>P1, P2, P3;
			for (int i = 0; i < T.size(); i++) {
				if (i % 3 == 0 || i % 3 == 1) P1.push_back(T[i]);
				if (i % 3 == 1 || i % 3 == 2) P2.push_back(T[i]);
				if (i % 3 == 2 || i % 3 == 0) P3.push_back(T[i]);
			}
			int Q1 = ask(P1);
			int Q2 = ask(P2);
			int Q3 = ask(P3);
			if (Q1 >= 1) T = P1;
			else if (Q2 >= 1) T = P2;
			else T = P3;
		}

		vector<int> D = path(T[0], T[1]);
		cout << "N " << D.size() << endl;
		for (int i = 0; i < D.size(); i++) { if (i) cout << " "; cout << D[i]; } cout << endl;
	}
}

int main() {
	if (Debug == 1) {
		cin >> N;
	}
	if (Debug == 2) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			used[a][b] = true; used[b][a] = true;
		}
	}
	solve();
	return 0;
}