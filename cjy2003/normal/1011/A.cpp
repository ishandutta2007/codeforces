#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
int n,k,ans,sum,jl;
char a[60];
int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",a+1);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>jl+1)
		{
			if(sum<k)sum++,ans+=a[i]-'a'+1,jl=a[i];
			else break;	
		}
	}
	if(sum<k)printf("-1");
	else printf("%d",ans);
	return 0;
}