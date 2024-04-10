#include <bits/stdc++.h>
using namespace std;

const int kMaxLog = 20;

int n, m;
vector<vector<int> > g;
vector<vector<int> > up;
vector<int> tin, tout, height;
int cur_time;

void PreCalcForLCA(int v, int pr)
{
    if (pr == -1) {
        for (int i = 0; i < kMaxLog; ++i) {
            up[v][i] = v;
        }
        height[v] = 0;
    } else {
        up[v][0] = pr;
        for (int i = 1; i < kMaxLog; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        height[v] = height[pr] + 1;
    }
    tin[v] = cur_time;
    ++cur_time;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            PreCalcForLCA(u, v);
        }
    }    
    tout[v] = cur_time;
    ++cur_time;
}

inline bool IsParent(int par, int v)
{
    return tin[par] <= tin[v] && tout[par] >= tout[v];
}

inline int GetLCA(int v1, int v2)
{
    if (IsParent(v1, v2)) {
        return v1;
    }
    if (IsParent(v2, v1)) {
        return v2;
    }
    for (int i = kMaxLog - 1; i >= 0; --i) {
        if (!IsParent(up[v1][i], v2)) {
            v1 = up[v1][i];
        }
    }
    return up[v1][0];
}

inline int GetDist(int v1, int v2)
{
    int l = GetLCA(v1, v2);
    if (l == v2) {
        return height[v1] - height[v2];
    } else if (l == v1) {
        return height[v2] - height[v1];
    } else {
        return height[v1] - height[l] + height[v2] - height[l];
    }
}

vector<vector<int> > centroids;
vector<int> dist_to_red;

void Update(int v)
{
    for (int i = 0; i < (int) centroids[v].size(); ++i) {
        int u = centroids[v][i];
        dist_to_red[u] = min(dist_to_red[u], GetDist(u, v));
    }
}

int Get(int v)
{
    int r = n;
    for (int i = 0; i < (int) centroids[v].size(); ++i) {
        int u = centroids[v][i];
        r = min(r, GetDist(u, v) + dist_to_red[u]);
    }
    return r;
}

void DeleteFromVector(vector<int>& g, int v)
{
    int new_sz = 0;
    for (int i = 0; i < (int) g.size(); ++i) {
        if (g[i] != v) {
            g[new_sz] = g[i];
            ++new_sz;
        }
    }
    g.resize(new_sz);
}

vector<int> sz;

void ConstructSizes(int v, int pr)
{
    sz[v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            ConstructSizes(u, v);
            sz[v] += sz[u];
        }
    }
}

void AddCentroid(int v, int pr, int centroid)
{
    centroids[v].push_back(centroid);
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            AddCentroid(u, v, centroid);
        }
    }
}

int GetCentroid(int v, int pr, int all_sz)
{
    int mx = -1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            if (mx == -1 || sz[u] > sz[mx]) {
                mx = u;
            }
        }
    }
    if (mx == -1) {
        return v;
    }
    if (sz[mx] < all_sz / 2) {
        return v;
    }
    return GetCentroid(mx, v, all_sz);
}

void ConstructCentroids(int v)
{
    ConstructSizes(v, -1);
    int centroid = GetCentroid(v, -1, sz[v]);
    AddCentroid(v, -1, centroid);
    for (int i = 0; i < (int) g[centroid].size(); ++i) {
        int u = g[centroid][i];
        DeleteFromVector(g[u], centroid);
    }
    for (int i = 0; i < (int) g[centroid].size(); ++i){ 
        ConstructCentroids(g[centroid][i]);
    }
    g[centroid].clear();
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; 
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    tin.resize(n);
    tout.resize(n);
    up.resize(n, vector<int>(kMaxLog));
    cur_time = 0;
    height.resize(n);
    PreCalcForLCA(0, -1);
    
    dist_to_red.resize(n);
    for (int i = 0; i < n; ++i) {
        dist_to_red[i] = GetDist(i, 0);
    }
    centroids.resize(n);
    sz.resize(n);
    ConstructCentroids(0);
    
    for (; m; --m) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int v;
            cin >> v;
            --v;
            Update(v);
        } else {
            int v;
            cin >> v;
            --v;
            cout << Get(v) << '\n';
        }
    }
    cout.flush();
    
    return 0;
}