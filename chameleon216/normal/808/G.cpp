#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

template<typename T1,typename T2>
inline void max_eq(T1& a,T2 b){if(a<b)a=b;}

const int MX=100100;
int N,M;
char S[MX],T[MX];

int F[MX],C[MX][26];
void Build()
{
	C[0][S[1]-'a']=1;
	Fr(i,1,N)Fr(k,0,25)
	{
		if(S[i+1]==k+'a')
			C[i][k]=i+1,F[C[i][k]]=C[F[i]][k];
		else C[i][k]=C[F[i]][k];
	}
}

int dp[2][MX];

int main()
{
	scanf("%s%s",T+1,S+1);
	N=strlen(S+1),M=strlen(T+1);
	Build();
	int *d=dp[0],*e=dp[1];
	memset(dp,0xc0,sizeof(dp)),d[0]=0;
	Fr(i,1,M)
	{
		Fr(j,0,N)
		{
			if(T[i]=='?')
				Fr(k,0,25)max_eq(e[C[j][k]],d[j]+(C[j][k]==N));
			else max_eq(e[C[j][T[i]-'a']],d[j]+(C[j][T[i]-'a']==N));
		}
		swap(d,e);
		memset(e,0xc0,(N+1)*sizeof(int));
	}
	int ans=0;
	Fr(j,0,N)max_eq(ans,d[j]);
	printf("%d\n",ans);
	return 0;
}