#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e,f,x,y,z,i,j,k,ans=1e9;
	scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&x,&y,&z);
	for(i=max(f+1-b,0);i<=200;++i)for(j=0;j<=200;++j)
	{
		k=(d-1)/(b+i-f)+1;
		k=max(k*max(0,e-c-j)+1-a,0);
		ans=min(ans,k*x+i*y+j*z);
	}
	printf("%d",ans);
}