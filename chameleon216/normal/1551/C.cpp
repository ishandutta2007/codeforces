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

const int MX=400100;
int N,X;
char S[MX];
int len[MX],cnt[MX][5],I[MX];

int Get(int i){return 2*cnt[i][X]-len[i];}
bool Comp(int i,int j){return Get(i)>Get(j);}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)
		{
			scanf("%s",S+1);
			len[i]=strlen(S+1);
			Fr(j,1,len[i])++cnt[i][S[j]-'a'];
			I[i]=i;
		}
		int ans=0;
		Fo(k,0,5)
		{
			X=k,sort(I+1,I+N+1,Comp);
			int sum=0,c=0;
			Fr(i_,1,N)
			{
				int i=I[i_];
				sum+=Get(i);
				if(sum<=0)break;
				++c;
			}
			ans=max(ans,c);
		}
		printf("%d\n",ans);
		memset(cnt,0,(N+1)*sizeof(*cnt));
	}
	return 0;
}