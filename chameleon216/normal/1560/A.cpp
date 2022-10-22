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

bool Check(int x)
{
	return x%3&&x%10!=3;
}

const int MX=1010;
int A[MX],ac;

int main()
{
	for(int i=1;ac<1000;++i)
		if(Check(i))A[++ac]=i;
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",A[x]);
	}
	return 0;
}