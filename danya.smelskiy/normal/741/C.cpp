#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[200005];
int clr[200005];
bool used[200005];
int a[200005];
int b[200005];

void dfs(int x,int y) {
    clr[x]=y;
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs(to,1-y);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x,y;
        cin>>x>>y;
        a[i]=x; b[i]=y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n+n;i+=2) {
        v[i].push_back(i+1);
        v[i+1].push_back(i);
    }
    for (int i=1;i<=n+n;++i)
        if (!used[i]) dfs(i,0);
    for (int i=1;i<=n;++i) {
        int x=a[i];
        int y=b[i];
        cout<<clr[x]+1<<" "<<clr[y]+1<<'\n';
    }
}