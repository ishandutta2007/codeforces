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

const int MX=5010;
int N,M;
char S[MX];

bool Comp(int a,int b)
{
	Fo(i,0,M)if(S[i%a]!=S[i%b])
		return S[i%a]<S[i%b];
	return 0;
}


int main()
{
	scanf("%d%d%s",&N,&M,S);
	int id=1;
	Fr(i,2,N)if(Comp(i,id))id=i;
	Fo(i,0,M)printf("%c",S[i%id]);
	putchar('\n');
	return 0;
}