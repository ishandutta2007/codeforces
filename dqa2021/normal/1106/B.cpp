#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

int L[100010],R[100010];
void del(int x)
{
	L[R[x]]=L[x];
	R[L[x]]=R[x];
}
int n,m;
int a[100010],c[100010];
int tot;
int seq[100010];
bool cmp(int x,int y)
{
	if (c[x]!=c[y])
		return c[x]<c[y];
	return x<y;
}
int main()
{
	scanf("%d%d",&n,&m); tot=n;
	for (int i=1;i<=n;i++) scanf("%d",a+i),seq[i]=i;
	for (int i=1;i<=n;i++) scanf("%d",c+i);
	sort(seq+1,seq+n+1,cmp); R[0]=seq[1];
	for (int i=1;i<=n;i++) L[seq[i]]=seq[i-1],R[seq[i]]=seq[i+1];
	while (m--)
	{
		int x,y;  ll ans=0;
		scanf("%d%d",&x,&y);
		if (a[x])
		{
			int tmp=min(a[x],y);
			ans+=(ll)c[x]*tmp;
			a[x]-=tmp;  y-=tmp;
			if (!a[x]) del(x),tot--;
		}
		while (tot&&y)
		{
//			printf("x %d  y %d    %d\n",R[0],y,a[R[0]]);
			int tmp=min(a[R[0]],y);
			ans+=(ll)c[R[0]]*tmp;
			a[R[0]]-=tmp; y-=tmp;
			if (!a[R[0]]) del(R[0]),tot--;
		}
		printf("%I64d\n",y?0LL:ans);   //!!!
	}
	return 0;
}