#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_set>
#define ll long long
using namespace std;
int n,T,a[1000010];
unordered_set<int>t; 
bool chk1()
{
	for(int i=2;i<=n;i++)
		if(a[i]!=a[1]) return 0;
	return 1;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool chk2()
{
	int p1=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1) p1=1;
	if(!p1) return 1;
	t.clear();
	for(int i=1;i<=n;i++) t.insert(a[i]);
	for(int i=1;i<=n;i++) if(t.count(a[i]+1)) return 0;
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(chk1()||chk2()) printf("YES\n");
		else printf("NO\n");
	}
}