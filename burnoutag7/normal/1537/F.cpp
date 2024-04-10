#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,d[200005],v[200005];
ll s[2];
vector<int> g[200005];
bool oc;

void dfs(int x,int cd){
    d[x]=cd;
    s[cd&1]+=v[x];
    for(int y:g[x])if(!d[y]){
        dfs(y,cd+1);
    }else if(cd>d[y]+1&&cd-d[y]&1^1){
        oc=true;
    }
}

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        v[i]=t-v[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    oc=false;
    memset(d+1,0,n<<2);
    s[0]=s[1]=0;
    dfs(1,1);
    cout<<(s[0]==s[1]||oc&&(s[0]+s[1])%2==0?"YES\n":"NO\n");
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
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