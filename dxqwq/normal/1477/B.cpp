#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
char t[1000003];
int tag[2000003],sum[2000003],x[1000003],y[1000003];
void build(int l,int r,int i)
{
	tag[i]=0;
	if(l==r)
	{
		sum[i]=(t[l]=='1');
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,i<<1),build(mid+1,r,(i<<1)+1);
	sum[i]=sum[i<<1]+sum[(i<<1)+1];
	return ;
}
void pd(int i,int L,int R)
{
	tag[i<<1]=tag[(i<<1)+1]=tag[i];
	if(tag[i]==1) sum[i<<1]=sum[(i<<1)+1]=0;
	else sum[i<<1]=L,sum[(i<<1)+1]=R;
	tag[i]=0;
	return ;
}
int getsum(int l,int r,int L,int R,int i)
{
	if(r<L||R<l) return 0;
	if(L<=l&&r<=R)
	{
		return sum[i];
	}
	int mid=(l+r)>>1;
	if(tag[i]) pd(i,mid-l+1,r-mid);
	return getsum(l,mid,L,R,i<<1)+getsum(mid+1,r,L,R,(i<<1)+1);
}
void set0(int l,int r,int L,int R,int i)
{
	if(r<L||R<l) return ;
	if(L<=l&&r<=R)
	{
		tag[i]=1,sum[i]=0;
		return ;
	}
	int mid=(l+r)>>1;
	if(tag[i]) pd(i,mid-l+1,r-mid);
	set0(l,mid,L,R,i<<1),set0(mid+1,r,L,R,(i<<1)+1);
	sum[i]=sum[i<<1]+sum[(i<<1)+1];
	return ;
}
void set1(int l,int r,int L,int R,int i)
{
	if(r<L||R<l) return ;
	if(L<=l&&r<=R)
	{
		tag[i]=2,sum[i]=r-l+1;
		return ;
	}
	int mid=(l+r)>>1;
	if(tag[i]) pd(i,mid-l+1,r-mid);
	set1(l,mid,L,R,i<<1),set1(mid+1,r,L,R,(i<<1)+1);
	sum[i]=sum[i<<1]+sum[(i<<1)+1];
	return ;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		build(1,n,1);
		for(int i=1; i<=m; i++) 
		{
			x[i]=read(),y[i]=read();
		}
		bool f1=0,f2=0;
		for(int i=x[1]; i<=y[1]; i++) if(s[i]=='0') f1=1; else f2=1;
		if(f1&&f2)
		{
			puts("NO");
			continue;
		}
		bool yes=1,f3=0,f4=0;
		for(int i=m; i>=1; i--)
		{
			int t=getsum(1,n,x[i],y[i],1);
			double mid=0.5*(y[i]-x[i]+1);
			if(t<mid)
			{
				assert(y[i]-x[i]+1-t>=mid);
				set0(1,n,x[i],y[i],1);
				if(i==1) f3=1;
			}
			else if(y[i]-x[i]+1-t<mid)
			{
				set1(1,n,x[i],y[i],1);
				if(i==1) f4=1;
			}
			else
			{
				yes=0;
				break;
			}
		}
		for(int i=1; i<=n; i++) if(s[i]-'0'!=getsum(1,n,i,i,1)) yes=0;
		if(yes) 
		{
			puts("YES");
		 } 
		 else puts("NO");
	}
	return 0;
}