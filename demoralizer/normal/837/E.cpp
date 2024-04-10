#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

vector<int> f;

// void dvd(int x){
// 	if(x==0)return;
// 	int a=x;
// 	for(auto it=f.begin();it!=f.end();){
// 		if(a%it->fr==0){
// 			while(a%it->fr==0){
// 				it->sc--;
// 			}
// 		}
// 		if(it->sc == 0){
// 			f.erase(it++);
// 		}
// 		else{
// 			it++;
// 		}
// 	}
// }

int F(int a,int b){
	if(b==0)return 0;
	int g = __gcd(a,b);
	int v = 0,n=1;
	for(auto z:f){
		int vd = b/(z*g)*(z*g);
		if(vd > v && __gcd(vd,a) > g){
			n=z;
			v = vd;
		}
	}
	int nb = v;
	int ans = (b-nb)/g;
	int ng = __gcd(a,nb);
	// dvd(ng/g);
	return ans + F(a,nb);
	// return 0;
}

void solve(){
	int x,y;
	cin>>x>>y;
	int a=x;
	for(int i=2;i*i<=a;i++){
		if(a%i == 0){
			while(a%i==0){
				a/=i;
			}
			f.pb(i);
		}
	}
	if(a!=1)f.pb(a);
	cout<<F(x,y);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}