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
#define REMIN(a,b) a=min(a,b)
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int p[111];
int av[111];

int allzeros(int a,int b)
{
	REP(j,a,b) if (p[j]) return 0;
	return 1;
}

int dp[111][111][111][2];
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	REP(i,1,n)cin>>p[i];
	REP(i,1,n) av[p[i]]=1;
	vi cnt={0,0};
	REP(i,1,n) if (!av[i]) cnt[i%2]++;
	if (cnt[0]+cnt[1]==n){
		if (n==1) cout<<0<<"\n";
		else cout<<1<<"\n";
		return 0;
	}
	debug()<<cnt;
	REP(i,0,n)REP(c0,0,n)REP(c1,0,n)FOR(b,2)dp[i][c0][c1][b]=200;
	REP(c0,0,n)REP(c1,0,n)FOR(b,2)dp[0][0][0][b]=0;
	REP(i,1,n)REP(c0,0,cnt[0])REP(c1,0,cnt[1])FOR(b,2)FOR(c,2){
		if (p[i]!=0 && c==p[i]%2) dp[i][c0][c1][c]=min(dp[i][c0][c1][c],dp[i-1][c0][c1][b]+abs(c-b));
		//if (i==5 && c0==1 && c1==1 && c==1 && b==0) debug()<<imie("dsg")<<imie(dp[i][c0][c1][c])<<dp[i-1][c0][c1][b]<<dp[4][1][1][0];
		if (p[i]==0){
			if (c==0 && c0) REMIN(dp[i][c0][c1][c],dp[i-1][c0-1][c1][b]+abs(c-b));
			if (c==1 && c1) REMIN(dp[i][c0][c1][c],dp[i-1][c0][c1-1][b]+abs(c-b));
		}
		//debug()<<imie(i)<<imie(c0)<<imie(c1)<<imie(c)<<imie(dp[i][c0][c1][c]);
	}
	cout<<min(dp[n][cnt[0]][cnt[1]][0],dp[n][cnt[0]][cnt[1]][1])<<"\n";
		
	


    return 0;
}