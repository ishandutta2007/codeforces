#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define LL long long
using namespace std;
struct node
{
	int x;
	int id;
	friend bool operator <(node x,node y)
	{
		return x.x>y.x;
	}
}b[300000];
int a[300000];
int ans[300000];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){ scanf("%d",&b[i].x); b[i].id=i; }
	sort(b+1,b+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans[b[i].id]=a[i];
	printf("%d",ans[1]);
	for(int i=2;i<=n;i++)printf(" %d",ans[i]);
	printf("\n");
	return 0;
}