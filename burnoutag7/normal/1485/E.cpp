#include<bits/stdc++.h>
using namespace std;

int n,m,fa[200005],a[200005];
vector<int> g[200005],lvl[200005];
long long f[200005],h[200005],pre[200005],suf[200005];

void mklvl(int x,int p,int d){
    fa[x]=p;
    lvl[++d].push_back(x);
    m=max(m,d);
    for(int y:g[x])if(y!=p){
        mklvl(y,x,d);
    }
}

void mian(){
    cin>>n;
    m=0;
    for(int i=1;i<=n;i++)g[i].clear(),lvl[i].clear();
    for(int i=2;i<=n;i++){
        int t;
        cin>>t;
        g[t].push_back(i);
        g[i].push_back(t);
    }
    for(int i=2;i<=n;i++)cin>>a[i];
    mklvl(1,-1,0);
    for(int l=m;l>=1;l--){
        vector<int> &cl=lvl[l],v;
        for(int x:cl){
            h[x]=0;
            for(int y:g[x])if(y!=fa[x])h[x]=max(h[x],f[y]);
            v.push_back(x);
        }
        sort(v.begin(),v.end(),[](int x,int y){
            return a[x]<a[y];
        });
        pre[0]=-1e18;
        for(int i=1;i<=v.size();i++){
            int x=v[i-1];
            pre[i]=max(pre[i-1],h[x]-a[x]);
        }
        suf[v.size()+1]=-1e18;
        for(int i=v.size();i>=1;i--){
            int x=v[i-1];
            suf[i]=max(suf[i+1],h[x]+a[x]);
        }
        for(int i=1;i<=v.size();i++){
            int x=v[i-1];
            f[x]=h[x]+max(a[x]-a[v.front()],a[v.back()]-a[x]);
            f[x]=max(f[x],suf[i]-a[x]);
            f[x]=max(f[x],a[x]+pre[i]);
        }
    }
    cout<<f[1]<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}