#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,a[100010];
int c[100010];
void init(){
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),c[i]=0;
	for (int i=1;i<=n;i++) c[a[i]]++;
	for (int i=1;i<=n;i++) if (c[i]>(n+1>>1)) return puts("-1"),void();
	for (int i=1;i<=n;i++) c[i]=0;
	int T=0;
	for (int i=1,j;i<=n;i=j+1){
		for (j=i;j<n&&a[j+1]!=a[j];j++);
		c[a[i]]++,c[a[j]]++;
		T++;
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,c[i]-T-1);
	ans+=T-1;
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}