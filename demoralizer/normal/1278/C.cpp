#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

int n;
int a[200005];
int b[200005];
int c[200005];
map<int, int> d,e;

void solve(){
	cin>>n;
	int s1=0,s2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s1+=(a[i]==1)?1:-1;
	}
	rep(i,0,n){
		b[i]=a[n-1-i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		s2+=(c[i]==1)?1:-1;
	}
	int t1=0,t2=0;
	rep(i,0,n){
		int k1=s1-t1;
		int k2=s2-t2;
		if(!d.count(k1))d[k1]=i;
		if(!e.count(k2))e[k2]=i;
		t1+=(b[i]==1)?1:-1;
		t2+=(c[i]==1)?1:-1;
	}
	if(!d.count(0))d[0]=n;
	if(!e.count(0))e[0]=n;
	int ans=2*n;
	for(pii x:d){
		int a=x.sc;
		int b=4*n;
		if(e.count(-x.fr)){
			b=e[-x.fr];
		}
		ans=min(ans,a+b);
	}
	cout<<ans<<"\n";
	d.clear();
	e.clear();
}
signed main(){
	ios_base::sync_with_stdio(false);
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
	cin>>t;
	while(t--) solve();
	return 0;
}