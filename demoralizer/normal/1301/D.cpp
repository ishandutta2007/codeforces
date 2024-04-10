#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=0;



void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int t=4*n*m-2*n-2*m;
	if(k>t){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	int i=0;
	vector<pair<int, char>> v;
	while(k>0){
		if(k<m){
			v.pb({k,'R'});
			// cout<<k<<" R";
			k=-5;break;
		}
	if(m>1)
		v.pb({m-1,'R'});
		// cout<<(m-1)<<" R\n";
		k-=m-1;
		if(i==n-1){
			break;
		}
		if(k<m){
			v.pb({k,'L'});
			// cout<<k<<" L";
			k=-5;break;
		}
	if(m>1)
		v.pb({m-1,'L'});
		// cout<<(m-1)<<" L\n";
		k-=m-1;
		i++;
		v.pb({1,'D'});
		// cout<<"1 D\n";
		k--;
	}
	int j=m-1;
	while(k>0){
		if(k<n){
			v.pb({k,'U'});
			// cout<<k<<" U";
			k=-5;break;
		}
	if(n>1)
		v.pb({n-1,'U'});
		// cout<<(n-1)<<" U\n";
		k-=n-1;
		if(k<n){
			v.pb({k,'D'});
			// cout<<k<<" D";
			k=-5;break;
		}
	if(n>1)
		v.pb({n-1,'D'});
		// cout<<(n-1)<<" D\n";
		k-=n-1;
		j--;
		v.pb({1,'L'});
		// cout<<"1 L\n";
		k--;
	}
	cout<<sz(v)<<"\n";
	for(auto c:v)cout<<c<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}