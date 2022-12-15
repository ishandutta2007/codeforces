#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
struct edge{
    int ed,id;
    friend bool operator <(edge a,edge b){
        return a.ed<b.ed||a.ed==b.ed&&a.id<b.id;
    }
};
struct node{
    int id,cnt;
    friend bool operator <(node a,node b){
        return a.cnt>b.cnt||a.cnt==b.cnt&&a.id<b.id;
    }
};
set <edge> s[100005][3];
set <node> pos;
vector <int> v[200005];
int l[200005],r[200005],w[200005],cnt[100005][3],dir[200005];
void dfs(int x,int from,int id){
    //cout<<x<<" "<<from<<" "<<id<<endl;
    if(l[id]==from) dir[id]=1;
    else dir[id]=2;
    s[from][w[id]].erase(edge{x,id});
    s[x][w[id]].erase(edge{from,id});
    if(s[x][3-w[id]].size()) dfs((*s[x][3-w[id]].begin()).ed,x,(*s[x][3-w[id]].begin()).id);
}
void cover(int x){
    for(auto t:v[x]) dir[t]=(l[t]==l[x]||r[t]==r[x])?dir[x]:3-dir[x];
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&l[i],&r[i],&w[i]);
            s[l[i]][w[i]].insert(edge{r[i],i});
            s[r[i]][w[i]].insert(edge{l[i],i});
            cnt[l[i]][w[i]]++,cnt[r[i]][w[i]]++;
        }
        for(int i=1;i<=n;i++) if(cnt[i][1]%2) ans++;
        int tot=m;
        for(int k=1;k<=2;k++) {
            pos.clear();
            for (int i = 1; i <= n; i++) pos.insert(node{i, cnt[i][k]});
            while ((*pos.begin()).cnt > 1) {
                auto temp = *pos.begin();
                //cout<<k<<" "<<temp.id<<" "<<temp.cnt<<" "<<s[temp.id][k].size()<<endl;
                int x = temp.id;
                pos.erase(pos.begin()), pos.insert(node{x, temp.cnt - 2});
                auto t1 = *s[x][k].begin();
                s[x][k].erase(s[x][k].begin());
                auto t2=*s[x][k].begin();
                s[x][k].erase(s[x][k].begin());
                //cout<<k<<" "<<temp.id<<" "<<temp.cnt<<endl;
                s[t1.ed][k].erase(s[t1.ed][k].find(edge{x,t1.id}));
                s[t2.ed][k].erase(s[t2.ed][k].find(edge{x,t2.id}));
                if(t1.ed!=t2.ed) {
                    ++tot;
                    s[t1.ed][k].insert(edge{t2.ed, tot}), s[t2.ed][k].insert(edge{t1.ed, tot});
                    v[tot].push_back(t1.id), v[tot].push_back(t2.id);
                    l[tot] = t1.ed, r[tot] = t2.ed, w[tot]=k;
                }
                else{
                    if(l[t1.id]==l[t2.id]||r[t1.id]==r[t2.id]) dir[t1.id]=1,dir[t2.id]=2;
                    else dir[t1.id]=dir[t2.id]=1;
                    pos.erase(node{t1.ed,int(s[t1.ed][k].size()+2)}),pos.insert(node{t1.ed,int(s[t1.ed][k].size())});
                }
            }
        }
        /*
        for(int i=1;i<=n;i++){
            if(s[i][1].size()&&(*s[i][1].begin()).ed>i) cout<<"1 "<<i<<" "<<(*s[i][1].begin()).ed<<endl;
            if(s[i][2].size()&&(*s[i][2].begin()).ed>i) cout<<"2 "<<i<<" "<<(*s[i][2].begin()).ed<<endl;
        }
         */
        for(int i=1;i<=n;i++){
            if(s[i][1].size()&&!s[i][2].size()) dfs((*s[i][1].begin()).ed,i,(*s[i][1].begin()).id);
            else if(s[i][2].size()&&!s[i][1].size()) dfs((*s[i][2].begin()).ed,i,(*s[i][2].begin()).id);
        }
        for(int i=1;i<=n;i++)
            if(s[i][1].size())
                dfs((*s[i][1].begin()).ed,i,(*s[i][1].begin()).id);
        for(int i=tot;i>m;i--) cover(i);
        printf("%d\n",ans);
        for(int i=1;i<=m;i++) printf("%d",dir[i]);
        puts("");
    }
    return 0;
}
//cf