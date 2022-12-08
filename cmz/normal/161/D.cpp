#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
using namespace std;
typedef long long ll;
#define MAXN 50006
#define MAXK 506
ll dp[MAXN][MAXK];
struct edge{
    ll u;edge* next;
    edge(ll u=0,edge*next=NULL):u(u),next(next){}
    void insert(ll u){
        if(this->next == NULL) this->next = new edge(u,NULL);
        else this->next = new edge(u,this->next);
    }
}e[MAXN];
ll yn,yk;
ll pre[MAXN];
void dfs(ll u,ll fa){
    dp[u][0] = 1;
    for(edge* n=e[u].next;n!=NULL;n=n->next){
        ll v = n->u;
        if(v == fa) continue;
        pre[v] = u;
        dfs(v,u);
        for(ll k=1;k<=yk;++k)
            dp[u][k] += dp[v][k-1];
    }
}
ll res;
ll kkkkkkkk;
int main(){
    cin >> yn >> yk;
    for(ll i=0;i<yn-1;++i){
        static ll u,v;scanf("%I64d%I64d",&u,&v);
        e[u].insert(v),e[v].insert(u);
    }
    dfs(1,1);
    for(ll i=1;i<=yn;++i){
        ll cur = i,las = i;
        for(ll d = 1;d <= yk;++d){
            cur = pre[cur];
            if(!cur) break;
            dp[i][yk] += dp[cur][yk - d] - (yk==d?0:dp[las][yk-d-1]);
            las = cur;
        }
        res += dp[i][yk];
    }
    cout << res/2;
}