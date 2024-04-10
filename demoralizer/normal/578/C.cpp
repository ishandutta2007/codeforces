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

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

const int N=2e5+5;
int a[N];
double b[N];
int n;

double calc(double x){
	rep(i,0,n)b[i+1]=a[i]-x;
	double s=0,ans=0;
	b[0]=0;
	rep(i,1,n+1){
		b[i]+=b[i-1];
	}
	double l=0,u=0;
	rep(i,1,n+1){
		ans=max(ans,abs(b[i]-l));
		ans=max(ans,abs(b[i]-u));
		l=min(l,b[i]);
		u=max(u,b[i]);
	}
	return ans;
}

void solve(){
	cin>>n;
	rep(i,0,n)cin>>a[i];
	double L=-10002,U=10002;
	rep(i,0,90){
		double d=(U-L)/3;
		if(calc(L+d)>calc(L+2*d)){
			L=L+d;
		}
		else{
			U=U-d;
		}
	}
	cout<<calc(L);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout<<setprecision(9);
	cout<<fixed;
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