#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int maxn = 100010;
map<string,int> mp;
int idx;
int val[maxn];
vector<int> edge[maxn];
vector<pair<int,int> > W[maxn];
vector<int> root;
int d[maxn];
int L[maxn],R[maxn],dfn;
void dfs(int u,int dep)
{
    L[u] = ++dfn;
    d[u] = dep + 1;
    W[d[u]].push_back(make_pair(L[u],u));
    for(int i=0;i<edge[u].size();i++)
    {
        dfs(edge[u][i],dep+1);
    }
    R[u] = ++dfn;
}
struct Query {
    int id,l,r;
    Query(){}
    Query(int idx,int L,int R) : id(idx),l(L),r(R){ }
    bool operator  < (const Query & cmp) const {
        return r < cmp.r;
    }
};
vector<Query> QY[maxn];
int totq;
int ans[maxn];
set<int> st;
int m;
void init()
{
     int v,k;
     scanf("%d",&m);
     for(int i=0;i<m;i++)
     {
         scanf("%d%d",&v,&k);
         int dd = d[v] + k;
         int left = lower_bound(W[dd].begin(),W[dd].end(),make_pair(L[v],0)) - W[dd].begin(); 
         int right = lower_bound(W[dd].begin(),W[dd].end(),make_pair(R[v],0)) - W[dd].begin();
         if(left == right ) {  ans[i] = 0; continue;   }
         QY[dd].push_back (  Query(i,left,right) );
         st.insert(dd);
     }
}
int c[maxn];
map<int,int> pos;
int sz;
void update(int x,int d){
    for( ; x <= sz ; x+= x&-x) c[x]+=d;
}
int sum(int x){
    int ans = 0;
    for(; x ; x -= x&-x) ans += c[x];
    return ans;
}
void solve()
{
    for(set<int>::iterator it = st.begin();it!=st.end();it++)
    {
        sort(QY[*it].begin(),QY[*it].end());
        int pt = 1;
        memset(c,0,sizeof(c));
        pos.clear();
        sz = W[*it].size();
      //  printf("sz=%d\n",sz);
        for(int i=0;i<QY[*it].size();i++)
        {
            int left = QY[*it][i].l;
            int right = QY[*it][i].r;
            left++;
            while(pt <= right)
            {
                int & p = pos[val[W[*it][pt-1].second]] ;
                if(p != 0) update(p,-1);
                update(pt,1);
            //    printf("p=%d pt=%d\n",p,pt);
                p = pt;
                pt ++;
            }
            ans[QY[*it][i].id] = sum(right) - sum(left-1);
        }
    }
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
}
int main()
{
    int n,r;
    char s[25];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d",s,&r);
        if(!mp[s]) mp[s] = ++ idx ;
        val[i] = mp[s];
        if(r==0) {
            root.push_back(i);
        } else {
            edge[r].push_back(i);
        }
    }
    for(int i=0;i<root.size();i++) dfs(root[i],0);
    init();
    solve();
    return 0;
}