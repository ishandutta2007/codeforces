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

const int N=5e5+5;
int a[N];
int lm[N];
int rm[N];
int n;

set<int> rem;
set<pii> mn;
void solve(){
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,1,n+1){
		lm[i]=a[i-1];
		rm[i]=a[i+1];
		mn.insert({a[i],i});
		rem.insert(i);
	}
	rem.insert(0);
	rem.insert(n+1);
	int ans=0;
	rep(z,0,n-2){
		pii x=*mn.begin();
		mn.erase(x);
		rem.erase(x.sc);
		auto it=rem.lower_bound(x.sc);
		int r=*it;
		it--;
		int l=*it;
		rm[l]=a[r];
		lm[r]=a[l];
		if(l==0 || r==n+1){
			ans+=a[x.sc];
		}
		// cout<<x.sc<<" "<<l<<" "<<r<<"\n";
		ans+=min(lm[x.sc],rm[x.sc]);
	}
	cout<<ans;
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