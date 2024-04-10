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
char S[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%s",S+1);
		N=strlen(S+1);
		S[0]='2';
		int cnt[2]={0,0};
		Fr(i,1,N)if(S[i]!=S[i-1])
			cnt[S[i]-'0']++;
		int ans=0;
		if(!cnt[0])ans=0;
		else if(!cnt[1])ans=1;
		else if(cnt[0]==1)ans=1;
		else ans=2;
		printf("%d\n",ans);
	}
	return 0;
}