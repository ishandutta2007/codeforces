#include <bits/stdc++.h>
using namespace std;
long long kol,n,x,y,m,ans,a[100][100];
bool used[100];

void dfs(long long i){
    ++kol;
    used[i]=true;
    for (int j=1;j<=n;++j)
        if (a[i][j]==1 && j!=i && used[j]==false) dfs(j);
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    ans=1;
    for (int i=1;i<=n;++i) if (used[i]==false){
        kol=0;
        dfs(i);
            for (int j=1;j<kol;++j)
                ans*=2;
    }
    cout<<ans;
}