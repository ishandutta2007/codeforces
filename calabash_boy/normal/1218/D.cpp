#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int MOD = 1000000007;
const int INV2 = (MOD+1)>>1;
const int N = 17;
template <class type>
void FWT(vector<type> &a ,int n,int r){
    for (int i=1;i<n;i<<=1){
        for (int j=0;j<n;j+=(i<<1)){
            for (int k =0;k<i;k++){
                int x = a[j+k];int y = a[j+k+i];
                if (r){
                    a[j+k] = (x+y)%MOD;
                    a[j+k+i] = (x-y+MOD)%MOD;
                }else{
                    a[j+k] = 1LL*(x+y)*INV2%MOD;
                    a[j+k+i] = 1LL*(x-y+MOD)*INV2%MOD;
                }
            }
        }
    }
}
pair<int,int>  father[maxn];
int flag[maxn];
vector<pair<int,int> > E[maxn];
set<tuple<int,int,int> > non_tree_edges;
bool used[maxn];
void dfs(int u,int fa,int w){
    father[u] = make_pair(fa,w);
    used[u] = 1;
    for (auto edge : E[u]){
        int v,w;
        tie(v,w) = edge;
        if (v == fa)continue;
        if (!used[v])dfs(v,u,w);
        else non_tree_edges.insert(make_tuple(min(u,v),max(u,v),w));
    }
}
vector<int> get_vec(int u,int v,int w){
    memset(flag,0,sizeof flag);
    int now = u;
    while (now){
        flag[now] |= 1;
        now = father[now].first;
    }
    now = v;
    while (now){
        flag[now] |= 2;
        now = father[now].first;
    }
    vector<int> vec(1<<N,0);
    vec[w] ++;
    now = u;
    while (flag[now] != 3){
        vec[father[now].second] ++;
        now = father[now].first;
    }
    now = v;
    while (flag[now] != 3){
        vec[father[now].second] ++;
        now = father[now].first;
    }
    return vec;
}
bool check(vector<int> & a, int prefix,int low){
    for (int mask = 0;mask < (1<<low);mask ++){
        if (a[prefix + mask])return true;
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E[u].push_back(make_pair(v,w));
        E[v].push_back(make_pair(u,w));
        sum ^= w;
    }
    dfs(1,0,0);
    vector<int> a(1<<N,0);
    vector<int> b(1<<N,0);
    a[0] = 1;
    b[0] = 1;
    FWT(a, 1<<N, 1);
    for (auto edge: non_tree_edges){
        int u,v,w;
        tie(u,v,w) = edge;
        vector<int> vec = get_vec(u, v, w);
        FWT(vec, 1<<N, 1);
        for (int i=0;i< (1<<N);i++){
            a[i] = 1ll * a[i] * vec[i] % MOD;
        }
        FWT(b,1<<N,1);
        for (int i=0;i<(1<<N);i++){
            b[i] = 1ll * b[i] * vec[i] % MOD;
        }
        FWT(b,1<<N,0);
        for (int i=0;i<(1<<N);i++){
            b[i] = b[i] != 0;
        }
    }
    FWT(a, 1<<N, 0);
    int ans = 0;
    for (int i=N-1;i>=0;i--){
        int bit = sum & (1<<i);
        if (check(b,ans + bit, i)){
            ans += bit;
        }else{
            ans += (bit ^ (1<<i));
        }
    }
    cout<<(ans ^ sum )<<" "<<a[ans]<<endl;
    return 0;
}