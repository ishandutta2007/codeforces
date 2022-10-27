#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
using namespace std;
const int N=1e6,inf=1e18,mod=1000000007;
int a[N];
void Clear(){
	
}
void solve(){
	int n,m;
	cin >> n >> m;
	if(m<n) {
		cout << "No\n";
		return ;
	}
	if(n%2) {
		cout << "Yes\n";
		for(int i=1;i<n;i++) {
			cout << "1 ";
		}
		cout << m-(n-1) << "\n";
		return ;
	}
	if(m%2) {
		cout << "No\n";
		return ;
	}
	cout << "Yes\n";
	for(int i=1;i<n-1;i++) {
		cout << "1 ";
	}
	cout << (m-(n-2))/2 << " ";
	cout << (m-(n-2))/2 << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin >> T;
	while(T--){
		solve();
		Clear();
	}
	return 0;
}