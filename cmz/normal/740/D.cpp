#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=4e5+10;
ll a[maxn],fir[maxn],nxt[maxn],gett[maxn],val[maxn];
ll ans[maxn];
ll f[maxn][30],num[maxn][30];
ll n,top;
inline void add(ll x,ll y,ll z){
    gett[++top]=y; val[top]=z; nxt[top]=fir[x]; fir[x]=top;
}
void dfs(ll x,ll fa){
    for (ll i=1;i<=25;i++){
        f[x][i]=f[f[x][i-1]][i-1];
        num[x][i]=num[x][i-1]+num[f[x][i-1]][i-1];
    } 
    for (ll i=fir[x];i;i=nxt[i]){
        ll v=gett[i]; 
        if (v==fa) continue;
        f[v][0]=x; num[v][0]=val[i]; dfs(v,x);
    }
}
void get_ans(ll x,ll fa){
    if (x!=1){
        ll now=x,sum=0;
        for (ll i=25;i>=0;--i){
            if (sum+num[now][i]<=a[x]){
                sum+=num[now][i];
                now=f[now][i];
            }
        }
        now=f[now][0];
        ans[f[x][0]]++;
        ans[now]--;
        // cerr << "DEGUG " << x << ' ' << f[x][0] << ' ' << now << endl;
    }
    for (ll i=fir[x];i;i=nxt[i]){
        ll v=gett[i];
        if (v==fa) continue;
        get_ans(v,x);
    }
}
void diff(ll x,ll fa){
    for (ll i=fir[x];i;i=nxt[i]){
        ll v=gett[i];
        if (v==fa) continue;
        diff(v,x);
        ans[x]+=ans[v];
    }
}
int main(){
    scanf("%I64d",&n);
    for (ll i=1;i<=n;++i) scanf("%I64d",&a[i]);
    for (ll i=2,x,y;i<=n;++i){
        scanf("%I64d%I64d",&x,&y);
        add(i,x,y); add(x,i,y);
    }
    dfs(1,0); 
    get_ans(1,0);
    diff(1,0);
    for (ll i=1;i<=n;++i) printf("%I64d ",ans[i]);
    return 0;
}