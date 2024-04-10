#include<cstdio>
#include<algorithm>
#include<map>
#define N 510
using namespace std;
map<int,int>tt;
int to[N],cnt,len,ans[N],s[N*N][2],tot,a[N],x,T,n,t[N];
int _get(int x)
{
	if(!tt[x]) tt[x]=++cnt,to[cnt]=x;
	return tt[x];
}
void op(int x,int y)
{
	tot++;
	s[tot][0]=x,s[tot][1]=to[y];
}
void work(int l,int r)
{
	ans[++len]=r-l;
	for(int i=1;l+i<r;i++) op(l+i-2,a[r-i]);
	for(int i=1;l+i<r-i;i++) swap(a[l+i],a[r-i]);
	for(int i=l;i<r;i++) a[i]=a[i+1];
}
bool check()
{
	for(int i=1;i<=cnt;i++) t[i]=0;
	for(int i=1;i<=n;i++) t[a[i]]++;
	for(int i=1;i<=n;i++) if(t[a[i]]&1) return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tt.clear(),cnt=len=tot=0;
		for(int i=1;i<=n;i++) scanf("%d",&x),a[i]=_get(x);
		if((n&1)||check()){printf("-1\n");continue;}
		for(int i=n,j;i;i-=2)
		{
			j=i-1;
			while(a[j]!=a[i]) j--;
			work(j,i);
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++) printf("%d %d\n",s[i][0],s[i][1]);
		printf("%d\n",len);
		for(int i=len;i;i--) printf("%d ",ans[i]*2);
		printf("\n");
	}
}