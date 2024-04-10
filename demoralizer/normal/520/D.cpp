#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000009
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

map<int, int> ids[N];
pii x[N];
int supports[N];
set<int> rem;
vector<int> ans;

bool check(int id){
	int f=1;
	int a=x[id].fr,b=x[id].sc;
	rep(i,-1,2){
		if(ids[b+1].count(a+i)){
			if(supports[ids[b+1][a+i]]==1)f=0;
		}
	}
	return f;
}

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>x[i];
		ids[x[i].sc][x[i].fr]=i;
	}
	rep(i,0,n){
		int a=x[i].fr,b=x[i].sc;
		rep(i,-1,2){
			if(ids[b+1].count(a+i)){
				supports[ids[b+1][a+i]]++;
			}
		}
	}
	rep(i,0,n){
		if(check(i))rem.insert(i);
	}
	rep(i,0,n){
		int rid;
		if(i%2==0){
			rid=*rem.rbegin();
		}
		else{
			rid=*rem.begin();
		}
		ans.pb(rid);
		rem.erase(rid);
		int a=x[rid].fr,b=x[rid].sc;
		ids[b].erase(a);
		rep(i,-1,2){
			if(ids[b+1].count(a+i)){
				supports[ids[b+1][a+i]]--;
			}
		}
		if(b)
		rep(i,-1,2){
			if(ids[b-1].count(a+i)){
				int k=ids[b-1][a+i];
				if(check(k))rem.insert(k);
			}
		}
		rep(i,-2,3){
			if(i==0)continue;
			if(ids[b].count(a+i)){
				int k=ids[b][a+i];
				if(!check(k))rem.erase(k);
			}
		}
	}
	reverse(all(ans));
	int m=1;
	int rr=0;
	for(int x:ans){
		rr+=x*m%M;
		rr%=M;
		m*=n;
		m%=M;
	}
	cout<<rr;
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