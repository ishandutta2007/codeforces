#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long ll;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m;
ll a[200010],b[200010];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void init(){
	
}
void solve(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	//sort(a+1,a+n+1);
	for (int i=1;i<=m;i++) b[i]=read();
	for (int i=2;i<=n;i++) a[i]=abs(a[i]-a[1]);
	ll g=0;
	for (int i=2;i<=n;i++) g=gcd(g,a[i]);
	for (int i=1;i<=m;i++){
		ll ans=gcd(g,a[1]+b[i]);
		printf("%lld%c",ans," \n"[i==n]);
	}
}
int main()
{
	for (int T=1;T--;) init(),solve(); 
}