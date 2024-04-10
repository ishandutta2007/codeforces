#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define MOD 1000000007
int dp[MAXN][MAXN] = {{0}};
int dpmin[MAXN][MAXN] = {{0}};
int pow2[MAXN] = {0};
string x;
int n;

template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vector<int>> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vector<int>(v.size())}; iota(jmp[0].begin(), jmp[0].end(),0);
		for (int j = 1; 1<<j <= v.size(); ++j) {
			jmp.push_back(vector<int>(v.size()-(1<<j)+1));
			for(int i = 0; i<jmp[j].size(); i++) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

struct SuffixArray {
	string S; int N; vector<int> sa, isa, lcp;
	void init(string _S) { N = (S = _S).size()+1; genSa(); genLcp(); }
	void genSa() {
		sa = isa = vector<int>(N); sa[0] = N-1; iota(1+sa.begin(), sa.end(), 0);
		sort(1+sa.begin(), sa.end(),[&](int a, int b) { return S[a] < S[b]; });
		for(int i = 1;i< N; i++) { int a = sa[i-1], b = sa[i];
			isa[b] = i > 1 && S[a] == S[b] ? isa[a] : i; }
		for (int len = 1; len < N; len *= 2) { // currently sorted by first len chars
			vector<int> s(sa), is(isa), pos(N); iota(pos.begin(), pos.end(),0); 
			for(auto t:s) { int T = t-len; if (T >= 0) sa[pos[isa[T]]++] = T; }
			for(int i=1; i<N; i++) { int a = sa[i-1], b = sa[i];
				isa[b] = is[a] == is[b] && is[a+len] == is[b+len] ? isa[a] : i; }
		}
	}
	void genLcp() { // Kasai's Algo
		lcp = vector<int>(N-1); int h = 0;
		for(int b = 0; b<N-1; b++) { int a = sa[isa[b]-1];
			while (a+h < S.size() && S[a+h] == S[b+h]) h ++;
			lcp[isa[b]-1] = h; if (h) h--; }
		R.init(lcp); /// if we cut off first chars of two strings
		/// with lcp h then remaining portions still have lcp h-1 
	}
	RMQ<int> R; 
	int getLCP(int a, int b) { // lcp of suffixes starting at a,b
		if (a == b) return S.size()-a;
		int l = isa[a], r = isa[b]; if (l > r) swap(l,r);
		return R.query(l,r-1);
	}
    bool comp(int a, int b, int c, int d){ // return 1 if s[a...b]>=s[c...d]
        int len = getLCP(a, c);
        if(len >= b-a+1) return 1;
        return S[a+len] > S[c+len];
    }
};

int add(int &a, int &b){
    a += b;
    if(a>=MOD) a-=MOD;
    return a;
}

SuffixArray sa;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x;
    pow2[0] = 1;
    for(int i = 1; i<MAXN; i++) pow2[i] = 2ll*pow2[i-1]%MOD;
    n = x.size();
    memset(dpmin, 0x3f, sizeof dpmin);
    sa.init(x);
    for(int i = 0; i<n; i++) dp[i][0] = 1, dpmin[i][0] = 1;
    for(int i = 0; i<n && x[i] == '1'; i++) dp[i][i] = 1, dpmin[i][i] = i+1;
    for(int i = 2; i<n; i++){
        for(int j = 1; j<i; j++){
            if(x[j] == '0') continue;
            add(dp[i][j], dp[i-1][j]);
            dpmin[i][j] = min(dpmin[i][j], dpmin[i-1][j]);
            if(j >= i-j+1 && x[2*j-i-1] == '1' && sa.comp(j, i, 2*j-i-1, j-1)){
                add(dp[i][j], dp[j-1][2*j-i-1]);
                dpmin[i][j] = min(dpmin[i][j], 1+dpmin[j-1][2*j-i-1]);
            }
            if(j >= i-j && x[2*j-i] == '1' && !sa.comp(j, i-1, 2*j-i, j-1)){
                add(dp[i][j], dp[j-1][2*j-i]);
                dpmin[i][j] = min(dpmin[i][j], 1+dpmin[j-1][2*j-i]);
            }
        }
    }
    // cout << dp[13][8] << endl;
    int ans = 0;
    for(int i = 0; i<n; i++) add(ans, dp[n-1][i]);
    cout << ans << endl;
    int minans = 13200;
    int cur = 0;
    for(int i = n-1; i>=0 && n-1-i+1 <= 13; i--){
        if(x[i] == '1') add(cur, pow2[n-1-i]);
        else continue;
        minans = min(minans, cur+dpmin[n-1][i]);
    }
    if(minans != 13200){
        cout << minans << endl;
    }
    else{
        cur = 0;
        for(int i = n-1; i>=0; i--){
            if(x[i] == '1') add(cur, pow2[n-1-i]);
            else continue;
            if(dpmin[n-1][i]<MAXN){
                cout << add(cur, dpmin[n-1][i]) << endl;
                exit(0);
            }
        }
    }
}