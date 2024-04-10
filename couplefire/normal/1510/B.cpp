#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

int d, n, mt[2*N], mask[N], ans;
pair<int, int> tmp[N];
vector<int> adj[2*N];
bool vis[2*N];

bool try_kuhn(int v){
    if(vis[v]) return 0;
    vis[v] = 1;
    for(auto u : adj[v])
        if(mt[u] == -1 || try_kuhn(mt[u])){
            mt[u] = v;
            return 1;
        }
    return 0;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<d; j++)
            mask[i] += (1<<j)*(s[j]-'0');
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j) continue;
            if((mask[j]&mask[i]) == mask[i])
                adj[i].push_back(j+n);
        }
    }
    for(int i = 0; i<n; i++)
        tmp[i] = {-__builtin_popcount(mask[i]), i};
    sort(tmp, tmp+n);
    memset(mt, -1, sizeof mt);
    for(int i = 0; i<n; i++){
        memset(vis, 0, sizeof vis);
        try_kuhn(tmp[i].second);
    }
    for(int i = n; i<2*n; i++)
        if(mt[i] != -1) mt[mt[i]] = i-n;
    set<int> st;
    for(int i = 0; i<n; i++)
        if(mt[i] != -1){
            auto it = st.find(mt[i]);
            assert(it == st.end());
            st.insert(mt[i]);
        }
    for(int i = 0; i<n; i++)
        if(mt[i] != -1)
            assert((mask[mt[i]]&mask[i]) == mask[i] && mask[mt[i]] != mask[i]);
    for(int i = 0; i<n; i++)
        if(mt[i] == -1) ans += __builtin_popcount(mask[i])+1;
    cout << ans-1 << endl;
    int cnt = 0;
    for(int i = 0; i<n; i++) vis[i] = 0;
    int tt = 0;
    for(int i = 0; i<n; i++){
        if(vis[i] || mt[i+n] != -1) continue;
        if(cnt) cout << "R ";
        int cur = i;
        int bruh = 0;
        int huh = 0;
        while(cur != -1){
            // assert(!vis[cur]);
            // cout << cur << endl;
            assert(cur < n);
            assert((mask[cur]&bruh) == bruh);
            for(int j = 0; j<d; j++)
                if((mask[cur]&(1<<j))&&!(bruh&(1<<j))){
                    bruh ^= (1<<j);
                    cout << j << " ";
                    huh++;
                }
            assert(bruh == mask[cur]);
            if(mt[cur] == -1) tt += __builtin_popcount(mask[cur])+1;
            vis[cur] = 1, cur = mt[cur];
        }
        cout << endl;
        assert(huh == __builtin_popcount(bruh));
        cnt++;
    }
    cout << endl;
    st.clear();
    for(int i = 0; i<n; i++)
        if(mt[i] != -1){
            auto it = st.find(mt[i]);
            assert(it == st.end());
            st.insert(mt[i]);
        }
    // for(int i = 0; i<n; i++)
    //     if(mt[i] != -1) cout << i << " " << mt[i] << endl;
    // if(ans == 138) cout << tt << " " << ans << endl;
}