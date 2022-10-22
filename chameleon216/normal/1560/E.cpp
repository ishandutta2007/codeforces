#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=500100;
char S[MX],T[MX];
int N,cnt[26],B[26];

bool Check(int sl,int tl)
{
	memset(B,0,sizeof(B));
	int c=0;
	Fr(i,1,tl)
	{
		Fr(j,1,sl)if(!B[S[j]-'a'])
			if(S[++c]!=S[j])return 0;
		B[T[i]-'a']=1;
	}
	return c==N;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%s",S+1),N=strlen(S+1);
		memset(cnt,0,sizeof(cnt));
		int tc=0;
		Fl(i,N,1)
		{
			int c=S[i]-'a';
			if(!cnt[c])T[++tc]=S[i];
			++cnt[c];
		}
		reverse(T+1,T+tc+1),T[tc+1]=0;
		int len=0;
		Fr(i,1,tc)len+=cnt[T[i]-'a']/i;
		if(Check(len,tc))S[len+1]=0,printf("%s %s\n",S+1,T+1);
		else printf("-1\n");
	}
	return 0;
}