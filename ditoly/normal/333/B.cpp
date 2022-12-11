#include<cstdio>
#include<algorithm>
using namespace std;
#define R(a,x) for(int a=0;a<(x);++a)
#define MN 200000
int r[MN+5],c[MN+5];
int main()
{
	int n,m,i,x,y,ans=0;
	scanf("%d%d",&n,&m);
	while(m--)scanf("%d%d",&x,&y),r[x]=1,c[y]=1;
	for(i=2;i<n-i+1;++i)
	{
		int res=0;
		R(r1,r[i]?1:3)R(r2,r[n-i+1]?1:3)R(c1,c[i]?1:3)R(c2,c[n-i+1]?1:3)
		{
			if(r1&&c1&&r1==c1)continue;
			if(r1&&c2&&r1!=c2)continue;
			if(r2&&c2&&r2==c2)continue;
			if(r2&&c1&&r2!=c1)continue;
			res=max(res,bool(r1)+bool(r2)+bool(c1)+bool(c2));
		}
		ans+=res;
	}
	if((n&1)&&(!r[n+1>>1]||!c[n+1>>1]))++ans;
	printf("%d",ans);
}