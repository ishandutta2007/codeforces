#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=220000,Inf=0x3f3f3f3f;
int N,K;
const int M=200000;
char S[MX];
int L[MX][26],R[MX][26];
int cnt[MX];

int main()
{
	scanf("%d%d",&N,&K);
	scanf("%s",S+1);
	Fo(k,0,26)L[0][k]=Inf;
	Fr(i,1,K)cnt[S[i]-'a']=1;
	Fr(i,1,M)
	{
		Fo(k,0,26)L[i][k]=L[i-1][k]+1;
		if(S[i])L[i][S[i]-'a']=0;
	}
	Fo(k,0,26)R[M+1][k]=Inf;
	Fl(i,M,1)
	{
		Fo(k,0,26)R[i][k]=R[i+1][k]+1;
		if(S[i])R[i][S[i]-'a']=0;
	}
	Fr(i,1,N)
	{
		ll sum=0;
		scanf("%s",S+1);
		int l=strlen(S+1);
		Fr(j,1,l)
		{
			int k=S[j]-'a';
			//printf("%d ",min(l,min(L[j][k],R[j][k])));
			int t=min(L[j][k],R[j][k]);
			if(cnt[k]==0)t=l;
			sum+=t;
		}
		//putchar('\n');
		printf("%lld\n",sum);
	}
	return 0;
}