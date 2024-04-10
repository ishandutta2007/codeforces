#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define inf 1000000007
#define N 200005
using namespace std;
long long a[310000],b[310000];
int mylog(long long x)
{
	int s=0;
	while(1)
	{
		long long tmp=1;
		tmp=tmp<<(s+1);
		tmp--;
		if (tmp<x)s++;
		else break;
	}
	return s;
}
long long mypow(int x,int k)
{
	long long ans=1;
	while (1)
	{
		if (k & 1)ans=(ans*x)%inf;
		x=(x*x)%inf;
		k>>=1;
	}
	return ans;
}
long long aa[510000],bb[51000];
int Q,T;
long long now,K;
int main(){
	int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&T);
        if(T==1)
        	{ 
        		scanf("%lld",&now);
        		scanf("%lld",&K);
        		int p=mylog(now);
        		K=(K+(1ll<<p))%(1ll<<p);(aa[p]+=K)%=(1ll<<p); 
        		continue; 
        	}
        if(T==2)
        	{ 
        		scanf("%lld",&now);
        		scanf("%lld",&K);
        		int p=mylog(now);
        		K=(K+(1ll<<p))%(1ll<<p);
        		(bb[p]+=K)%=(1ll<<p); 
        		continue; 
        	}
        if(T==3){
            scanf("%lld",&now);
            int tp=mylog(now);
            now=(now-(1ll<<tp)+aa[tp]+(1ll<<tp))%(1ll<<tp)+(1ll<<tp);
            while(now>1)
            {
                int p=mylog(now);
                printf("%lld ",(now-(1ll<<p)-aa[p]+(1ll<<p))%(1ll<<p)+(1ll<<p));
                now=(now-(1ll<<p)+bb[p]+(1ll<<p))%(1ll<<p)+(1ll<<p);
                now=now>>1;
            }
            puts("1");
        }
    }
    return 0;
}