#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, dp[N][N]; string s;
vector<int> lol[N];

template<class T> struct RMQ {
	int level(int x) { return 31-__builtin_clz(x); }
	vector<T> v; vector<vector<int>> jmp;
	int cmb(int a, int b) {
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); }
	void init(const vector<T>& _v) {
		v = _v; jmp = {vector<int>((int)v.size())};
		iota(jmp[0].begin(), jmp[0].end(), 0);
		for (int j = 1; 1<<j <= (int)v.size(); ++j) {
			jmp.push_back(vector<int>((int)v.size()-(1<<j)+1));
			for(int i = 0; i<(int)jmp[j].size(); ++i) jmp[j][i] = cmb(jmp[j-1][i],
				jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) {
		assert(l <= r); int d = level(r-l+1);
		return cmb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

struct SuffixArray {
	string S; int N; vector<int> sa, isa, lcp;
	void init(string _S) { N = (S = _S).size()+1; genSa(); genLcp(); }
	void genSa() { // sa has size sz(S)+1, starts with sz(S)
		sa = isa = vector<int>(N); sa[0] = N-1; iota(1+sa.begin(), sa.end(), 0);
		sort(1+sa.begin(), sa.end(), [&](int a, int b) { return S[a] < S[b]; });
		for(int i = 1; i<N; ++i) { int a = sa[i-1], b = sa[i];
			isa[b] = i > 1 && S[a] == S[b] ? isa[a] : i; }
		for (int len = 1; len < N; len *= 2) { // currently sorted
			// by first len chars
			vector<int> s(sa), is(isa), pos(N); iota(pos.begin(), pos.end(), 0); 
			for(auto t:s) {int T=t-len;if (T>=0) sa[pos[isa[T]]++] = T;}
			for(int i = 1; i<N; ++i) { int a = sa[i-1], b = sa[i]; /// verify that nothing goes out of bounds
				isa[b] = is[a]==is[b]&&is[a+len]==is[b+len]?isa[a]:i; }
		}
	}
	void genLcp() { // Kasai's Algo
		lcp = vector<int>(N-1); int h = 0;
		for(int b = 0; b<N-1; ++b) { int a = sa[isa[b]-1];
			while (a+h < (int)S.size() && S[a+h] == S[b+h]) ++h;
			lcp[isa[b]-1] = h; if (h) h--; }
		R.init(lcp); /// if we cut off first chars of two strings
		/// with lcp h then remaining portions still have lcp h-1 
	}
	RMQ<int> R; 
	int getLCP(int a, int b) { // lcp of suffixes starting at a,b
		if (a == b) return (int)s.size()-a;
		int l = isa[a], r = isa[b]; if (l > r) swap(l,r);
		return R.query(l,r-1);
	}
};

void solve(){
    cin >> n >> s;
	SuffixArray sa; sa.init(s);
	sa.genLcp(); sa.genLcp();
    int ans = 0;
    for(int i = 0; i<n; ++i){
        for(int j = i; j<n; ++j)
            lol[j].clear();
        for(int j = 0; j<i; ++j){
            int len = sa.getLCP(j, i);
            if(i+len<n && s[j+len]<s[i+len]) lol[i+len].push_back(j);
        }
        int cur = 0;
        for(int j = i; j<n; ++j){
            for(int x : lol[j])
                cur = max(cur, dp[x][n-1]);
            dp[i][j] = cur+1;
            if(j>i) dp[i][j] = max(dp[i][j], dp[i][j-1]+1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}