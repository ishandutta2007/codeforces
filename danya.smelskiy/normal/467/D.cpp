#include <bits/stdc++.h>
using namespace std;


map<string,bool> used;
map<int,string> to;
int n,m,all,cl;
map<string,int> fr;
bool used2[500005];
vector<int> v[500005],vv[500005],v1[500005];
vector<int> q;
int col[500005];
int maxkol[500005];
int minlen[500005];
int ans[500005];
string a[500005];

inline string get_lower(string x){
    for (int i=0;i<x.size();++i)
        if (x[i]>='A' && x[i]<='Z') x[i]-=('A'-'a');
    return x;
}
void add(string s){
    if (used[s]) return;
    used[s]=true;
    ++all;
    to[all]=s;
    fr[s]=all;
}
void dfs(int x) {
    used2[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used2[to]==false) dfs(to);
    }
    q.push_back(x);
}
void dfs2(int x,int y){
    col[x]=y;
    used2[x]=true;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (used2[to]==false) dfs2(to,y);
    }
}
inline int get_kol(string s){
    int res=0;
    for (int i=0;i<s.size();++i)
        res+= ( s[i] =='r'  ? 1 : 0);
    return res;
}
void dfs3(int x) {
    used2[x]=true;
    for (int i=0;i<v1[x].size();++i) {
        int to=v1[x][i];
        if (used2[to]==false) dfs3(to);
        if (maxkol[to]<maxkol[x] || (maxkol[to]==maxkol[x] && minlen[to]<minlen[x])) {
            minlen[x]=minlen[to];
            maxkol[x]=maxkol[to];
            ans[x]=ans[to];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]=get_lower(a[i]);
        add(a[i]);
    }
    cin>>m;
    for (int i=1;i<=m;++i) {
        string x,y;
        cin>>x>>y;
        x=get_lower(x);
        y=get_lower(y);
        add(x);
        add(y);
        v[fr[x]].push_back(fr[y]);
        vv[fr[y]].push_back(fr[x]);
    }
    for (int i=1;i<=all;++i)
        if (used2[i]==false) dfs(i);
    reverse(q.begin(),q.end());
    memset(used2,false,sizeof(used2));
    for (int i=0;i<q.size();++i)
        if (used2[q[i]]==false) dfs2(q[i],++cl);
    memset(used2,false,sizeof(used2));
    for (int i=1;i<=cl;++i){
        maxkol[i]=1e9;
        minlen[i]=1e9;
    }
    for (int i=1;i<=all;++i) {
        int x=col[i];
        int kol2=get_kol(to[i]);
        if (kol2<maxkol[x] || (kol2==maxkol[x] && to[i].size()<minlen[x])) {
            minlen[x]=to[i].size();
            maxkol[x]=kol2;
            ans[x]=i;
        }
    }
    for (int i=1;i<=all;++i)
    for (int j=0;j<v[i].size();++j) {
        int to=v[i][j];
        if (col[i]!=col[to]) v1[col[i]].push_back(col[to]);
    }
    for (int i=1;i<=cl;++i)
        if (used2[i]==false) dfs3(i);
    long long ans1=0,ans2=0;
    for (int i=1;i<=n;++i) {
        int x=col[fr[a[i]]];
        ans1+=(long long)maxkol[x];
        ans2+=(long long)minlen[x];
    }
    cout<<ans1<<" "<<ans2;
}