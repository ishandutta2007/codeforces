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

void Write(int x)
{
	putchar('A');
	while(x)putchar('a'+(x&1)),x>>=1;
	putchar(' ');
}

const int MX=60;
int N,K,C[MX],cc;


int main()
{
	scanf("%d%d",&N,&K);
	char s[30];
	Fr(i,1,K-1)C[i]=++cc;
	Fr(i,1,N-K+1)scanf("%s",s),C[i+K-1]=(*s=='Y')?++cc:C[i];
	Fr(i,1,N)Write(C[i]);
	putchar('\n');
}