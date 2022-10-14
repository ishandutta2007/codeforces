#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[33];
signed main()
{
	int n=read(),m=read();
	puts("1"),fflush(stdout);
	a[1]=read();
	if(a[1]==0) return 0;
	for(int i=2; i<=m; i++) puts("1"),fflush(stdout),a[i]=read(); 
	int l=2,r=n,ans=n,pos=0;
	while(l<=r)
	{
		++pos,(pos>m)&&(pos-=m);
		int mid=(l+r)>>1;
		printf("%d\n",mid),fflush(stdout);
		int res=read()*a[pos];
		if(res==0) return 0;
		else if(res==1) l=mid+1;
		else r=mid-1;
	}
	return 0;
}