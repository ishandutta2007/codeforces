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

int n,a[200010],p[200010];
struct C{
	int ch[2],f;
}c[200000*35+10];
int idtot=1;
int ins(int x){
	int o=1;
	for (int i=29;~i;i--){
		int t=x>>i&1;
		if (!c[o].ch[t]) c[o].ch[t]=++idtot,c[idtot].f=o;
		o=c[o].ch[t];
	}
	return o;
}
int checkleft(int x,int d){
	for (int i=0;i<d;i++) x=c[x].f;
	int res=0;
	while (x^1){
		if (x==c[c[x].f].ch[0]){
			x=c[x].f; continue;
		}
		x=c[x].f;
		if (c[x].ch[0]) res++;
	}
	return res;
}
int checkright(int x,int d){
	for (int i=0;i<d;i++) x=c[x].f;
	int res=0;
	while (x^1){
		if (x==c[c[x].f].ch[1]){
			x=c[x].f; continue;
		}
		x=c[x].f;
		if (c[x].ch[1]) res++;
	}
	return res;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) p[i]=ins(a[i]);
	int ans=0;
	for (int i=1;i<n;i++){
		int v=a[i]^a[i+1],t=-1;
		for (int j=29;~j;j--) if (v>>j&1){
			t=j; break;
		}
		ans=max(ans,2+checkleft(p[i],t)+checkright(p[i+1],t));
//		printf("test %d: %d + %d + %d\n",i,2,checkleft(p[i],t),checkright(p[i+1],t));
	}
	printf("%d\n",n-ans);
	return 0;
}