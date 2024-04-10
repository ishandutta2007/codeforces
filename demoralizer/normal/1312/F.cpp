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

const int N=3e5+5;

int n,x,y,z,r,st;
int a[N];

int dp[10000][3];
int calc(int p,int l){
	if(p<=0)return 0;
	int &ans=dp[p][l];
	if(ans!=-1)return ans;
	set<int> s;
	s.insert(0);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.erase(calc(p-x,0));
	if(l!=1)s.erase(calc(p-y,1));
	if(l!=2)s.erase(calc(p-z,2));
	ans=*s.begin();
	return ans;
}

int get(int p,int l){
	if(p<st)return calc(p,l);
	return calc((p-st)%r+st,l);
}

void solve(){
	mem1(dp);
	cin>>n>>x>>y>>z;
	int k=0;
	map<int, int> rec;
	rep(i,0,10000){
		k=(k<<6)|((calc(i,0)<<4)|(calc(i,1)<<2)|calc(i,2));
		k=(((k>>30)<<30)^k);
		if(rec.count(k)){
			st=rec[k];
			r=i-rec[k];
			break;
		}
		rec[k]=i;
	}
	int v=0;
	rep(i,0,n){
		cin>>a[i];
		v^=get(a[i],0);
	}
	int cnt=0;
	rep(i,0,n){
		int u=get(a[i],0)^v;
		if(u==get(a[i]-x,0))cnt++;
		if(u==get(a[i]-y,1))cnt++;
		if(u==get(a[i]-z,2))cnt++;
	}
	cout<<cnt<<"\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}