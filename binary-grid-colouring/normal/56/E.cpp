#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n;
struct node
{
	int x,h;
	int dp,id;
}a[maxn];
int sum[maxn];
bool cmp(node a,node b)
{
	return a.x>b.x;
}

int main()
{
   //freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].h;
		a[i].id=i;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)a[i].dp=1;
	sum[a[0].id]=1;
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j-=a[j].dp)
		{
			if(a[j].x>a[i].x+a[i].h-1) break;//
			else a[i].dp += a[j].dp; 
		 
		}
		sum[a[i].id]=a[i].dp;
	//	printf("%d %d\n",a[i].id,a[i].dp);
	}
	for(int i=0;i<n;i++){
		printf("%d ",sum[i]); 
	}
	return 0;
}