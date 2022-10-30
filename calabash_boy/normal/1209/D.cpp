#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int fa[maxn];
int find(int x){
    return fa[x] == x?x : fa[x] = find(fa[x]);
}
int n,m;
int main(){
    int ans = 0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)fa[i] = i;
    while (m--){
        int u,v;
        cin>>u>>v;
        int fu = find(u);
        int fv = find(v);
        if (fu == fv){
            ans ++;
        }else{
            fa[fu] = fv;
        }
    }
    cout<<ans<<endl;
    return 0;
}