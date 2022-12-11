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

int n; ll W;
int w[200010],p[200010]; int m;
void init(){
//	...
}
void solve(){
	n=read(),W=read(); m=0;
	for (int i=1;i<=n;i++){
		ll x=read();
		if (x<=W) w[++m]=x,p[m]=i;
	}
	if (!m) return puts("-1"),void();
	ll S=0;
	for (int i=1;i<=m;i++){
		if (w[i]*2>=W){
			printf("1\n%d\n",p[i]);
			return;
		}
		S+=w[i];
		if (S*2>=W){
			printf("%d\n",i);
			for (int j=1;j<=i;j++) printf("%d ",p[j]);
			puts("");
			return;
		}
	}
	puts("-1");
}
int main()
{
	for (int T=read();T--;) init(),solve();
}