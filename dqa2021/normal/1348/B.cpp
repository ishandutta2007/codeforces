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

int k,n,a[110],b[110];
bool mrk[110];
void init(){}
void solve(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1); int m=unique(b+1,b+n+1)-b-1;
	if (m>k) return puts("-1"),void();
	for (int i=1;i<=n;i++) mrk[i]=0;
	for (int i=1;i<=m;i++) mrk[b[i]]=1;
	while (m<k){
		for (int i=1;i<=n;i++) if (!mrk[i]){
			mrk[i]=1; b[++m]=i; break;
		}
	}
	printf("%d\n",n*k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			printf("%d ",b[j]);
	puts("");
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}