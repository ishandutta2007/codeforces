#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;
const int INF = 1000000007;

int n, q;
int up[N][20], permu[N], dep[N], cnt[N], val[N], arr[N], brr[N], dist[N], ans;
bool vis[N];
stack<int> sta;
set<int> st;

int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 0; i<20; i++)
        if((dep[u]-dep[v])&(1<<i)) u = up[u][i];
    if(u == v) return u;
    for(int i = 19; i>=0; i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
            return up[u][0];
}

int DIST(int u, int v){
    return dist[u]+dist[v]-2*dist[LCA(u, v)];
}

void add(int x){
    auto it = st.insert(x).first;
    int l = *prev(it), r = *(next(it)==st.end()?st.begin():next(it));
    ans += DIST(l, x)+DIST(r, x)-DIST(l, r);
}

void del(int x){
    auto it = st.find(x);
    int l = *prev(it), r = *(next(it)==st.end()?st.begin():next(it));
    ans -= DIST(l, x)+DIST(r, x)-DIST(l, r);
    st.erase(it);
}

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q; sta.push(0); permu[0] = INF;
    for(int i = 1; i<=n; i++){
        cin >> permu[i];
        while(sta.size() && permu[sta.top()] < permu[i]) sta.pop();
        up[i][0] = sta.top(); dep[i] = dep[up[i][0]]+1;
        for(int j = 1; j<20; j++)
            up[i][j] = up[up[i][j-1]][j-1];
        sta.push(i);
    }
    for(int i = 1; i<=n; i++)
        cin >> arr[i], val[i] += arr[i];
    for(int i = 1; i<=n; i++)
        cin >> brr[i], val[i] -= brr[i], val[up[i][0]] += brr[i];
    for(int i = n; i>=1; i--)
        dist[up[i][0]] += min(0ll, dist[i]+=val[i]), dist[i] = max(0ll, dist[i]);
    dist[0] += val[0];
    for(int i = 1; i<=n; i++)
        dist[i] += dist[up[i][0]];
    cnt[0] = 1; st.insert(0);
    while(q--){
        int x; cin >> x;
        if(vis[x]){
            vis[x] = 0;
            if(!(--cnt[up[x][0]]))
                del(up[x][0]);
        } else{
            vis[x] = 1;
            if(!(cnt[up[x][0]]++))
                add(up[x][0]);
        }
        cout << ans/2+dist[0] << '\n';
    }
}