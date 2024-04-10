#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M1=1000000007,M2=998244353;
int n,i,k,p,j,t;
ll h1[1000005],h2[1000005],s1,s2,a1,a2,aa1,ss1,aa2,ss2;
char c[1000005],ans[1000005];
int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	n--;
	for(i=1;c[i];i++)
	{
		ans[i]=c[i];
		h1[i]=(h1[i-1]*109+ans[i]-'0')%M1;
		h2[i]=(h2[i-1]*107+ans[i]-'0')%M2;
	}
	k=strlen(c+1);
	while(n--)
	{
		scanf("%s",c+1);
		ss1=ss2=s1=s2=1;
		p=0;
		aa1=aa2=a1=a2=0;
		t=0;
		for(i=1;c[i]&&i<=k;i++)
		{
			s1=s1*109%M1;
			s2=s2*107%M2;
			a1=(a1*109+c[i]-'0')%M1;
			a2=(a2*107+c[i]-'0')%M2;
			if(i%2==0)
			{
				t++;
				aa1=(aa1*109+c[i/2]-'0')%M1;
				aa2=(aa2*107+c[i/2]-'0')%M2;
				ss1=ss1*109%M1;
				ss2=ss2*107%M2;
			}
			if(a1==((h1[k]-h1[k-i]*s1)%M1+M1)%M1&&a2==((h2[k]-h2[k-i]*s2)%M2+M2)%M2)
				if(aa1==((h1[k-i+t]-h1[k-i]*ss1)%M1+M1)%M1&&aa2==((h2[k-i+t]-h2[k-i]*ss2)%M2+M2)%M2)
					p=i;
		}
		for(j=p+1;c[j];j++)
		{
			ans[++k]=c[j];
			h1[k]=(h1[k-1]*109+ans[k]-'0')%M1;
			h2[k]=(h2[k-1]*107+ans[k]-'0')%M2;
		}
	}
	printf("%s",ans+1);
}