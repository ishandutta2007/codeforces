#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,f[505][505],g[505][505];
string st;
int dfsf(int l,int r);
int dfsg(int l,int r)
{
if(l>r) return 0;
if(l==r) return 1;
if(g[l][r]!=-1) return g[l][r];
int i;g[l][r]=0x12121212;
for(i=r-1;i>=l;i--) if(st[i]==st[r]) g[l][r]=min(g[l][r],dfsg(l,i)+dfsf(i+1,r-1));
return g[l][r];
}
int dfsf(int l,int r)
{
if(l>r) return 0;
if(l==r) return 1;
if(f[l][r]!=-1) return f[l][r];
f[l][r]=(st[l]==st[r]?dfsg(l,r):0x12121212);
int i;
fz(i,l,r-1) f[l][r]=min(f[l][r],dfsf(l,i)+dfsf(i+1,r));
return f[l][r];
}
int main()
{
cin>>n>>st;st=" "+st;
memset(f,-1,sizeof(f));memset(g,-1,sizeof(g));
cout<<dfsf(1,n)<<endl;
return 0;
}