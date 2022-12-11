#include<stdio.h>
#include<string.h>
#include<math.h>
int n,q,t[40],w,ma,ans;
long long m[40],a;
int main()
{
	m[0]=1;
	for(int i=1;i<=35;i++)
		m[i]=m[i-1]*2;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a);
		w=log(a)/log(2)+0.00000001;
		t[w]++;
		if(w>ma)ma=w;
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		scanf("%I64d",&a);
		w=log(a)/log(2)+0.00000001;
		while(a)
		{
			if(t[w]>=a/m[w])
			ans+=a/m[w],a-=a/m[w]*m[w];
			else ans+=t[w],a-=t[w]*m[w];
			if(w==0)break;
			w--;
		}	
		if(a!=0)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}