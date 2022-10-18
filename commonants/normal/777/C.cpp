#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n,m;
int a[110000],*h[110000],pc[110000],*c[110000],v[110000];

int main()
{
	scanf("%d%d",&n,&m);
	h[0]=a;
	for(int i=1;i<n;i++)h[i]=h[i-1]+m;
	c[0]=pc;
	for(int i=1;i<n;i++)c[i]=c[i-1]+m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)scanf("%d",&h[i][j]);
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++)
		{
			c[i][j]=((i<n-1&&h[i][j]<=h[i+1][j])?c[i+1][j]+1:1);
		}
		for(int j=0;j<m;j++)v[i]=max(v[i],c[i][j]);
	}
	int k;scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int l,r;scanf("%d%d",&l,&r);l--,r--;
		if(v[l]>r-l)printf("Yes\n");else printf("No\n");
	}
	return 0;
}