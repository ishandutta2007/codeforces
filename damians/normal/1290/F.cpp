//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define un(x) x.erase(unique(ALL(x)),x.end())
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=998244353;

struct mi {
	typedef decay<decltype(MOD)>::type T;
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(ll v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.val; }
   
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
 
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(!(a == 0)); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};


mi dp[13][13][13][13][2][2];
mi ndp[13][13][13][13][2][2];
int x[5];
int y[5];
int dpx[1<<5],dnx[1<<5],dpy[1<<5],dny[1<<5];

int bts[2][2][2][2];

bool mxx(int bitm,int bitx,int ok,int nok) {
	if (nok==0) return (bitx>bitm || (bitx==bitm && ok==0));
	return (bitx<bitm || (bitx==bitm && ok==1));
}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	FOR(bitm,2)FOR(bitx,2)FOR(ok,2)FOR(nok,2) bts[bitm][bitx][ok][nok]=mxx(bitm,bitx,ok,nok);
	int n;cin>>n;
	int m;cin>>m;
	FOR(i,n) cin>>x[i]>>y[i];
	int spx,snx,spy,sny;
	spx=0;FOR(i,n) if (x[i]>0) spx+=x[i]; if (spx==0) {cout<<0;return 0;}
	snx=0;FOR(i,n) if (x[i]<0) snx-=x[i]; if (snx==0) {cout<<0;return 0;}
	spy=0;FOR(i,n) if (y[i]>0) spy+=y[i]; if (spy==0) {cout<<0;return 0;}
	sny=0;FOR(i,n) if (y[i]<0) sny-=y[i]; if (sny==0) {cout<<0;return 0;}
	dp[0][0][0][0][1][1]=1;
	int ncpx,ncnx,ncpy,ncny;
	int bx,by;
	while(m){
		memset(ndp,0,sizeof(ndp));
		int bitm=m&1;
		m/=2;
		FOR(c,(1<<n)){
			dpx[c]=dnx[c]=dpy[c]=dny[c]=0;
			FOR(i,n) {
				if (x[i]>0 && (c>>i)&1) dpx[c]+=x[i];
				if (x[i]<0 && (c>>i)&1) dnx[c]-=x[i];
				if (y[i]>0 && (c>>i)&1) dpy[c]+=y[i];
				if (y[i]<0 && (c>>i)&1) dny[c]-=y[i];
			}
		}
		FOR(cpx,13)FOR(cnx,13)FOR(cpy,13)FOR(cny,13)FOR(xok,2)FOR(yok,2) {
			if (dp[cpx][cnx][cpy][cny][xok][yok]!=0) {
				mi val=dp[cpx][cnx][cpy][cny][xok][yok];
				FOR(c,(1<<n)) {
					ncpx=cpx+dpx[c];
					ncnx=cnx+dnx[c];
					ncpy=cpy+dpy[c];
					ncny=cny+dny[c];
					bx=ncpx&1;
					by=ncpy&1;
					if ((ncnx&1)==bx && (ncny&1)==by) {
						FOR(nxok,2) {
							if (bts[bitm][bx][xok][nxok]) {
								FOR(nyok,2) {
									if (bts[bitm][by][yok][nyok]) {
										ndp[ncpx/2][ncnx/2][ncpy/2][ncny/2][nxok][nyok]+=val;
									}
								}
							}
						}
					}
				}
			}
		}
		swap(dp,ndp);
	}
	cout<<dp[0][0][0][0][1][1]-1<<endl;
						
					


    return 0;
}