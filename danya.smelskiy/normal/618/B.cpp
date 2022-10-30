#include <bits/stdc++.h>
using namespace std;


int n;
int a[55][55];
int ans[55];
bool used[55];

inline bool f(int x,int y){
    for (int i=1;i<=n;++i)
        if (a[x][i] && a[x][i]!=y) return false;
    return true;
}
inline void del(int x,int y){
    used[x]=true;
    ans[x]=y;
    for (int i=1;i<=n;++i)
        a[x][i]=a[i][x]=0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
    if (used[j]==false && f(j,i)) { del(j,i); break; }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}