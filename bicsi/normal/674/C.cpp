#include <bits/stdc++.h>

using namespace std;

double Tok[200005], T[200005], U[200005], SP[200005], A[200005], B[200005];
double DP[200005], Ant[200005];
deque<int> Q;

#define var_dump(x) cerr<<#x<<": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x<<"[]: ";for(int i=1; i<=n; ++i) cerr<<x[i]<<" ";cerr<<endl;}

double Eval(int j, int i) {
	return T[i] + Ant[j] + A[j] + U[i] * B[j];
}

double Inter(int i, int j) {
	double ai = Ant[i] + A[i],
		   aj = Ant[j] + A[j],
		   bi = B[i],
		   bj = B[j];

// Rezolv ai + x * bi == aj + x * bj
// ai - aj = x * (bj - bi)
	return (ai - aj) / (bj - bi);
}

int main() {
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; ++i) {
		cin >> Tok[i];
		SP[i] = SP[i - 1] + Tok[i];

		T[i] = T[i - 1] + SP[i] / Tok[i];
		U[i] = U[i - 1] + 1.0 / Tok[i];
		A[i] = -T[i] + SP[i] * U[i];
		B[i] = -SP[i];
		DP[i] = 1e16;

		assert(A[i] + 1e-9 > A[i - 1]);
	}

	//arr_dump(A, n);
	//arr_dump(B, n);

	for(int it = 1; it <= k; ++it) {
		memcpy(Ant, DP, sizeof(Ant));
		Q.clear();
		Q.push_back(0);

		for(int i = 1; i <= n; ++i) {
			while(Q.size() >= 2 && Eval(Q[0], i) + 1e-9 > Eval(Q[1], i))
				Q.pop_front();

			DP[i] = Eval(Q[0], i);
			
			while(Q.size() >= 2 && Inter(i, Q[Q.size() - 1]) - 1e-9 < Inter(Q[Q.size() - 1], Q[Q.size() - 2]))
				Q.pop_back();

			Q.push_back(i);
		}
	}

	cout << fixed << setprecision(15) << DP[n];


	return 0;
}