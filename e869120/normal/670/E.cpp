#include<iostream>
#include<string>
using namespace std;
int n, m, p, L[600000], R[600000]; string S, T;
int main() {
	cin >> n >> m >> p >> S >> T; S = '-' + S;
	for (int i = 0; i <= n + 1; i++) { L[i] = i - 1; R[i] = i + 1; }
	for (int i = 0; i < T.size(); i++) {
		if (T[i] == 'L')p = L[p];
		if (T[i] == 'R')p = R[p];
		if (T[i] == 'D') {
			int V = p, depth = 0;
			if (S[p] == '(') { depth++; V = R[V]; while (depth > 0) { if (S[V] == '(')depth++; else depth--; V = R[V]; }V = L[V]; }
			if (S[p] == ')') { depth++; V = L[V]; while (depth > 0) { if (S[V] == '(')depth--; else depth++; V = L[V]; }V = R[V]; }
			
			int a1 = V, a2 = p; if (a1 > a2)swap(a1, a2); p = R[a2]; if (R[a2] == S.size())p = L[a1];
			if (a1 >= 1)R[L[a1]] = R[a2]; L[R[a2]] = L[a1];
		}
	}
	int F = R[0]; while (F < S.size()) { cout << S[F]; F = R[F]; }cout << endl;
	return 0;
}