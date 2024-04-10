#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
typedef long long ll;
inline ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
void print(ll x){
	if (x>9) print(x/10); putchar((x%10)^48);
}
#undef G

int n; ll w[1000010],S;
int main()
{
	n=read();
	for (int i=1;i<=n;i++) w[i]=read(),S+=w[i];
	S-=1LL*n*(n-1)/2; ll t=(S+n-1)/n,r=t*n-S;
	for (int i=1;i<=n;i++){
		ll ans=i-1+t; if (i>=n-r+1) ans--;
		print(ans),putchar(' ');
	}
	puts("");
	return 0;
}