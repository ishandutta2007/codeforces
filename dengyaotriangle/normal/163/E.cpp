#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000005;
const int dic=26;

int ps=1,rt=1;
int c[maxn][dic],fail[maxn];
vector<int> adj[maxn];
int id[maxn];
int dfn[maxn],otn[maxn],c1;

int n;
char s[maxn];
bool iin[maxn];

template<typename t,int sz> struct bita{
    static const int bmaxn=sz;t val[bmaxn];bita(){memset(val,0,sizeof(val));}
    inline void chg(int i,t v){while(i<bmaxn){val[i]+=v;i+=i&(-i);}}inline t qry(int i){t ans=0;while(i){ans+=val[i];i-=i&(-i);}return ans;}
};
void dfs(int u){
    dfn[u]=++c1;
    for(int i=0;i<adj[u].size();i++)dfs(adj[u][i]);
    otn[u]=c1;
}

bita<long long,maxn> bit;
int main(){
    int qc;
    ios::sync_with_stdio(0);
    cin>>qc>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int u=rt;
        for(char*p=s;;p++){
            if(*p){
                int w=*p-'a';if(!c[u][w])c[u][w]=++ps;
                u=c[u][w];
            }else{id[i]=u;break;}
        }
    }
    queue<int> q;fail[rt]=rt;
    for(int i=0;i<dic;i++){
        if(c[rt][i]){q.push(c[rt][i]);fail[c[rt][i]]=rt;adj[rt].push_back(c[rt][i]);}
        else c[rt][i]=rt;
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<dic;i++){
            if(c[u][i]){q.push(c[u][i]);fail[c[u][i]]=c[fail[u]][i];adj[fail[c[u][i]]].push_back(c[u][i]);}
            else c[u][i]=c[fail[u]][i];
        }
    }
    dfs(rt);
    for(int i=1;i<=n;i++){
        iin[i]=1;
        bit.chg(otn[id[i]]+1,-1);bit.chg(dfn[id[i]],1);
    }
    while(qc--){
        cin>>s;
        if(s[0]=='+'){
            int i=atoi(s+1);
            if(!iin[i]){
                bit.chg(otn[id[i]]+1,-1);bit.chg(dfn[id[i]],1);
                iin[i]=1;
            }
        }else if(s[0]=='-'){
            int i=atoi(s+1);
            if(iin[i]){
                bit.chg(otn[id[i]]+1,1);bit.chg(dfn[id[i]],-1);
                iin[i]=0;
            }
        }else{
            int u=rt;long long ans=0;
            for(char*p=s+1;*p;p++){
                u=c[u][*p-'a'];
                ans+=bit.qry(dfn[u]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}