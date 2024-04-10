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
int a[N],fa[N];
vector<int> v;
int ff(int x){
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
void mer(int x,int y) {
	fa[ff(x)]=ff(y);
}
void Clear(){
	v.clear();
}
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n*2;i++) {
		fa[i]=i;
	}
	string s;
	cin >> s;
	s=' '+s;
	for(int i=1;i<=n*2;i++) {
		if(s[i]=='(') v.push_back(i);
		else {
			int x=v.back();
			mer(x,i);
			if(i!=n*2&&s[i+1]=='(') mer(i+1,x);
			v.pop_back();
		}
	}
	int ans=0;
	for(int i=1;i<=n*2;i++) ans+=fa[i]==i;
	cout << ans << "\n";
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