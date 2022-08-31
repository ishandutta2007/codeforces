#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cassert>
#include<set>
#include<iomanip>
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
#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,q,x,y,vis[4005][4005],l,r,mid,ans;
struct bit_2d{T_ a[4005][4005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=4000;i+=lowbit(i)){for (j=y;j<=4000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
bit_2d c;
pair<int,int> queryx(int x,int ly,int ry)
{
    if (c.query(x,ly,x,ry)==(ry-ly+1)) return make_pair((1<<25),(1<<25));
    int l=ly-1,r=ry,mid,y=30000;
    while (l<r)
    {
        mid=(l+r+1)/2;
        if (c.query(x,ly,x,mid)<mid-ly+1)
        {
            r=mid-1;
            y=mid;
        }
        else l=mid;
    }
    int tx=(x+y-2000)/2;
    int ty=x-tx;
    return make_pair(tx,ty);
}
pair<int,int> queryy(int y,int lx,int rx)
{
    if (c.query(lx,y,rx,y)==(rx-lx+1)) return make_pair((1<<25),(1<<25));
    int l=lx-1,r=rx,mid,x=30000;
    while (l<r)
    {
        mid=(l+r+1)/2;
        if (c.query(lx,y,mid,y)<mid-lx+1)
        {
            r=mid-1;
            x=mid;
        }
        else l=mid;
    }
    int tx=(x+y-2000)/2;
    int ty=x-tx;
    return make_pair(tx,ty);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    fz1(i,4000) fz1(j,4000) if ((i+j)&1) vis[i][j]=c.a[i][j]=1;
    else
    {
        int tx=(i+j-2000)/2;
        int ty=i-tx;
        if (tx<1||tx>n||ty<1||ty>m) vis[i][j]=c.a[i][j]=1;
    }
    fz1(i,4000) fz1(j,4000)
    {
        if (i+c.lowbit(i)<=4000) c.a[i+c.lowbit(i)][j]+=c.a[i][j];
    }
    fz1(i,4000) fz1(j,4000)
    {
        if (j+c.lowbit(j)<=4000) c.a[i][j+c.lowbit(j)]+=c.a[i][j];
    }
//	fz1(i,4000) fz1(j,4000) c.a[i][j]+=c.a[i-c.lowbit(i)][j]+c.a[i][j-c.lowbit(j)]-c.a[i-c.lowbit(i)][j-c.lowbit(j)];
    while (q--)
    {
        scanf("%d%d",&x,&y);
        if (!vis[x+y][x-y+2000])
        {
            vis[x+y][x-y+2000]=1;
            c.add(x+y,x-y+2000,1);
            printf("%d %d\n",x,y);
            continue;
        }
        l=0;r=4000;ans=2001;
        int tx=x+y,ty=x-y+2000;
        while (l<r)
        {
            mid=(l+r+1)/2;
            int lx=max(tx-mid,1),ly=max(ty-mid,1),rx=min(tx+mid,4000),ry=min(ty+mid,4000);
            if (c.query(lx,ly,rx,ry)==(rx-lx+1)*(ry-ly+1))
            {
                l=mid;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        mid=ans;
        int lx=max(tx-mid,1),ly=max(ty-mid,1),rx=min(tx+mid,4000),ry=min(ty+mid,4000);
        pair<int,int> res=min(min(queryx(lx,ly,ry),queryx(rx,ly,ry)),min(queryy(ly,lx,rx),queryy(ry,lx,rx)));
        x=res.first;y=res.second;
        tx=x+y;ty=x-y+2000;
        vis[tx][ty]=1;
        c.add(tx,ty,1);
        printf("%d %d\n",x,y);
    }
    return 0;
}