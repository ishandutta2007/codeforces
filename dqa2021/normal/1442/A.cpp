#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

int n,a[30010];
void init(){
	
}
bool solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	ll t=0;
	for (int i=n-1;i;i--){
		if (a[i]<t) return 0;
		a[i]-=t;
		if (a[i]<=a[i+1]) continue;
		int s=a[i]-a[i+1]; a[i]=a[i+1];
		t+=s;
	}
	return 1;
}
int main()
{
	for (int T=read();T--;) init(),puts(solve()?"yes":"no");
}