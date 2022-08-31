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

int pw(int a,int b,int p){
	if(b==0)return 1;
	int t=pw(a,b/2,p);
	if(b%2)return (((a*t)%p)*t)%p;
	else return ((t*t)%p);
}

int z[2005];
int a[2005];
int ans[2005];
void solve(){
	z[0]=1;
	int n,k;
	cin>>n>>k;
	int x=1;
	rep(i,0,2002){
		z[i]=x;
		x=x*(k+i)%M * pw(i+1,M-2,M)%M;
	}
	rep(i,0,n){
		cin>>a[i];
	}
	rep(i,0,n){
		rep(j,0,n-i){
			ans[j+i]=(ans[j+i] + z[j]*a[i]%M)%M;
		}
	}
	rep(i,0,n){
		cout<<ans[i]<<" ";
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}