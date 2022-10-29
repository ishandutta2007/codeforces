#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=200005;
int n;
int a[maxn],b[maxn],p[maxn];
int ans[maxn];
bool cmpb(int i,int j)
{return b[i]<b[j];}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),p[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	sort(p+1,p+n+1,cmpb);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ans[p[i]]=a[n-i+1];
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}