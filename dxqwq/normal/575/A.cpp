// Problem: A. Fibonotci
// Contest: Codeforces - Bubble Cup 8 - Finals [Online Mirror]
// URL: https://codeforces.com/problemset/problem/575/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int k=read(),p=read();
struct Matrix
{
    int a[2][2];
    Matrix operator*(const Matrix&t)const
    {
        Matrix res;
        memset(res.a,0,sizeof(res.a));
        for(int i=0; i<2; ++i)
            for(int k=0; k<2; ++k)
                for(int j=0; j<2; ++j)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*t.a[k][j])%p;
        return res;
    }
}f[200003];
Matrix qp(Matrix x,int y)
{
	Matrix res=(Matrix){1,0,0,1};
	for(Matrix t=x; y; y>>=1,t=t*t) if(y&1) res=res*t;
	return res;
}
int a[50003];
bool tag[200003];
struct node1{int x,y;bool operator<(const node1&t)const{return x<t.x;}}b[50003];
struct node2{int x;Matrix y;}c[100003];
void build(int l,int r,int x)
{
	if(tag[x]) return ;
	tag[x]=1;
	if(l==r) 
	{
		f[x]=(Matrix){0,a[l],1,a[l+1]};
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,(x<<1)+1),
	f[x]=f[x<<1]*f[(x<<1)+1];
	return ;
}
void update(int nl,int nr,int pos,int x,Matrix t)
{
	tag[x]=0;
	if(nl==nr) 
	{
		f[x]=t;
		return ;
	}
	int mid=(nl+nr)>>1;
	if(pos<=mid) update(nl,mid,pos,x<<1,t);
	else update(mid+1,nr,pos,(x<<1)+1,t);
	f[x]=f[x<<1]*f[(x<<1)+1];
	return ;
}
Matrix query(int nl,int nr,int l,int r,int x)
{
	if(l<=nl&&nr<=r) return f[x];
	if(r<nl||nr<l) return (Matrix){1,0,0,1};
	int mid=(nl+nr)>>1;
	return query(nl,mid,l,r,x<<1)*query(mid+1,nr,l,r,(x<<1)+1);
}
signed main()
{
	if(p==1) puts("0"),exit(0);
	if(k==0) puts("0"),exit(0); 
	if(k==1) puts("1"),exit(0);
	--k;
	int n=read();
	for(int i=0; i<n; ++i) a[i]=read();
	int m=read(),M=0;
	for(int i=1; i<=m; ++i) 
		b[i].x=read(),b[i].y=read();
	sort(b+1,b+m+1),b[0].x=b[m+1].x=-1;
	Matrix tmp=(Matrix){0,0,1,0},ans=(Matrix){1,0,0,1};
	for(int i=1; i<=m; ++i)
	{
		if(b[i-1].x+1!=b[i].x)
		{
			tmp.a[0][1]=a[(b[i].x-1)%n],
			tmp.a[1][1]=b[i].y,
			c[++M]=(node2){b[i].x-1,tmp};
		}
		if(b[i].x+1!=b[i+1].x)
		{
			tmp.a[0][1]=b[i].y,
			tmp.a[1][1]=a[(b[i].x+1)%n],
			c[++M]=(node2){b[i].x,tmp};
		}
		else
		{
			tmp.a[0][1]=b[i].y,
			tmp.a[1][1]=b[i+1].y,
			c[++M]=(node2){b[i].x,tmp};
		}
	}
	a[n]=a[0],build(0,n-1,1);
	while(c[M].x>=k) --M;
	for(int i=1; i<=M; ++i)
	{
		if(c[i-1].x/n!=c[i].x/n)
			ans=ans*f[1],build(0,n-1,1);
		if(c[i-1].x/n+1<c[i].x/n)
			ans=ans*qp(f[1],c[i].x/n-c[i-1].x/n-1);
		update(0,n-1,c[i].x%n,1,c[i].y);
	}
	if(c[M].x/n!=k/n)
		ans=ans*f[1],build(0,n-1,1);
	if(c[M].x/n+1<k/n)
		ans=ans*qp(f[1],k/n-c[M].x/n-1);
	ans=ans*query(0,n-1,0,k%n,1);
	printf("%lld\n",ans.a[1][0]);
	return 0;
}