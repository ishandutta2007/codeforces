#include <bits/stdc++.h>
using namespace std;

int n,m,timer;
int pred[100005][19];
vector<int> v[100005];
int tin[100005],tout[100005];
long double kol[100005],dd[100005],du[100005];
long double h[100005];
int x,y;
void dfs(int x,int y){
    tin[x]=++timer;
    pred[x][0]=y;
    for (int i=1;i<=18;++i)
        pred[x][i]=pred[pred[x][i-1]][i-1];
    h[x]=h[y]+1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        kol[x]+=kol[to]+1;
        dd[x]+=dd[to]+kol[to]+1;
    }
    tout[x]=++timer;
}
void dfs2(int x,int y){
    if (y!=0) {
        du[x]=du[y];
        du[x]-=dd[x]+kol[x]+1;
        du[x]+=kol[1]-kol[x];
    }
    du[x]+=dd[x];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs2(to,x);
    }
    du[x]-=dd[x];
}
inline bool check(int x,int y){
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
int get_lca(int x,int y){
    if (check(x,y)) return x;
    if (check(y,x)) return y;
    for (int i=18;i>=0;--i)
        if (pred[x][i] && check(pred[x][i],y)==false) x=pred[x][i];
    return pred[x][0];
}
int get_lca2(int x,int y){
    swap(x,y);
    for (int i=18;i>=0;--i)
        if (pred[x][i] && check(pred[x][i],y)==false) x=pred[x][i];
    return x;
}
inline long double solve1(int x,int y){
    long double res;
    int c=get_lca2(x,y);
//    cout<<"<"<<x<<" "<<y<<" "<<c<<'\n';
    res=dd[y]*(kol[1]-kol[c])+(du[x]+dd[x]-dd[c]-kol[c]-1.)*(kol[y]+1.);
    res/=(kol[y]+1.)*(kol[1]-kol[c]);
    res++;
    res+=((h[y]-h[x]));
    return res;
}
inline long double solve(int x,int y){
    if (h[x]>h[y]) swap(x,y);
    if (check(x,y)) { return solve1(x,y); }
    long double res=0;
    int c=get_lca(x,y);
    res+=dd[x]*(kol[y]+1.)+dd[y]*(kol[x]+1.);
    res/=(kol[x]+1.)*(kol[y]+1);
    res+=h[x]-h[c]+h[y]-h[c];
    ++res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<fixed<<setprecision(9);
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<'\n';
    }
}