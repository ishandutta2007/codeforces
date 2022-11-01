#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,tot;
vector<pair<int,int> > g[1000005],rg[1000005],ng[1000005];
vector<int> vs;
bool u[1000005];
int cmp[1000005];
ll wt[1000005];
ll dp[1000005];
int pre[20005];
ll pp[20005];

ll calc(int x){
    int pos=lower_bound(pre,pre+20001,x)-pre;
    return (ll)x*(pos+1)-pp[pos]+(pre[pos]-x);
}

void ndfs(int x){
    u[x]=1;
    for(pair<int,int> &y:g[x])if(!u[y.first])ndfs(y.first);
    vs.push_back(x);
}

void rdfs(int x,int k){
    u[x]=1;
    cmp[x]=k;
    for(pair<int,int> &y:rg[x])if(!u[y.first])rdfs(y.first,k);
}

ll dfs(int x){
    ll &res=dp[x];
    if(res)return res;
    for(pair<int,int> &y:ng[x]){
        res=max(res,dfs(y.first)+y.second);
    }
    return res+=wt[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=20000;i++){
        pre[i]=pre[i-1]+i;
        pp[i]=pp[i-1]+pre[i];
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        rg[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++)if(!u[i])ndfs(i);
    memset(u,0,sizeof(u));
    for(int i=n-1;i>=0;i--)if(!u[vs[i]])rdfs(vs[i],++tot);
    for(int x=1;x<=n;x++){
        for(pair<int,int> &y:g[x]){
            if(cmp[x]==cmp[y.first])wt[cmp[x]]+=calc(y.second);
            else ng[cmp[x]].push_back(make_pair(cmp[y.first],y.second));
        }
    }
    int src;
    cin>>src;
    cout<<dfs(cmp[src])<<endl;

    return 0;
}