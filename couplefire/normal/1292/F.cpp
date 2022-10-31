#include <bits/stdc++.h>
using namespace std;

const int N = 65, M = 15, MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, arr[N], fa[N], comb[N][N], in[N], to[N], f[1<<M], g[1<<M][N], ans = 1, cur;
vector<int> comps[N];

int find(int v){return v==fa[v]?v:fa[v]=find(fa[v]);}

void unite(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    fa[u] = v;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; iota(fa, fa+n, 0);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    sort(arr, arr+n);
    for(int i = 0; i<n; ++i)
        for(int j = i+1; j<n; ++j)
            if(arr[j]%arr[i]==0)
                unite(i, j), in[j]++;
    for(int i = 0; i<n; ++i)
        comps[find(i)].push_back(i);
    comb[0][0] = 1;
    for(int i = 1; i<=n; ++i){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j<i; ++j)
            comb[i][j] = add(comb[i-1][j-1], comb[i-1][j]);
    }
    for(int _ = 0; _<n; ++_) if(comps[_].size()>1){
        vector<int>& c = comps[_]; vector<int> s;
        for(auto x : c)
            if(!in[x]) s.push_back(x);
        int m = s.size(), cnt = c.size()-s.size();
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for(auto x : c) if(in[x]){
            for(int i = 0; i<m; ++i)
                if(arr[x]%arr[s[i]]==0) to[x] ^= (1<<i);
            inc(f[to[x]], 1);
        }
        for(int i = 0; i<m; ++i)
            for(int mask = 0; mask<(1<<m); ++mask)
                if(mask&(1<<i)) inc(f[mask], f[mask^(1<<i)]);
        g[0][0] = 1;
        for(int mask = 0; mask<(1<<m); ++mask){
            for(int i = 0; i<=cnt; ++i){
                if(!g[mask][i]) continue;
                if(f[mask]>i) inc(g[mask][i+1], mul(f[mask]-i, g[mask][i]));
                for(int j = 0; j<m+cnt; ++j)
                    if(in[c[j]] && (to[c[j]]&mask)!=to[c[j]] && ((to[c[j]]&mask) || mask==0))
                        inc(g[mask|to[c[j]]][i+1], g[mask][i]);
            }
        }
        grow(ans, mul(g[(1<<m)-1][cnt], comb[cur+=cnt-1][cnt-1]));
    }
    cout << ans << '\n';
}