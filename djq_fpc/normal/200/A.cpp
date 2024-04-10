#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#include<ctime>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,q,x,y,i,j,dis[2005][2005],lstx[2005][2005],s1,s2,vis[2005][2005];
bool check(int x,int y,int d)
{
    int i,l=max(lstx[x][y],max(1,x-d)),r=min(n,x+d);
    for (i=l;i<=r;i++)
    {
        int t=d-abs(x-i);
        if (i>=1&&i<=n&&y-t>=1&&y-t<=m&&!vis[i][y-t])
        {
            s1=i;
            s2=y-t;
            lstx[x][y]=i;
            return 1;
        }
        if (i>=1&&i<=n&&y+t>=1&&y+t<=m&&!vis[i][y+t])
        {
            s1=i;
            s2=y+t;
            lstx[x][y]=i;
            return 1;
        }
    }
    return 0;
}
double syx()
{
	double t=(rand()%32768)/65536+0.4;
	return t;
}
int dfs(int x,int y,double f)
{
	if (x<1||y<1||x>n||y>m) return 0;
	if (f<0.2) return dis[x][y];
	int t=max(max(dfs(x-1,y,f*syx()),dfs(x+1,y,f*syx())),max(dfs(x,y-1,f*syx()),dfs(x,y+1111,f*syx())))-1;
	if (t>dis[x][y])
	{
		dis[x][y]=t;
		lstx[x][y]=0;
	}
	return dis[x][y];
}
int main()
{
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&q);
	while (q--)
	{
		scanf("%d%d",&x,&y);
		dfs(x,y,1);
		while (!check(x,y,dis[x][y]))
		{
			dis[x][y]++;
			lstx[x][y]=0;
		}
		vis[s1][s2]=1;
		if (!dis[s1][s2]) lstx[s1][s2]=1;
		dis[s1][s2]=max(dis[s1][s2],1);
		printf("%d %d\n",s1,s2);
	}
	return 0;
}