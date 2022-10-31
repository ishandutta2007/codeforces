#include <bits/stdc++.h>
using namespace std;

bool used[300005];
vector<pair<int,int> > v[300005];
vector<int> q;
int a[300005];
int n,m;
int x,y;

void dfs(int x,int y,int z){
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (used[to]) continue;
        dfs(to,x,v[x][i].second);
    }
    if (a[x]) {
        if (y==-1) {
            cout<<"-1";
            exit(0);
        }
        a[y]=1-a[y];
        q.push_back(z);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int sum=0,dd=0;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]==-1) ++dd;
        else sum+=a[i];
    }
    sum%=2;
    if (dd==0 && sum&1) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;++i)
    if (a[i]==-1) {
        if (sum) {
            --sum;
            a[i]=1;
        } else a[i]=0;
    }
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(make_pair(y,i));
        v[y].push_back(make_pair(x,i));
    }
    dfs(1,-1,-1);
    cout<<q.size()<<'\n';
    for (int i=0;i<q.size();++i)
        cout<<q[i]<<'\n';
}