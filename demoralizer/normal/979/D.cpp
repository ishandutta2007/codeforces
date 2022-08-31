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

const int N=1e5+5;

set<int> s[N];

void solve(){
	int q;
	cin>>q;
	rep(xyz,0,q){
		int t;
		cin>>t;
		if(t==1){
			int u;
			cin>>u;
			for(int i=1;i*i<=u;i++){
				if(u%i==0){
					s[i].insert(u);
					s[u/i].insert(u);
				}
			}
		}
		else{
			int x,k,ss;
			cin>>x>>k>>ss;
			int e=1;
			while(2*e<=x){
				e<<=1;
			}
			if(x%k || s[k].empty()){
				cout<<"-1\n";
				continue;
			}
			int u=ss-x;
			auto it=s[k].upper_bound(u),lo=s[k].begin();
			if(it==s[k].begin()){
				cout<<"-1\n";
				continue;
			}
			it--;
			for(int i=17;i>=0;i--){
				int p=*it,q=*lo;
				if(((x&(1<<i))==0) && (p&(1<<i))){
					p=(p>>i)<<i;
					lo=s[k].lower_bound(p);
					continue;
				}
				if((x&(1<<i)) && (p&(1<<i))){
					if((q&(1<<i))==0){
						q=((q>>i)+1)<<i;
						it=s[k].lower_bound(q);
						it--;
					}
				}
			}
			cout<<*it<<"\n";
		}
	}
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}