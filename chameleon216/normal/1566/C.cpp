#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;

const int MX=100100;
int N;
char S[MX],T[MX];
int A[MX];

int Solve()
{
	int sum=0;
	A[N+1]=1;
	Fr(i,1,N)
	{
		if(A[i]==1)sum+=2;
		else if(A[i]==2)
		{
			if(A[i+1]==0)sum+=2,++i;
		}
		else if(A[i]==0)
		{
			if(A[i+1]==2)sum+=2,++i;
			else sum+=1;
		}
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%s%s",&N,S+1,T+1);
		Fr(i,1,N)A[i]=(S[i]-'0')+(T[i]-'0');
		printf("%d\n",Solve());
	}
	return 0;
}