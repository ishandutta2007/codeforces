#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n,k;
int main()
{
	cin>>n;
	if (n<=2)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int sum=n*(n+1)/2;
	if (sum%n==0)
	{
		printf("1 %d\n",n);
		printf("%d",n-1);
		rep(i,n-1)printf(" %d",i);
		puts("");
		return 0;
	}
	if (sum%(n+1)==0)
	{
		printf("2 %d %d\n",1,n);
		printf("%d",n-2);
		for(int i=2;i<n;i++)printf(" %d",i);
		puts("");
		return 0;
	}
	puts("No");
}