#include<bits/stdc++.h>
#define N 200005
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int gg,g,d,ss,n,m,cn[N],a[N],l,r,mid,ans,k[N];

inline int ch(int p)
{
	g=gg;
	memset(cn,0,sizeof(cn));
	++cn[0]; 
	for(int i=1; i<=n; ++i){
		++cn[a[i]];
		if(cn[a[i]]==k[a[i]])++g;
		if(i-ss-p>=0){ 
			--cn[a[i-ss-p]];
			if(cn[a[i-ss-p]]==k[a[i-ss-p]]-1)--g;
		}
		if(g>m)return 1;
	}
	return 0;
}

int main()
{
	n=read(); m=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	for(int i=1; i<=m; ++i)k[i]=read(),ss+=k[i];
	for(int i=0; i<=m; ++i)if(!k[i])++gg; 
	ans=-1;l=0; r=n-ss;
	while(l<=r){
		mid=(l+r)>>1;
		if(ch(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}