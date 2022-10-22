#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=120;
int N;
char S[MX],B[MX];
int mian()
{
	scanf("%s",S+1),N=strlen(S+1);
	int L=1,R=N;
	Fill(B,0);
	Fr(i,1,N)
	{
		if(S[i]=='1')
		{
			if(!B[i-1])B[i]=1;
			else break;
		}
		L=i;
	}
	Fill(B,0);
	Fl(i,N,1)
	{
		if(S[i]=='0')
		{
			if(!B[i+1])B[i]=1;
			else break;
		}
		R=i;
	}
//	printf("%d %d\n",L,R);
	return L>=R;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r=mian();
		if(r)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}