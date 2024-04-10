#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+ 100;
int fa[maxn];
int n;
vector<pair<int,int> > E1,E0;
int find(int x){
    return x == fa[x]?x:fa[x] = find(fa[x]);
}
int sz0[maxn];
int sz1[maxn];
int sz00[maxn];
int sz11[maxn];
int main(){
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if (w == 0){
            E0.push_back(make_pair(u,v));
        }else{
            E1.push_back(make_pair(u,v));
        }
    }
    for (int i=1;i<=n;i++){
        fa[i] = i;
    }
    for (auto pr : E0){
        int u,v;
        tie(u,v) = pr;
        int fu = find(u);
        int fv = find(v);
        if (fu == fv)continue;
        fa[fu] = fv;
    }
    for (auto pr : E0){
        int u,v;
        tie(u,v) = pr;
        int anc = find(u);
        sz0[anc] ++;
    }
    for (int i=1;i<=n;i++){
        sz00[i] = sz0[find(i)];
    }
    for (int i=1;i<=n;i++){
        fa[i] = i;
    }
    for (auto pr : E1){
        int u,v;
        tie(u,v) = pr;
        int fu = find(u);
        int fv = find(v);
        if (fu == fv)continue;
        fa[fu] = fv;
    }
    for (auto pr : E1){
        int u,v;
        tie(u,v) = pr;
        int anc = find(u);
        sz1[anc] ++;
    }
    for (int i=1;i<=n;i++){
        sz11[i] = sz1[find(i)];
    }
    long long ans = 0;
    for (int i=1;i<=n;i++){
        ans += 1ll * sz00[i] * sz11[i];
        ans += 1ll * sz0[i] * (sz0[i] + 1);
        ans += 1ll * sz1[i] * (sz1[i] + 1);
    }
    cout<<ans<<endl;
    return 0;
}