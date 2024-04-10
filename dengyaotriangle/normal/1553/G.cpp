#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n,q;
int a[maxn];

const int maxs=1e6+4;

bool ntp[maxs];
int prm[maxs],prc;
int lpf[maxs],pri[maxs];

const int maxt=maxn+maxs;

vector<int> adj[maxt],bdj[maxt];
int blk[maxt],c1;

void dfs(int u,int c){
    blk[u]=c;
    for(int v:adj[u])if(!blk[v]){
        dfs(v,c);
    }
}
int main(){
    for(int i=2;i<maxs;i++){
        if(!ntp[i]){
            prm[++prc]=i;
            pri[i]=prc;
            lpf[i]=i;
        }
        for(int j=1;i*prm[j]<maxs;j++){
            ntp[i*prm[j]]=1;
            lpf[i*prm[j]]=prm[j];
            if(i%prm[j]==0){
                break;
            }
        }
    }
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int u=a[i];
        while(u!=1){
            int g=lpf[u];
            adj[prc+i].push_back(pri[g]);
            adj[pri[g]].push_back(prc+i);
            u/=g;
        }
    }
    for(int i=1;i<=prc+n;i++){
        if(!blk[i]){
            dfs(i,++c1);
        }
    }
    for(int i=1;i<=n;i++){
        int u=a[i]+1;
        set<int> fk;fk.insert(blk[prc+i]);
        while(u!=1){
            int g=lpf[u];
            fk.insert(blk[pri[g]]);
            u/=g;
        }
        for(int u:fk){
            for(int v:fk)if(u!=v){
                bdj[u].push_back(v);bdj[v].push_back(u);
            }
        }
    }
    for(int i=1;i<=c1;i++)sort(bdj[i].begin(),bdj[i].end());
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=2;
        int f1=blk[prc+u],f2=blk[prc+v];
        if(f1==f2)ans=0;
        else{
            int id=lower_bound(bdj[f1].begin(),bdj[f1].end(),f2)-bdj[f1].begin();
            if(id!=bdj[f1].size()&&bdj[f1][id]==f2){
                ans=1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}