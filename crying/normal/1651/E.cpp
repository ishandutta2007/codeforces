#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=3010,INF=1e9;
int n,vis[MAXN];
ll a[MAXN],cur;
vector<int>e[MAXN];
ll ans;
void dfs(int u){
    a[cur++]=u;vis[u]=1;
    for(auto v:e[u])if(!vis[v])dfs(v);
}
int main(){
    cin>>n;
    rep(i,1,2*n){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    rep(i,1,2*n){
        if(vis[i])continue;
        if(!e[i].size())continue;
        cur=0;
        dfs(i);
        ll minL=INF,minR=INF,maxL=0,maxR=0;
        rep(j,0,cur-1){
            if(a[j]<=n)minL=min(minL,a[j]),maxL=max(maxL,a[j]);
            else minR=min(minR,a[j]-n),maxR=max(maxR,a[j]-n);
        }
        ll cnt=minL*(n-maxL+1)*minR*(n-maxR+1);
        ans+=cnt*(cur/2);
        rep(u,0,cur-1){
            ll minL=INF,minR=INF,maxL=0,maxR=0;
            if(a[u]<=n)minL=min(minL,a[u]),maxL=max(maxL,a[u]);
            else minR=min(minR,a[u]-n),maxR=max(maxR,a[u]-n);
            int pos=(u+1)%cur,edge=0;
            while(1){
                if(pos==u)break;
                edge++;
                if(a[pos]<=n)minL=min(minL,a[pos]),maxL=max(maxL,a[pos]);
                else minR=min(minR,a[pos]-n),maxR=max(maxR,a[pos]-n);
                int pre=(u-1+cur)%cur,flag=1;
                ll _minL=0,_minR=0,_maxL=n+1,_maxR=n+1;
                if(a[pre]<=n){
                    if(a[pre]<minL)_minL=max(_minL,a[pre]);
                    else if(a[pre]>maxL)_maxL=min(_maxL,a[pre]);
                    else flag=0;
                }else{
                    if(a[pre]-n<minR)_minR=max(_minR,a[pre]-n);
                    else if(a[pre]-n>maxR)_maxR=min(_maxR,a[pre]-n);
                    else flag=0;
                }
                pre=(pos+1)%cur;
                if(a[pre]<=n){
                    if(a[pre]<minL)_minL=max(_minL,a[pre]);
                    else if(a[pre]>maxL)_maxL=min(_maxL,a[pre]);
                    else flag=0;
                }else{
                    if(a[pre]-n<minR)_minR=max(_minR,a[pre]-n);
                    else if(a[pre]-n>maxR)_maxR=min(_maxR,a[pre]-n);
                    else flag=0;
                }
                if(flag){
                    ll cnt=(minL-_minL)*(_maxL-maxL)*(minR-_minR)*(_maxR-maxR);
                    ans+=cnt*((edge+1)/2);
                }
                pos=(pos+1)%cur;
            }
        }
    }
    cout<<ans;
    return 0;
}