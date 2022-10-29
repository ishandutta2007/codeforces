#include<bits/stdc++.h>
using namespace std;
const int N=110020;
struct QU{
    int opt,x,y;
}Q[N];
int n,k,q;
bitset<4096> bit[N];
int a[13][N];
 
bool check(int val,int x,int y)
{
    int mask=0;
    for(int i=1;i<=k;i++) if(a[i][y]>=val) mask|=(1<<(i-1));
    return bit[x][mask];
}
 
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<(1<<k);j++)
        {
            bit[i][j]=((j>>(i-1))&1);
        }
    }
    int tot=k;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&Q[i].opt,&Q[i].x,&Q[i].y);
        if(Q[i].opt==1) bit[++tot]=bit[Q[i].x]|bit[Q[i].y];
        else if(Q[i].opt==2) bit[++tot]=bit[Q[i].x]&bit[Q[i].y];
        else
        {
            int l=1,r=(int)1e9,mid,best;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(check(mid,Q[i].x,Q[i].y)) l=mid+1,best=mid;
                else r=mid-1;
            }
            printf("%d\n",best);
        }
    }
    return 0;
}