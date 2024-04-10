
// Problem : D. Xenia and Bit Operations
// Contest : Codeforces Round #197 (Div. 2)
// URL : https://codeforces.com/problemset/problem/339/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int aray[1<<17];

class SST {
public:
    int d, v;
    SST* ch[2];
    SST(int d, int loc) : d(d) {
		if(d) {
			ch[0] = new SST(d-1, loc);
			ch[1] = new SST(d-1, loc | (1<<(d-1)));
			if(d%2) v = ch[0]->v | ch[1]->v;
			else v = ch[0]->v ^ ch[1]->v;
		} else v = aray[loc];
    }
    ~SST() {
        if(ch[0]) delete ch[0];
        if(ch[1]) delete ch[1];
    }
    void inc(int i, int v0) {
        if(!d) {
			v = v0;
			return;
		}
        bool cv = i&(1<<(d-1));
        ch[cv]->inc(i, v0);
		if(d%2) v = ch[0]->v | ch[1]->v;
		else v = ch[0]->v ^ ch[1]->v;
    }
};


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	rep(i, 1<<n) cin >> aray[i];
	SST* s = new SST(17, 0);
	while(m--) {
		int i, v; cin >> i >> v;
		s->inc(i-1, v);
		cout << s->v << endl;
	}
}