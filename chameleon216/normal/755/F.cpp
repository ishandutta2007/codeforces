#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <bitset>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1000010;
int N,K,P[MX],B[MX];
int cnt[MX];

bitset<MX> dp;
int S[MX];
int GetMin()
{
	dp[0]=1;
	Fr(v,1,N)
	{
		int c=cnt[v];
		if(c<=8)
		{
			Fr(i,1,c)dp|=dp<<v;
		}
		else 
		{
			Fr(i,0,N)
			{
				S[i]=dp[i];
				if(i>=v)S[i]+=S[i-v];
				dp[i]=S[i]-(i>=v*(c+1)?S[i-v*(c+1)]:0);
			}
		}
	}
	return K+!dp[K];
}

int GetMax()
{
	int s1=0,s2=0;
	Fr(i,1,N)
	{
		s1+=(i&1)*cnt[i];
		s2+=(i>>1)*cnt[i];
	}
	int k=K,r=0;
	r+=2*min(s2,k),k-=min(s2,k);
	r+=min(s1,k),k-=min(s1,k);
	return r;
}

int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)scanf("%d",&P[i]);
	Fr(i,1,N)if(!B[i])
	{
		int c=0;
		for(int x=i;!B[x];B[x]=1,x=P[x],++c);
		++cnt[c];
	}
	printf("%d %d\n",GetMin(),GetMax());
	return 0;
}