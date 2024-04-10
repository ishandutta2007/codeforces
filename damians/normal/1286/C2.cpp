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
int cnt[3][256][111];
int A[3];
int B[3];


void query(int a,int b,int ind)
{
	
	cout<<"? "<<a<<" "<<b<<endl;
	int k=b-a+1;
	FOR(j,k*(k+1)/2){
		string g;cin>>g;
		FOR(i,SZ(g)) cnt[ind][g[i]][SZ(g)]++;
	}
}


int getdiff(int ind,int d,char c){
	return cnt[ind][c][d+1]-cnt[ind][c][d];
}
	

vector<char> findcand(int ind,int p){
	vector<char> r;	
	REP(c,'a','z'){
		FOR(sdfsdg,getdiff(ind,p-1,c)-getdiff(ind,p,c)) r.pb(c);
	}
	return r;
}

	
int main()
{
	ios_base::sync_with_stdio(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	string s(n,'?');
	if (n==1){
		cout<<"? 1 1"<<endl;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	s="?"+s;
	if (n<0){
		int k=(int)(1/sqrt(2)*n)+1;
		if (k%2==0)k--;
		A[0]=1;B[0]=k;
		A[1]=n-k+1;B[1]=n;
		A[2]=(n-k)/2;B[2]=(n-k)/2+k;
	}
	else{
		A[0]=1;B[0]=n/2;
		A[1]=1;B[1]=n/2+1;
		A[2]=1;B[2]=n;
	}
	FOR(j,3) debug()<<imie(mp(A[j],B[j]));
	FOR(j,3)query(A[j],B[j],j);
	
	//REP(c,'a','z') if (getdiff(k-1,c)) s[k]=c;
	while(count(ALL(s),'?')>1){
		debug()<<imie(s);
		FOR(q,3){
			int a=A[q];
			int b=B[q];
			for(int i=1;a+i-1<=b-i+1;i++){
				debug()<<pii({a+i-1,b-i+1});
				if (a+i-1==b-i+1 && s[a+i-1]=='?'){
					auto v=findcand(q,i);
					s[a+i-1]=v[0];
				}
				if (((s[a+i-1]=='?') + (s[b-i+1]=='?'))==1){
					
					auto v=findcand(q,i);
					debug()<<imie(v);
					if (s[a+i-1]=='?'){
						if (v[1]!=s[b-i+1]) swap(v[0],v[1]);
					}
					else{
						if (v[0]!=s[a+i-1]) swap(v[0],v[1]);
					}
					s[a+i-1]=v[0];
					s[b-i+1]=v[1];
				}
			}
		}
	}
	cout<<"! "<<s.substr(1)<<endl;
	
	
	


    return 0;
}