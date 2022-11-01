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
const int MOD=1e9+7;//998244353;
#define maxn 500000
vi isin[maxn];
int p[maxn];
int edge[maxn];
int sz[maxn][2];

int res=0;
#define INF (1<<20)

int fi(int x) {
	if (p[p[x]]!=p[x]) {
		fi(p[x]);
		edge[x]=edge[x]^edge[p[x]];
		p[x]=p[p[x]];
	}
	return p[x];
}

void add_constr(int x,int y,int b) {
	int px=fi(x);
	int py=fi(y);
	if (px==py) return;
	b^=edge[x]^edge[y];
	x=px;
	y=py;
	p[y]=x;
	edge[y]=b;
	res-=min(sz[x][0],sz[x][1]);
	res-=min(sz[y][0],sz[y][1]);
	FOR(j,2) {
		sz[x][j]=min(INF,sz[x][j]+sz[y][j^b]);
	}
	res+=min(sz[px][0],sz[px][1]);
}

void force(int x,int b) {
	int px=fi(x);
	b^=edge[x];
	x=px;
	res-=min(sz[x][0],sz[x][1]);
	sz[x][b^1]=INF;
	res+=min(sz[x][0],sz[x][1]);
}




	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n,k;cin>>n>>k;
	string s;cin>>s;
	FOR(i,k) {
		int d;cin>>d;
		FOR(j,d) {
			int x;cin>>x;
			x--;
			isin[x].pb(i);
		}
	}
	FOR(i,k) {
		p[i]=i;
		sz[i][1]=1;
	}
	FOR(i,n) {
		//debug()<<imie(isin[i]);
		if (SZ(isin[i])==1) {
			force(isin[i][0],1^(s[i]-'0'));
		}
		if (SZ(isin[i])==2) {
			add_constr(isin[i][0],isin[i][1],1^(s[i]-'0'));
		}
		cout<<res<<"\n";
	}
	


    return 0;
}