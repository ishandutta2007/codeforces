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


array<vi, 2> manacher(const string& s) {
int n = SZ(s);
array<vi,2> p = {vi(n+1), vi(n)};
REP(z,0,1) for (int i=0,l=0,r=0; i < n; i++) {
int t = r-i+!z;
if (i<r) p[z][i] = min(t, p[z][l+t]);
int L = i-p[z][i], R = i+p[z][i]-!z;
while (L>=1 && R+1<n && s[L-1] == s[R+1])
p[z][i]++, L--, R++;
if (R>r) l=L, r=R;
}
return p;
}



string go(string s) {
	int n=SZ(s);
	int le=0;
	FOR(i,n) {
		if (s[i]==s[n-1-i]) {
			le++;
		}else break;
	}
	if (le==n) return s;
	auto A=manacher(s);
	//debug()<<imie(n)<<imie(SZ(A[0]))<<imie(SZ(A[1]));
	int best_len=0;
	pii be={0,0};
	REPD(i,n/2,0) {
		if (i-A[0][i]<=le) {
			int nle=2*A[0][i]+2*(i-A[0][i]);
			if (nle>best_len) {
				best_len=nle;
				be={i+A[0][i], i-A[0][i]};
			}
		}
	}
	
	REPD(i,n/2,0) {
		if (2*i+1>n) continue;
		if (i-A[1][i]<=le) {
			int nle=1+2*A[1][i]+2*(i-A[1][i]);
			if (nle>best_len) {
				best_len=nle;
				be={i+A[1][i]+1, i-A[1][i]};
			}
		}
	}
	string res="";
	FOR(i,be.st) res+=s[i];
	FOR(i,be.nd) res+=s[n-be.nd+i];
			
	return res;
}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int t;cin>>t;
	FOR(dsgsg,t) {
		string s;cin>>s;
		string r=go(s);
		reverse(ALL(s));
		string r2=go(s);
		reverse(ALL(r2));
		if (SZ(r)<SZ(r2)) swap(r,r2);
		cout<<r<<"\n";
	}


    return 0;
}