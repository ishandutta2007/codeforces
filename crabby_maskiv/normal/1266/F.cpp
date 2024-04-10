#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+5;
vector<pii> g[N];
int fa[N];
int f0[N],f1[N];
void dfs1(int u){
    for(auto e:g[u]){
        int v=e.sc;
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        f0[u]=max(f0[u],f0[v]+1);
    }
}
void dfs2(int u){
    int mx=-1e9,i;
    for(i=0;i<(int)g[u].size();i++){
        int v=g[u][i].sc;
        if(v==fa[u]) continue;
        f1[v]=max(f1[v],f1[u]+1);
        f1[v]=max(f1[v],mx+2);
        mx=max(mx,f0[v]);
    }
    mx=-1e9;
    for(i=(int)g[u].size()-1;i>=0;i--){
        int v=g[u][i].sc;
        if(v==fa[u]) continue;
        f1[v]=max(f1[v],mx+2);
        mx=max(mx,f0[v]);
    }
    for(auto e:g[u]){
        int v=e.sc;
        if(v==fa[u]) continue;
        dfs2(v);
    }
}
int n,m;
int ans1[N],ans2[N],ans[N];
int cnt[N];
vector<int> add[N],del[N];
priority_queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j,k;
    cin>>n;
    for(i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].pb(mkp(0,v));
        g[v].pb(mkp(0,u));
    }
    dfs1(1);
    dfs2(1);
    for(i=1;i<=n;i++){
        m=g[i].size();
        for(j=0;j<m;j++){
            int v=g[i][j].sc;
            if(v==fa[i]) g[i][j].fr=f1[i];
            else g[i][j].fr=f0[v]+1;
        }
        sort(g[i].begin(),g[i].end());
        //cerr<<"u = "<<i<<endl;
        //for(j=0;j<m;j++) cerr<<g[i][j].sc<<" "<<g[i][j].fr<<endl;
        for(j=m-2;j>=0;j--){
            if(g[i][j].fr==g[i][j+1].fr) ans1[g[i][j].fr-1]=max(ans1[g[i][j].fr-1],m-j);
            else ans1[g[i][j].fr]=max(ans1[g[i][j].fr],m-j);
        }
        for(j=m-1;j>=0;j--)
            ans2[g[i][j].fr]=max(ans2[g[i][j].fr],m-j);
    }
    for(i=1;i<=n;i++){
        m=g[i].size();
        for(j=0;j<=m;j++){
            add[j].clear();
            del[j].clear();
        }
        for(j=0;j<m;j++){
            int v=g[i][j].sc;
            if(v==fa[i]) continue;
            int c=0,m1=g[v].size();
            for(k=m1-1;k>=0;k--){
                if(g[v][k].sc==i) continue;
                int w=g[v][k].fr;
                c++;
                int ps=lower_bound(g[i].begin(),g[i].end(),mkp(w,0))-g[i].begin();
                ans2[w]=max(ans2[w],c+m-ps-(ps<=j));
                if(ps<=j){
                    add[0].pb(c-1);
                    del[ps].pb(c-1);
                }
                else{
                    add[0].pb(c-1);
                    del[j+1].pb(c-1);
                    add[j+1].pb(c);
                    del[ps].pb(c);
                }
            }
        }
        for(j=0;j<=m;j++){
            for(auto x:add[j]){
                cnt[x]++;
                q.push(x);
            }
            for(auto x:del[j]) cnt[x]--;
            while(!q.empty()&&!cnt[q.top()]) q.pop();
            if(!q.empty()) ans2[g[i][j].fr]=max(ans2[g[i][j].fr],q.top()+m-j);
        }
    }
    for(i=n;i;i--) ans1[i]=max(ans1[i],ans1[i+1]);
    for(i=n;i;i--) ans2[i]=max(ans2[i],ans2[i+1]);
    //cerr<<"ans1[2] = "<<ans1[2]<<endl;
    for(i=1;i*2+1<=n;i++) ans[i*2+1]=ans1[i];
    for(i=1;i*2<=n;i++) ans[i*2]=ans2[i];
    for(i=1;i<=n;i++) ans[1]=max(ans[1],(int)g[i].size()+1);
    for(i=1;i<=n;i++) cout<<max(ans[i],1)<<" ";
    return 0;
}