#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 2e5+3, A = 1e6+3, MOD = 1e9+7;
struct modint {
    int v;
    modint() {v=0;}
    modint (ll _v) {v = _v%MOD; if(v<0)v+=MOD;}
    modint (int _v) {v=_v; if(v<0)v+=MOD;}
    friend void scan (modint &a) {scanf("%d",&a.v);if(a.v>=MOD)a.v-=MOD;}
    friend void scanll(modint &a){ll r;scanf("%lld",&r);a.v=r%MOD;if(a.v<0)a.v+=MOD;}
    friend void print (const modint &a) {printf("%d",a.v);}
    friend void print (const modint &a, const char &c) {printf ("%d%c",a.v,c);}
    void operator= (const modint &m) {v = m.v;}
    void operator= (const int &_v) {*this = modint(_v);}
    void operator= (const ll &_v) {*this = modint(_v);}
    friend modint fpow (modint base, int ex) {modint res = 1;while (ex){if (ex&1) res*=base;base*=base;ex>>=1;}return res;}
    friend modint fpow (modint base, ll ex) {modint res = 1;while (ex){if (ex&1) res*=base;base*=base;ex>>=1;}return res;}
    friend modint inv (modint a) {return fpow(a,MOD-2);}
    friend modint inv (int a) {return fpow(modint(a),MOD-2);}
    modint operator+= (const int &_v) {v+=_v;if(v>=MOD)v-=MOD;return *this;}
    modint operator-= (const int &_v) {v-=_v;if(v<0)v+=MOD;return *this;}
    modint operator*= (const int &_v) {v=(ll)v*_v%MOD;if(v<0)v+=MOD;return *this;}
    modint operator/= (const int &_v) {return (*this)*=inv(modint(_v));}
    modint operator+= (const modint &m) {return (*this)+=m.v;}
    modint operator-= (const modint &m) {return (*this)-=m.v;}
    modint operator*= (const modint &m) {return (*this)*=m.v;}
    modint operator/= (const modint &m) {return (*this)*=inv(m);}
    modint operator++ () {return (*this)+=1;}
    modint operator-- () {return (*this)-=1;}
    modint operator++ (int) {(*this)+=1;return (*this)-1;}
    modint operator-- (int) {(*this)-=1;return (*this)+1;}
    friend modint operator+ (modint m, const modint &m2) {return m+=m2;}
    friend modint operator- (modint m, const modint &m2) {return m-=m2;}
    friend modint operator* (modint m, const modint &m2) {return m*=m2;}
    friend modint operator/ (modint m, const modint &m2) {return m/=m2;}
    bool operator< (const modint &m) {return v < m.v;}
    bool operator< (const int &_v) {return v < _v;}
    bool operator> (const modint &m) {return v > m.v;}
    bool operator> (const int &_v) {return v > _v;}
    bool operator<= (const modint &m) {return v <= m.v;}
    bool operator<= (const int &_v) {return v <= _v;}
    bool operator>= (const modint &m) {return v >= m.v;}
    bool operator>= (const int &_v) {return v >= _v;}
    bool operator== (const modint &m) {return v == m.v;}
    bool operator== (const int &_v) {return v == _v;}
    bool operator!= (const modint &m) {return v != m.v;}
    bool operator!= (const int &_v) {return v != _v;}
};
vector<int> adj[MN];
modint dp[MN];
modint up[MN];
vector<modint> pre[MN], suf[MN];
void dfs (int cur) {
    pre[cur].reserve(adj[cur].size()); suf[cur].resize(adj[cur].size());
	for (int i : adj[cur]) {
		dfs(i);
        pre[cur].push_back((pre[cur].empty()?1:pre[cur].back())*(dp[i]+1));
	}
    dp[cur] = pre[cur].empty()?1:pre[cur].back();
    for (int j = adj[cur].size()-1; j >= 0; j--) {
        int i = adj[cur][j];
        suf[cur][j] = (j+1==adj[cur].size()?1:suf[cur][j+1])*(dp[i]+1);
    }
}
void dfs2 (int cur, int p = -1) {
    for (int j = 0; j < adj[cur].size(); j++) {
        int i = adj[cur][j];
        up[i] = (up[cur]+1)*(j?pre[cur][j-1]:1)*(j+1==adj[cur].size()?1:suf[cur][j+1]);
        dfs2(i,cur);
    }
}
int main () {
   	int n;
	scanf ("%d",&n);
	for (int i = 2; i <= n; i++) {
		int a;
		scanf ("%d",&a);
		adj[a].push_back(i);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i <= n; i++) printf ("%d ",dp[i]*(up[i]+1));
	printf ("\n");
    return 0;
}