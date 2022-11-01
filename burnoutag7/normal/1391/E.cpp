#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[500005];
int dep[500005],fa[500005];
vector<int> lev[500005];

void dfs(const int &x,const int &p,const int &cd){
    fa[x]=p;
    dep[x]=cd;
    lev[dep[x]].emplace_back(x);
    for(int &y:g[x])if(!dep[y]){
        dfs(y,x,cd+1);
    }
}

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)g[i].clear(),lev[i].clear();
    memset(dep+1,0,n<<2);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0,1);
    for(int i=n+1>>1;i<=n;i++){
        if(!lev[i].empty()){
            cout<<"PATH\n";
            cout<<i<<'\n';
            int x=lev[i].front();
            while(x){
                cout<<x<<' ';
                x=fa[x];
            }
            cout<<'\n';
            return;
        }
    }
    cout<<"PAIRING\n";
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=lev[i].size()>>1;
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=0;j+1<lev[i].size();j+=2)cout<<lev[i][j]<<' '<<lev[i][j+1]<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}