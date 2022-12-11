#include<cstdio>
#define MN 10000000
int p[MN+5],pn,u[MN+5],mu[MN+5],phi[MN+5],cnt,s[MN+5];
long long ans,S;
bool cmp(int a,int b){return u[a]<u[b];}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		if(!u[i])p[++pn]=u[i]=i,mu[i]=-1,phi[i]=i-1;
		for(j=1;i*p[j]<=n;++j)
		{
			u[i*p[j]]=p[j];
			if(i%p[j])mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*(p[j]-1);
			else{phi[i*p[j]]=phi[i]*p[j];break;}
		}
		++s[u[i]];ans+=i-1-phi[i];
	}
	for(i=1;i<=pn;++i)if(p[i]>n/2)++cnt;
	ans+=3*(1LL*(n-1)*(n-2)/2-ans-1LL*cnt*(n-1-cnt)-1LL*cnt*(cnt-1)/2);
	for(i=2;i<=n;++i)s[i]+=s[i-1];
	for(i=2;i<=n;++i)S+=1LL*(s[i]-s[i-1])*s[n/i];
	for(i=2;i<=n;++i)S+=(1LL*(n/i)*(n/i)-(1LL*i*i>n&&u[i]==i))*mu[i];
	printf("%I64d",ans-S/2);
}