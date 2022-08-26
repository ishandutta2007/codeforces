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
int n,m,i,j,a[1000005],b[1000005],fa[2000005],typ[2000005],l,r,mid,ans,cnt;
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
int f(int x){if(x>n) return x-n;return x+n;}
vector<int> all;
char merge(int x,int y)
{
x=fnd(x);y=fnd(y);if(x==y){if(typ[x])return 1;typ[x]=1;return 0;}
if(typ[x]&&typ[y]) return 1;
fa[x]=y;typ[y]|=typ[x];return 0;
}
char check(int x)
{
int i;fz1(i,all.size()){fa[i]=i;typ[i]=0;}
fz1(i,n)
{
if(a[i]>x&&b[i]>x) return 0;
if(a[i]>x||b[i]>x) if(merge(min(a[i],b[i]),min(a[i],b[i]))) return 0;
if(a[i]<=x&&b[i]<=x) if(merge(a[i],b[i])) return 0;
}
return 1;
}
int main()
{
scanf("%d",&n);fz1(i,n){scanf("%d%d",&a[i],&b[i]);all.push_back(a[i]);all.push_back(b[i]);}
sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
fz1(i,n){a[i]=upper_bound(all.begin(),all.end(),a[i])-all.begin();b[i]=upper_bound(all.begin(),all.end(),b[i])-all.begin();}
l=0;r=all.size();ans=-1;
while(l<r){mid=(l+r+1)/2;if(check(mid)){r=mid-1;ans=mid;}else l=mid;}
if(ans==-1) puts("-1"); else printf("%d\n",all[ans-1]);return 0;
}