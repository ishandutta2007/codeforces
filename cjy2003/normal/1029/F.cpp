#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long hys[50001],ays[50001],bys[50001],a,b,c,tothys,totays,totbys,p,mini=1ll<<60;
int main()
{
	scanf("%I64d %I64d",&a,&b);
	if(a>b)hys[0]=a,a=b,b=hys[0];
	c=a+b;
	p=sqrt(c);
	for(int i=1;i<=p;++i)
		if(c%i==0)
			hys[++tothys]=i;
//	hys[++tothys]=c;
	p=sqrt(a);
	for(int i=1;i<=p;++i)
		if(a%i==0)
			ays[++totays]=i;
//	ays[++totays]=a;
	ays[totays+1]=1ll<<60;
	p=sqrt(b);
	for(int i=1;i<=p;++i)
		if(b%i==0)
			bys[++totbys]=i;
//	ays[++totays]=a;
	bys[totbys+1]=1ll<<60;
	p=0;
	for(int i=1;i<=tothys;++i)
	{
		while(ays[p]<=hys[i])++p;
		if(a/ays[p-1]<=c/hys[i])
		{
			if(hys[i]+c/hys[i]<mini)mini=hys[i]+c/hys[i];	
		}	
	}
	p=0;
	for(int i=1;i<=tothys;++i)
	{
		while(bys[p]<=hys[i])++p;
		if(b/bys[p-1]<=c/hys[i])
		{
			if(hys[i]+c/hys[i]<mini)mini=hys[i]+c/hys[i];	
		}	
	}
	printf("%I64d",mini*2);
	return 0;
}