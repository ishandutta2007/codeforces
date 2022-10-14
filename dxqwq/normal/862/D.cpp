#include<bits/stdc++.h>
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
using namespace std;
signed main(){
    int n=read();
	printf("? ");
	for(int i=1; i<=n; i++) printf("0");
	puts(""),fflush(stdout);
	int p=read();
	printf("? 1");
	for(int i=1; i<n; i++) printf("0");
	puts(""),fflush(stdout);
	int q=read();
	int id0=-1,id1=-1; 
	if(p>q) 
	{
		id1=1;//we need 0
		int l=2,r=n;
		while(l<=r)
		{
			if(l==r) 
			{
				id0=l;
				break;
			}
			int mid=(l+r)>>1;
			printf("? ");
			for(int i=1; i<=n; i++) if(l<=i && i<=mid) printf("1"); else printf("0");
			puts(""),fflush(stdout);
			int res=read();
			if(p-res==mid-l+1) l=mid+1; else r=mid; 
		}
	}
	else
	{
		id0=1;//we need 1
		int l=2,r=n;
		while(l<=r)
		{
			if(l==r) 
			{
				id1=l;
				break;	
			}
			int mid=(l+r)>>1;
			printf("? ");
			for(int i=1; i<=n; i++) if(l<=i && i<=mid) printf("1"); else printf("0");
			puts(""),fflush(stdout);
			int res=read();
			if(res-p==mid-l+1) l=mid+1; else r=mid; 
		}
	}
	printf("! %d %d\n",id0,id1);
	fflush(stdout);
    return 0;
}