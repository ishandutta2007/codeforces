#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//suffix array with lcp query
struct suff_arr {
	int n;
	vector<int> A,I;
	
	suff_arr(const string& s):n(s.size()),A(s.size()+1) {
		for(int i = 0; i < n; ++i) A[i] = s[i]+1;
		vector<int> T(n),L(n),F(n+1);
		I = A;
		for(int i = 0; i < n; ++i) L[i] = i;
		A[n] = I[n] = 0;
		sort(L.begin(),L.end(),[this](int i, int j) {return (A[i]!=A[j])?A[i]<A[j]:A[min(i+1,n)]<A[min(j+1,n)];});
		for(int g = 1;;) {
			for(int i = 0; i < n; ++i)
				I[L[i]] = (i && A[L[i]]==A[L[i-1]] && A[min(L[i]+g,n)]==A[min(L[i-1]+g,n)]) ? I[L[i-1]] : i+1;
			if((g <<= 1) < n) {
				fill(F.begin(),F.end(),0);
				F[0] = g;
				for(int i = n-1; i >= g; --i) ++F[I[min(i,n)]];
				for(int i = 1; i <= n; ++i) F[i] += F[i-1];
				for(int i = 0; i < n; ++i) T[--F[I[min(i+g,n)]]] = i;
				fill(F.begin(),F.end(),0);
				for(int i = 0; i < n; ++i) ++F[I[i]];
				for(int i = 1; i <= n; ++i) F[i] += F[i-1];
				for(int i = n-1; i >= 0; --i) L[--F[I[T[i]]]] = T[i];
				swap(A,I);
			} else break;
		}
		A.pop_back(), I.pop_back();
		for(int i = 0; i < n; ++i)
			A[--I[i]] = i;
	}

	//lcp stuff : can be removed if not needed
	vector<vector<int> > rmq;
	inline int lg(int a){return 31-__builtin_clz(a);}
	void kasai(const string& s) {
		rmq = vector<vector<int> >(lg(n)+1,vector<int>(n));
		int k = 0,j;
		for(int i = 0; i < n; ++i) {
			if(I[i]==n-1) {
				k = 0;
				continue;
			}
			for(j = A[I[i]+1];i+k<n && j+k<n && s[i+k] == s[j+k]; ++k);
			rmq[0][I[i]] = k;
			if(k) --k;
		}
		for(k = 0, j = 1; k+1 < rmq.size(); j<<=1,++k)
			for(int i = 0; i < n; ++i)
				rmq[k+1][i] = (i+j<n)?min(rmq[k][i],rmq[k][i+j]):rmq[k][i];
	}

	int lcp(int i, int j) {
		if(i == j) return n-i;
		i=I[i],j=I[j];
		if(j<i) swap(i,j);	
		int l = lg(j-i);
		return min(rmq[l][i],rmq[l][j-(1<<l)]);
	}
};

const int N = 1e5+5;
int dp[N][33];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,x;
	string s,t;
	cin >> n >> s >> m >> t >> x;
	suff_arr S(s + "$" + t);
	S.kasai(s+"$"+t);
	for(int i = 0; i <= n; ++i) {
		for(int r = 0; r <= x; ++r) {
			if(dp[i][r] == m) {
				cout << "YES\n";
				return 0;
			}
			dp[i+1][r] = max(dp[i+1][r],dp[i][r]);
			if(dp[i][r] == m || i == n || s[i] != t[dp[i][r]]) continue;
			int lcp = S.lcp(i,n+1+dp[i][r]);
			// int lcp = 0;
			dp[i+lcp][r+1] = max(dp[i+lcp][r+1],dp[i][r]+lcp);
		}
	}
	cout << "NO\n";
}