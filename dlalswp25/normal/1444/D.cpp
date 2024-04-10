#include <bits/stdc++.h>

using namespace std;

bool D[1010][505050];
bool chk;

int A[1010];
vector<int> v;
int S;

int N;
int U[1010];
int V[1010];

vector<int> uh, dh;
vector<int> uv, dv;

vector<int> th, tv;

void f(int n, int s) {
	// printf("%d %d\n", n, s);
	// for(int i : v) printf("%d ", i); puts("");
	// puts("***********");
	if(n > N) {
		if(s == S / 2) chk = true;
		return;
	}
	if(D[n][s]) return;
	D[n][s] = true;
	if(A[n] + s <= S / 2) {
		v.push_back(n);
		f(n + 1, s + A[n]);
		if(chk) return;
		v.pop_back();
	}
	f(n + 1, s);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		uh.clear(); dh.clear(); th.clear();
		uv.clear(); dv.clear(); tv.clear();

		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &U[i]);
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &V[i]);
		if(N != n) { puts("No"); continue; }

		S = 0;
		for(int i = 1; i <= N; i++) { A[i] = U[i]; S += A[i]; }

		if(S & 1) { puts("No"); continue; }

		for(int i = 1; i <= N; i++) for(int j = 0; j <= N * 500; j++) D[i][j] = 0;

		v.clear(); chk = false;
		f(1, 0);
		int t = 0;
		for(int i : v) t += A[i];
		if(t != S / 2) { puts("No"); continue; }

		for(int i : v) U[i] *= -1;
		for(int i = 1; i <= N; i++) {
			if(U[i] > 0) uh.push_back(U[i]);
			else dh.push_back(U[i]);
		}

		v.clear(); chk = false;
		S = 0;
		for(int i = 1; i <= N; i++) { A[i] = V[i]; S += A[i]; }
		if(S & 1) { puts("No"); continue; }
		for(int i = 1; i <= N; i++) for(int j = 0; j <= N * 500; j++) D[i][j] = 0;

		f(1, 0);
		t = 0;
		for(int i : v) t += A[i];
		if(t != S / 2) { puts("No"); continue; }

		for(int i : v) V[i] *= -1;
		for(int i = 1; i <= N; i++) {
			if(V[i] > 0) uv.push_back(V[i]);
			else dv.push_back(V[i]);
		}

		sort(uh.begin(), uh.end());
		sort(dh.begin(), dh.end());
		sort(uv.begin(), uv.end());
		sort(dv.begin(), dv.end());

		puts("Yes");
		int x = 0, y = 0;

		bool rev = false;
		if(uh.size() > uv.size()) {
			swap(uh, uv);
			swap(dh, dv);
			rev = true;
		}

		// for(int i : uh) printf("%d ", i); puts("");
		// for(int i : uv) printf("%d ", i); puts("");
		// for(int i : dh) printf("%d ", i); puts("");
		// for(int i : dv) printf("%d ", i); puts("");

		if(true) {
			reverse(uh.begin(), uh.end());

			for(int i : uh) th.push_back(i);
			for(int i : uv) {
				tv.push_back(i);
				if(tv.size() > th.size()) {
					th.push_back(dh.back());
					dh.pop_back();
				}
			}

			reverse(dv.begin(), dv.end());
			for(int i : dv) tv.push_back(i);
			for(int i : dh) th.push_back(i);
		}

		for(int i = 0; i < th.size(); i++) {
			printf("%d %d\n", x, y);
			if(rev) y += th[i];
			else x += th[i];
			printf("%d %d\n", x, y);
			if(rev) x += tv[i];
			else y += tv[i];
		}
	}
	return 0;
}