#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vector<char> A[4];
vector<string> S = {"abbb","abaa","aaba","aaab","aabb","abab","abba"};

typedef vector<vector<double> > matrix;
matrix M(6,vector<double>(7)), W;
constexpr double EPS = 1e-10;

ll rref(matrix &M) {
	int n = M.size(), m = M[0].size(), r = 0;
	double det = 1;
	for(; r < min(n,m); ++r) {
		int i = r;
		for(; i < n && abs(M[i][r]) < EPS; ++i);
		if(i == n) break;
		if(i != r) swap(M[i],M[r]), det = -det;
		double v = 1.0/M[r][r];
		det = det * M[r][r];
		M[r][r] = 1;
		for(int j = r+1; j < m; ++j)
			M[r][j] = M[r][j] * v;
		for(i = 0; i < n; ++i) {
			if(i == r) continue;
			for(int j = m-1; j >= r; --j)
				M[i][j] = M[i][j] - M[i][r] * M[r][j];
		}
	}
	return det * (n == m && n == r);
}

int g[6];

inline int get_int(const double a) {
	if(abs(a - round(a)) > EPS) return -1;
	return rint(a);
}

inline void add(int i) {
	for(int j = 0; j < 4; ++j)
		A[j].pb(S[i][j]);
}

int best = 1<<20;
vi bv;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int mn = 1<<20;
	for(int i = 0; i < 6; ++i)
		scanf("%d",g+i), mn = min(mn,g[i]);
	int r = 0;
	for(int i = 0; i < 4; ++i)
		for(int j = i+1; j < 4; ++j,++r)
			for(int c = 0; c < 7; ++c)
				M[r][c] = S[c][i] != S[c][j];
	for(int c = 0; c <= 100000; ++c) {
		W = M;
		bool ok = true;
		for(int r = 0; ok && r < 6; ++r) {
			W[r][6] = g[r] - c * W[r][6];
			if(W[r][6] < 0) ok = false;
		}
		if(!ok) break;
		rref(W);
		for(int r = 0; ok && r < 6; ++r) {
			if(get_int(W[r][6]) < 0) {
				ok = false;
			}
		}
		if(!ok) continue;
		vector<int> tmp(7);
		int sm = c;
		tmp[6] = c;
		for(int r = 0; r < 6; ++r)
			tmp[r] = rint(W[r][6]), sm += tmp[r];
		if(sm < best) {
			best = sm;
			bv = tmp;
		}
	}
	if(best != (1<<20)) {
		printf("%d\n",best);
		for(int i = 0; i < 7; ++i) {
			while(bv[i]--) add(i);
		}
		for(int i = 0; i < 4; ++i) {
			for(char c : A[i])
				printf("%c",c);
			printf("\n");
		}
	} else printf("-1\n");
}