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
int n,m,i,j,b[200005];
long long a[200005],l,r,mid,ans;
struct ii{long long x;int y;};
bool operator <(const ii &x,const ii&y){return x.x/x.y>y.x/y.y;}
bool check(long long x)
{
int i;
priority_queue<ii> pq;
fz1(i,n) if(1ll*b[i]*(m-1)>a[i]) pq.push((ii){a[i],b[i]});
fz0k(i,m)
{
if(pq.empty()) return 1;
ii t=pq.top();pq.pop();
if(1ll*t.y*i>t.x) return 0;
t.x+=x;
if(1ll*t.y*(m-1)>t.x) pq.push(t);
}
return 1;
}
int main()
{
scanf("%d%d",&n,&m);
fz1(i,n)scanf("%lld",&a[i]);
fz1(i,n)scanf("%d",&b[i]);
l=-1;r=((long long)2e12)+2;ans=-1;
while(l<r)
{
mid=(l+r+1)/2;
if(check(mid)){r=mid-1;ans=mid;}else l=mid;
}
cout<<ans<<endl;
return 0;
}