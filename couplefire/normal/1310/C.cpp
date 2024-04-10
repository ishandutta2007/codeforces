#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005

template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vector<int>> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vector<int>(v.size())}; iota(jmp[0].begin(), jmp[0].end(),0);
		for (int j = 1; 1<<j <= v.size(); ++j) {
			jmp.push_back(vector<int>(v.size()-(1<<j)+1));
			for(int i = 0; i<jmp[j].size(); i++) jmp[j][i] = comb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
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
    bool comp(int a, int b, int c, int d){ // return 1 if s[a...b]<s[c...d]
        if(b-a+1 == 0 && d-c+1 == 0) return 0;
        if(b-a+1 == 0) return 1;
        if(d-c+1 == 0) return 0;
        int len = getLCP(a, c);
        if(len >= b-a+1 && len >= d-c+1) return (b-a)<(d-c);
        if(len >= b-a+1) return 1;
        if(len >= d-c+1) return 0;
        return S[a+len] < S[c+len];
    }
    bool isSame(int a, int b, int c, int d){
        return (b-a == d-c) && getLCP(a, c) >= (b-a+1);
    }
};

SuffixArray sa;
int n, m; long long k;
string s;
vector<pair<int, int>> ranges;
long long dp[1005][1005];
int l, r;
vector<int> badPos[1005];

bool check(int mid){
    l = ranges[mid].first, r = ranges[mid].second;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i<=n; i++) badPos[i].clear();
    for(int i = 1; i<=n; i++){
        int len = sa.getLCP(l, i);
        if(len >= r-l+1) badPos[i+r-l].push_back(i);
        else if(i+len <= n && s[i+len] > s[l+len]) badPos[i+len].push_back(i);
    }
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dp[i][j] = min(dp[i][j]+dp[i-1][j], k);
            for(auto x : badPos[i]) dp[i][j] = min(dp[i][j]+dp[x-1][j-1], k);
        }
    }
    return dp[n][m] >= k;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> s;
    s = '$'+s;
    sa.init(s);
    for(int i = 1; i<=n; i++) for(int j = i; j<=n; j++) ranges.push_back({i, j});
    sort(ranges.begin(), ranges.end(), [&](pair<int, int> a, pair<int, int> b){
        return sa.comp(a.first, a.second, b.first, b.second);
    });
    // for(auto x : ranges) cout << x.first << " " << x.second << endl;
    int lo = 0, hi = ranges.size()-1;
    while(lo<hi){
        int mid = lo+(hi-lo+1)/2;
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    // cout << check(4) << endl;
    cout << s.substr(ranges[lo].first, ranges[lo].second-ranges[lo].first+1) << endl;
}