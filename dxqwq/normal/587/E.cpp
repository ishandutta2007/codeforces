//As a zkdxl and Peal_Frog follower,plz no bug!!!
#include<bits/stdc++.h>
using namespace std;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n=read();
struct lb { int n[33]; } a[800003];
lb emptylb;
int s[200003],t[200003],tree[200003];
void add(int x,int k) { while(x<=n) tree[x]^=k,x+=x&(-x); return ; }
int find(int x) { int res=0; while(x) res^=tree[x],x-=x&(-x); return res; }
inline lb insert(lb x,int y)
{
	lb res=x;
	int tmp=1<<30;
	for(int i=30; i>=0; i--,tmp>>=1) if(tmp&y) if(res.n[i]) y^=res.n[i]; else { res.n[i]=y; break; } 
	return res;
}
inline lb merge(int x,int y)//merge x y
{
	lb res=a[x];
	for(int i=0; i<=30; i++) if(a[y].n[i]) res=insert(res,a[y].n[i]); 
	return res;
}
inline lb merge(lb x,lb y)//merge x y
{
	lb res=x;
	for(int i=0; i<=30; i++) if(y.n[i]) res=insert(res,y.n[i]); 
	return res;
}
void build(int l,int r,int i)
{
	//printf("%d %d %d\n",l,r,i);
	//system("pause");
	if(l==r) 
	{
		a[i]=insert(emptylb,t[l]);
		return ; 
	}
	int mid=(l+r)>>1;
	build(l,mid,i<<1),build(mid+1,r,(i<<1)+1),a[i]=merge(i<<1,(i<<1)+1);
	return ;
}
int getsize(lb x)
{
	int res=0;
	for(int i=30; i>=0; i--) if(x.n[i]) ++res;
	return (1<<res);
}
void update(int l,int r,int k,int i)
{
	if(l==r) 
	{
		a[i]=insert(emptylb,t[l]);
		return ; 
	}
	int mid=(l+r)>>1;
	if(k<=mid) update(l,mid,k,(i<<1)); else update(mid+1,r,k,(i<<1)+1);
	a[i]=merge(i<<1,(i<<1)+1);
	return ;
}
lb getlb(int l,int r,int L,int R,int i)
{
	if(r<L || R<l) return emptylb; 
	if(L<=l && r<=R) return a[i];
	if(l==r) return a[i];
	int mid=(l+r)>>1;
	return merge(getlb(l,mid,L,R,i<<1),getlb(mid+1,r,L,R,(i<<1)+1));
}
int main()
{
	for(int i=0; i<=30; i++) emptylb.n[i]=0;
	int m=read();
	for(int i=1; i<=n; i++) s[i]=read(),t[i]=s[i-1]^s[i],add(i,t[i]);
	build(1,n,1);
	while(m--)
	{
		int opt=read(),l=read(),r=read();
		if(opt==1)
		{
			int v=read();
			t[l]^=v,add(l,v),update(1,n,l,1);
			if(r!=n) t[r+1]^=v,add(r+1,v),update(1,n,r+1,1);
		}
		else printf("%d\n",getsize(insert(getlb(1,n,l+1,r,1),find(l))));
	}
	return 0;
}