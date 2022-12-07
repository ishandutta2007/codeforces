#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;
#define ll long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second

const int N=300100;
struct node{
    node* g[26];
    void clear(){memset(g,0,sizeof(g));}
}pool[N*10],*cur=pool,*rt[N];
stack<node*>tras;
int sz[N],c[N],diff[N],n,u,v;
vector<int>son[N],g[N];
char s[N];

node *newnode(){
    if(tras.empty()){
        node *p=cur++;
        return p;
    }
    node *p=tras.top();
    p->clear();
    tras.pop();
    return p;
}

void DFS(node *a,node *b,int &sz){
    FOR(i,0,25)
        if (b->g[i]!=0){
            if(!a->g[i]) a->g[i]=newnode(),sz++;
            DFS(a->g[i],b->g[i],sz);
        }
}
bool cmp(int a,int b){return sz[a]>sz[b];}
void dfs(int t,int f){
    sz[t]=1;
    FOR(i,0,(int)g[t].size()-1)
        if(g[t][i]!=f){
            dfs(g[t][i],t);
            sz[t]+=sz[g[t][i]];
            son[t].pb(g[t][i]);
        }
    if(sz[t]==1){
        rt[t]=newnode();
        diff[t]=1;
        rt[t]->g[s[t]-'a']=newnode();
        return;
    }
    sort(son[t].begin(),son[t].end(),cmp);
    rt[t]=rt[son[t][0]];diff[t]=diff[son[t][0]];
    FOR(i,1,(int)son[t].size()-1) DFS(rt[t],rt[son[t][i]],diff[t]);
    node *p=newnode(); diff[t]++; p->g[s[t]-'a']=rt[t];
    rt[t]=p;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n)scanf("%d",c+i);
    scanf("%s",s+1);
    FOR(i,1,n-1)scanf("%d%d",&u,&v),g[u].pb(v),g[v].pb(u);
    dfs(1,0);
    int ans=0,cnt=0;
    FOR(i,1,n){
        if(diff[i]+c[i]>ans) cnt=0;
        if(diff[i]+c[i]>=ans) cnt++,ans=diff[i]+c[i];
    }
    printf("%d\n%d\n",ans,cnt); 
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/