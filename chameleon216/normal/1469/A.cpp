#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
const int MX=200;

char s[MX];
int N;
bool solve()
{
	N=strlen(s+1);
	int l,r;
	Fr(i,1,N)
	{
		if(s[i]=='(')l=i;
		if(s[i]==')')r=i;
	}
	int a=(l-1)%2,b=(r-l-1)%2,c=(N-r)%2;
	return (a+b+c)%2==0&&l!=N&&r!=1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		printf(solve()?"YES\n":"NO\n");
	}
	return 0;
}