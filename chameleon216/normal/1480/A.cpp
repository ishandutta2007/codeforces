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
const int MX=100;

char S[MX];
void mian()
{
	scanf("%s",S+1);
	int len=strlen(S+1);
	Fr(i,1,len)
	{
		if(i&1)S[i]=(S[i]=='a'?'b':'a');
		else S[i]=(S[i]=='z'?'y':'z');
	}
	printf("%s\n",S+1);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}