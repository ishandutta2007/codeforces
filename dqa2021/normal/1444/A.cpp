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

int stk[100000],top;
void init(){
	
}
void solve(){
	ll x=read(),y=read();
	if (x%y) printf("%I64d\n",x);
	else{
		ll ans=0;
		int t=y; top=0;
		for (int i=2;i*i<=t;i++){
			if (t%i==0){
				stk[++top]=i;
				while (t%i==0) t/=i;
			}
		}
		if (t^1) stk[++top]=t;
		for (int i=1;i<=top;i++){
			int v=stk[i]; ll a=0,b=0,U=1,V=1;
			for (ll z=x;z%v==0;z/=v,a++,U*=v);
			for (ll z=y;z%v==0;z/=v,b++,V*=v);
			ans=max(ans,x/U*V/v);
		}
		printf("%I64d\n",ans);
	}
}
int main()
{
	for (int T=read();T--;) init(),solve();
}