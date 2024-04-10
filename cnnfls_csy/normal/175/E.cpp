#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,k,nf,ne,ns,a[25];
vector<double> sub;
double rf,re,rs,df,de,ans,sum[105],dp[105][25][25],wf[25],we[25];
double crs(double l,double r,double ll,double rr)
{
    return max(0.0,min(r,rr)-max(l,ll));
}
void calc()
{
    memset(wf,0,sizeof(wf));
    memset(we,0,sizeof(we));
    int i,j,k,x,y; 
    double sum=0;
    sub.clear();
    for (i=1;i<=n;i++)
    {
        wf[i]=rf*2*df;
        we[i]=re*2*de;
        for (j=1;j<=n;j++)
        {
            wf[i]+=crs((i+1)/2-rf,(i+1)/2+rf,(j+1)/2-rs,(j+1)/2+rs)*a[j]*df;
            we[i]+=crs((i+1)/2-re,(i+1)/2+re,(j+1)/2-rs,(j+1)/2+rs)*a[j]*de;
        }
        if (!a[i]) 
        {
            sum+=wf[i];
            sub.push_back(wf[i]-we[i]);
        }
    }
    sort(sub.begin(),sub.end());
    for (i=0;i<ne;i++) sum-=sub[i];
    ans=max(ans,sum);
}
void dfs(int x,int y)
{
    if (x>n)
    {
        if (!y) calc();
        return;
    }
    for (a[x]=0;a[x]<=1&&a[x]<=y;a[x]++)
    {
        dfs(x+1,y-a[x]);
    }
}
int main()
{
    cin>>nf>>ne>>ns>>rf>>re>>rs>>df>>de;
    rf=sqrt(sqr(rf)-1);
    re=sqrt(sqr(re)-1);
    rs=sqrt(sqr(rs)-1); 
    n=nf+ne+ns;
    dfs(1,ns);
    printf("%.10f\n",ans);
    return 0;
}