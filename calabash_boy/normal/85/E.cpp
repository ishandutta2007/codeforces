#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 50;
const int mod = 1e9 + 7;
int n;
pair<int,int> P[maxn];
int vis[maxn];
int ans;
void dfs(int u,int c,int limit){
    vis[u] = c;
    for (int i=1;i<=n;i++){
        int len = abs(P[i].first - P[u].first)
        + abs(P[i].second - P[u].second);
        if (len > limit){
            if (vis[i] == c)throw 1;
            if (vis[i] == 3 - c)continue;
            if (vis[i] == 0)dfs(i,3 - c,limit);
        }
    }
}
bool check(int limit){
    for (int i=1;i<=n;i++)vis[i] = 0;
    ans = 1;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            try{
                dfs(i,1,limit);
            }catch(int err){
                return false;
            }
            ans = ans * 2 % mod;
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        P[i] = make_pair(x,y);
    }
    int l = 0;
    int r = 10000;
    while (r-l > 1){
        int mid = l + r >> 1;
        if (check(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    for (int i=l;i<=r;i++){
        if (check(i)){
            cout<<i<<endl;
            cout<<ans<<endl;
            return 0;
        }
    }
    assert(0);
    return 0;
}