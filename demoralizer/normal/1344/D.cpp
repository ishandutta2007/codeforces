#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

const long long INF=4e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

int a[N];
int b[N];

int get(int a,int incen){
	int L=0,U=a;
	int ans=a;
	while(L<=U){
		int m=(L+U)/2;
		if(3*m*m + 3*m + 1 - a - incen >= 0){
			ans=m;
			U=m-1;
		}
		else{
			L=m+1;
		}
	}
	return ans;
}

void solve(){
	int n,k;
	cin>>n>>k;
	rep(i,0,n){
		cin>>a[i];
	}
	
	int L=-INF,U=INF;
	int opt;
	while(L<=U){
		int incen=(L+U)/2;
		int cnt=0;
		rep(i,0,n){
			int x=a[i];
			cnt += get(x,incen);
		}
		if(cnt <= k){
			opt = incen;
			L=incen+1;
		}
		else{
			U=incen-1;
		}
	}
	
	int cnt=0;
	int mx = -INF;
	rep(i,0,n){
		b[i] = get(a[i],opt);
		cnt += b[i];
		if(b[i]<a[i])amax(mx,a[i] - 3*b[i]*b[i] - 3*b[i] - 1);
	}
	
	rep(i,0,n){
		if(b[i] < a[i] && cnt < k && a[i] - 3*b[i]*b[i] - 3*b[i] -1 == mx){
			b[i]++;
			cnt++;
		}
		cout<<b[i]<<" ";
	}
	
	// cout<<"\n\n\n"<<cnt;
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