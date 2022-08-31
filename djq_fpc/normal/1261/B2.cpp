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
int n,m,i,j,a[200005],ans[200005],pos[200005],sum[800005];
vector<int> qry[200005];
struct ii{int x,id;}b[200005];
bool cmp(ii x,ii y)
{
	if(x.x!=y.x) return x.x>y.x;
	return x.id<y.id;
}
void update(int x,int l,int r,int y,int c)
{
	sum[x]+=c;
	if(l==r) return;
	int mid=(l+r)/2;
	if(y<=mid) update(x+x,l,mid,y,c); else update(x+x+1,mid+1,r,y,c);
}
int query(int x,int l,int r,int y)
{
	if(l==r){
		return l;
	}
	int mid=(l+r)/2;
	if(sum[x+x]>=y) return query(x+x,l,mid,y);
	return query(x+x+1,mid+1,r,y-sum[x+x]);
}
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		scanf("%d",&a[i]);
		b[i]=(ii){a[i],i};
	}
	sort(b+1,b+n+1,cmp);
	scanf("%d",&m);
	fz1(i,m){
		int x;
		scanf("%d%d",&x,&pos[i]);
		qry[x].push_back(i);
	}
	fz1(i,n){
		update(1,1,n,b[i].id,1);
		ff(qry[i],it){
			ans[*it]=a[query(1,1,n,pos[*it])];
		}
	}
	fz1(i,m){
		printf("%d\n",ans[i]);
	}
	return 0;
}