#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,M;
char S[MX];
int F(int i)
{
	if(i<=1||i>=N)return 0;
	return S[i-1]=='a'&&S[i]=='b'&&S[i+1]=='c';
}
int sum=0;

int main()
{
	scanf("%d%d%s",&N,&M,S+1);
	Fr(i,2,N-1)sum+=F(i);
	Fr(i,1,M)
	{
		int x;
		char c;
		scanf("%d %c",&x,&c);
		sum-=F(x-1)+F(x)+F(x+1);
		S[x]=c;
		sum+=F(x-1)+F(x)+F(x+1);
		printf("%d\n",sum);
	}
	return 0;
}