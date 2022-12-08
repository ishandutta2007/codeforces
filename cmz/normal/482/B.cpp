# include<bits/stdc++.h>
# define int long long
using namespace std;
const int N=1e5+10;
int n,Q,c[31][N],ans[31][N];
struct rec{ int l,r,d; }q[N];
void update(int l,int r,int d)
{
    for (int i=30;i>=0;i--)
        if (d&(1ll<<i)) c[i][l]++,c[i][r+1]--;
}
void init()
{
    for (int i=0;i<=30;i++) for (int j=1;j<=n;j++) c[i][j]=c[i][j-1]+c[i][j];
    for (int i=0;i<=30;i++) for (int j=1;j<=n;j++) c[i][j]=(c[i][j]>0);
    memcpy(ans,c,sizeof(c));
    for (int i=0;i<=30;i++) for (int j=1;j<=n;j++) c[i][j]=c[i][j-1]+c[i][j];
}
bool check(int l,int r,int d)
{
    for (int i=30;i>=0;i--)
     if ((!(d&(1ll<<i)))&&(c[i][r]-c[i][l-1]==r-l+1)) return false;
    return true;
}
signed main()
{
    scanf("%lld%lld",&n,&Q);
    for (int i=1;i<=Q;i++) {
        scanf("%lld%lld%lld",&q[i].l,&q[i].r,&q[i].d);
        update(q[i].l,q[i].r,q[i].d);
    }
    init();
    for (int i=1;i<=Q;i++)
        if (!check(q[i].l,q[i].r,q[i].d)) { puts("NO"); return 0; }
    puts("YES");
    for (int i=1;i<=n;i++) {
        int ret=0;
        for (int j=0;j<=30;j++) if (ans[j][i]) ret+=(1<<j);
        printf("%lld ",ret);
    }
    return 0;
}