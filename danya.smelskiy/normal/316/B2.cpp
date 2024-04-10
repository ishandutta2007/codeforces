#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005];
bool used[1005];
int b[1005];
int kol,kol2;
vector<int> v[1005];
void dfs(int x){
    used[x]=true;
    ++kol2;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs(to);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]) {
            v[i].push_back(a[i]);
            v[a[i]].push_back(i);
        }
    }
    int kol=0;
    int z=m;
    while (z) {
        ++kol;
        z=a[z];
    }
    int kol3=kol;
    kol=0;
    dfs(m);
    for (int i=1;i<=n;++i)
    if (used[i]==false) {
        kol2=0;
        dfs(i);
        b[++kol]=kol2;
    }
    for (int i=0;i<=n;++i)
    used[i]=false;
    used[0]=true;
    for (int i=1;i<=kol;++i) {
        for (int j=n;j>=b[i];--j)
            if (used[j-b[i]]) used[j]=true;
    }
    for (int i=0;i<=n;++i)
        if (used[i]) cout<<i+kol3<<'\n';
}