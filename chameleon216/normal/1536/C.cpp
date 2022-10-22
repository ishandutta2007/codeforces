#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
pair<int,int> Calc(int a,int b)
{
	int g=gcd(a,b);
	return make_pair(a/g,b/g);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n,a[2]={};
		char c;
		map<pair<int,int>,int> mp;
		scanf("%d",&n);
		Fr(i,1,n)
		{
			scanf(" %c",&c);
			++a[c=='K'];
			printf("%d ",++mp[Calc(a[0],a[1])]);
		}
		putchar('\n');
	}
	return 0;
}