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

const int N=2e5+5;

int a[N];

void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	int cntn=0,cntp=0,cntz=0;
	rep(i,0,n){
		cin>>a[i];
		if(a[i]==0)cntz++;
		else if(a[i]>0)cntp++;
		else cntn++;
	}
	
	if(cntz){
		if(k<cntz){
			rep(i,0,n){
				cout<<a[i]<<" ";
			}
			return;
		}
		if(cntn%2==0){
			cntn++;
			cntz--;
			k--;
			rep(i,0,n){
				if(a[i]==0){
					a[i]-=x;
					break;
				}
			}
		}
		rep(i,0,n){
			if(a[i]==0){
				a[i]+=x;
				cntz--;
				cntp++;
				k--;
			}
		}
	}
	
	if(cntn%2==0){
		int mn=0;
		rep(i,0,n){
			if(abs(a[mn])>abs(a[i]))mn=i;
		}
		if(abs(a[mn])-k*x >= 0){
			if(a[mn] > 0)a[mn]-=k*x;
			else a[mn]+=k*x;
			rep(i,0,n){
				cout<<a[i]<<" ";
			}
			return;
		}
		int t=abs(a[mn])/x + 1;
		k-=t;
		if(a[mn] > 0) a[mn]-=t*x;
		else a[mn]+=t*x;
	}
	
	set<pii> s;
	rep(i,0,n){
		s.insert({abs(a[i]),i});
	}
	
	rep(i,0,k){
		pii z=*s.begin();
		s.erase(s.begin());
		if(a[z.sc] > 0)a[z.sc]+=x;
		else a[z.sc]-=x;
		s.insert({abs(a[z.sc]),z.sc});
	}
	
	rep(i,0,n){
		cout<<a[i]<<" ";
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