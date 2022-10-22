#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
#define N 200010
using namespace std;
int T,cl[N],cr[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int n,l,r,c,ans=0,suml=0,sumr=0,twol=0,twor=0;
		scanf("%d %d %d",&n,&l,&r);
		for(int i=1;i<=n;++i) cl[i]=cr[i]=0;
		for(int i=1;i<=l;++i)
			scanf("%d",&c),++cl[c];
		for(int i=1;i<=r;++i)
			scanf("%d",&c),++cr[c];
		for(int i=1;i<=n;++i)
			if(cl[i]<=cr[i]) cr[i]-=cl[i],cl[i]=0,sumr+=cr[i],twor+=cr[i]>>1;
			else cl[i]-=cr[i],cr[i]=0,suml+=cl[i],twol+=cl[i]>>1;
		while(suml<sumr && twor) --twor,sumr-=2,++ans;
		while(suml>sumr && twol) --twol,suml-=2,++ans;
		ans+=max(suml,sumr);
		printf("%d\n",ans);
	}
	return 0;
}