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

int n,a[1010];
bool check(){
	for (int i=1;i<=n;i++) if (a[i]!=i-1) return 1;
	return 0;
}
int getmex(){
	static int mrk[1012],tim; tim++;
	for (int i=1;i<=n;i++) mrk[a[i]]=tim;
	int res=0; while (mrk[res]==tim) res++;
	return res;
}
int ans[2010],top;
void init(){
	top=0;
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	while (check()){
		int t=getmex();
		if (t==n){
			for(int i=1;i<=n;i++) if (a[i]!=i-1){
				a[i]=t; ans[++top]=i;break;
			}
			continue;
		}
		a[t+1]=t; ans[++top]=t+1;
	}
	printf("%d\n",top);
	for (int i=1;i<=top;i++) printf("%d ",ans[i]); puts("");
}
int main()
{
	for (int T=read();T--;) init(),solve();
}