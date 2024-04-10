#include<bits/stdc++.h>
using namespace std;
int prime[1000003],tot;
bool vis[1000003];
void shai(long long X)
{
    tot=0;
    memset(vis,0,sizeof(vis));
    for(long long i=2;i<X;i++)
    {
        //
        if(!vis[i])
        {
            prime[tot++]=i;
        }
        //i
        for(long long j=0;j<tot&&prime[j]*i<X;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) // prime , i  prime[j] i*prime[j+1]  prime[j] 
            {
                break;
            }
        }
    }
}
int q[100003],t[100003],len;
bool can[10000003];
int main()
{
	long long n,m;
	cin>>n;
	if(n==1) 
	{
		cout<<"1 1";
		return 0;
	}
	shai((int)(sqrt(n))+10);
	int i=0;
	m=n,len=0;
	while(1)
	{
		if(i>=tot) break;
		if((long long)prime[i]*(long long)prime[i]>n) break;
		if(m%(long long)prime[i]==0)  
		{
			m/=prime[i];
			++len;
			q[len]=i;
			t[len]=1;
			while(m%prime[i]==0) m/=prime[i],t[len]++;
		}
		if(m==1) break;
		++i;
	}
	int sqr=(int)sqrt(n)+1;
	//if(len==1) return 0*printf("1 %I64d",n);
	memset(can,0,sizeof(can));
	can[1]=true;
	for(register int i=1; i<=len; i++) 
	{
		bool f=0;
		long long tmp=1;
		for(int j=1; j<=t[i]; j++) 
		{
			tmp*=prime[q[i]];
			if(tmp>sqr)
			{
				f=1;
				break;
			}
		}
		int lens=sqr/tmp;
		if(f) continue;
		for(register int j=lens; j>=1; --j) if(can[j]) can[j*tmp]=1;
	 } 
	for(register int i=sqr-1; i>=1; i--)
	{
		if(can[i]) 
		{
			printf("%d %I64d",i,n/i);
			return 0;
		}
	}
	return 1;
}