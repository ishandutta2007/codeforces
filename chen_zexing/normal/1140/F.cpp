#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
struct oper{
    long long *pos,old_v;
};
map <pair<int,int>,int> mp;
map <int,pair<int,int>> rev;
vector <int> v[300005];
vector <int> tree[1200005];
int cnt;
long long fa[600005],szx[600005],szy[600005];
long long ans;
int find(int x){
    return fa[x]==x?x:find(fa[x]);
}
void cover(int node,int l,int r,int L,int R,int id){
    if(l>=L&&r<=R){
        tree[node].push_back(id);
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=L) cover(node*2,l,mid,L,R,id);
    if(mid<R) cover(node*2+1,mid+1,r,L,R,id);
}
void dfs(int node,int l,int r){
    stack <oper> stk;
    for(int i=0;i<tree[node].size();i++){
        int x=find(rev[tree[node][i]].first),y=find(rev[tree[node][i]].second);
        if(szx[x]+szy[x]<szx[y]+szy[y]) swap(x,y);
        if(x!=y) {
            stk.push(oper{&ans, ans}), ans -= szx[x] * szy[x] + szx[y] * szy[y];
            stk.push(oper{&szx[x], szx[x]}), stk.push(oper{&szy[x], szy[x]});
            szx[x] += szx[y], szy[x] += szy[y];
            stk.push(oper{&fa[y], fa[y]}), fa[y] = x;
            stk.push(oper{&ans, ans}), ans += szx[x] * szy[x];
        }
        //cout<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<szx[x]<<" "<<szy[x]<<" "<<ans<<endl;
    }
    int mid=(l+r)/2;
    if(l==r){
        printf("%lld ",ans);
    }
    else dfs(node*2,l,mid),dfs(node*2+1,mid+1,r);
    while(!stk.empty()) *(stk.top().pos)=stk.top().old_v,stk.pop();
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=600000;i++) i>300000?szy[i]=1:szx[i]=1,fa[i]=i;
        for(int i=1,x,y;i<=n;i++){
            scanf("%d%d",&x,&y);
            y+=300000;
            if(!mp[make_pair(x,y)]) mp[make_pair(x,y)]=++cnt,rev[cnt]=make_pair(x,y);
            v[mp[make_pair(x,y)]].push_back(i);
        }
        for(int i=1;i<=cnt;i++){
            if(v[i].size()%2) v[i].push_back(n+1);
            for(int j=0;j<v[i].size();j+=2) cover(1,1,n,v[i][j],v[i][j+1]-1,i);
        }
        dfs(1,1,n);
    }
    return 0;
}
//
/// 
//01
//