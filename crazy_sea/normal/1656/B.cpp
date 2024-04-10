#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#define ll long long
using namespace std;
set<int>t;
int n,k,a[1000010],T;
bool chk()
{
	for(int i=1;i<=n;i++)
		if(t.count(a[i]+k)) return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			t.insert(a[i]);
		}
		printf("%s\n",chk()?"YES":"NO");
		t.clear();
	 } 
}