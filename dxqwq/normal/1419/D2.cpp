#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003],c[1000003];
bool check(int n,int x)
{
	int t=n-x-1;
	for(int i=1; i<=x; i++) b[i*2-1]=a[++t],b[i*2]=a[i];
	b[x*2+1]=a[++t];
	
	for(int i=1; i<=x; i++) if(b[i*2-1]<=b[i*2] || b[i*2]>=b[i*2+1]) return 0;
	
	t=x;
	for(int i=1; i<=x*2+1; i++) c[i]=b[i];
	for(int i=x*2+2; i<=n; i++) c[i]=a[++t];
	return 1;
}
int main()
{
	int n=read();
	for(int i=1; i<=n; i++) c[i]=a[i]=read();
	sort(a+1,a+n+1);
	int l=1,r=(n-1)/2;
	int res=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(n,mid)) res=mid,l=mid+1; else r=mid-1;
	}
	printf("%d\n",res);
	for(int i=1; i<=n; i++) printf("%d ",c[i]);
	return 0;
}