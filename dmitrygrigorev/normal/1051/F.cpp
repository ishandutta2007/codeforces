#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int ,int> binup[100000][20];
struct Edge{int to; int w; bool go;};
vector<vector<Edge> > data;
vector<int> spec;
vector<bool> used;
int ctr=0;
int dp[42][100000];
vector<int> tin, tout, ht;
int cc = 0;
void dfs(int vertex, int last, int hh, int edg){
    used[vertex] = true;
    ht[vertex] = hh;
    tin[vertex] = cc++;
    if (last != -1){
        binup[vertex][0] = {last, edg};
        int ind = 0, par = last;
        while (binup[par][ind].first != -1){
            binup[vertex][ind+1] = {binup[par][ind].first, binup[par][ind].second + binup[vertex][ind].second};
            par = binup[par][ind].first;
            ind++;
        }
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].to;
        if (to == last){
            data[vertex][i].go = true;
            continue;
        }
        if (used[to]){
            if (spec[to] == -1)spec[to] = ctr++;
            if (spec[vertex] == -1) spec[vertex] = ctr++;
            dp[spec[to]][vertex] = data[vertex][i].w;
            dp[spec[vertex]][to] = data[vertex][i].w;
            continue;
        }
        data[vertex][i].go = true;
        dfs(to, vertex, hh+1, data[vertex][i].w);
    }
    tout[vertex] = cc++;
}
bool High(int u, int v){
    return ((tin[u] <= tin[v]) && (tout[u] >= tout[v]));
}
int Lift(int V, int st){
    int ans = 0;
    for (int i=0; i < 20; i++){
        int ba = st & (1<<i);
        if (ba == 0) continue;
        ans += binup[V][i].second;
        V = binup[V][i].first;
    }
    return ans;
}
int LCA(int u, int v){
    int h = ht[u], o=u;
    if (High(u, v)){
        return Lift(v, abs(ht[u] - ht[v]));
    }
    for (int i=19; i >= 0; i--){
        if (binup[u][i].first == -1) continue;
        int her = binup[u][i].first;
        if (High(her, v)) continue;
        u = her;
    }
    u = binup[u][0].first;
    return Lift(o, abs(ht[u] - h)) + Lift(v, abs(ht[u] - ht[v]));
}
void Dfs(int ind, int vertex, int D, int last){
    dp[ind][vertex] = min(dp[ind][vertex], D);
    //cout << ind << " " << vertex << " " << D << endl;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].to;
        if (to == last) continue;
        if (!data[vertex][i].go) continue;
        Dfs(ind, data[vertex][i].to, D+data[vertex][i].w, vertex);
    }
}
int get(int A, int B){
    if (spec[A] == -1) swap(A, B);
    //cout << A << "!!" << B << " " << dp[spec[A]][B] << endl;
    if (spec[A] == -1){
        return LCA(A, B);
    }
    return dp[spec[A]][B];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < 42; i++) for (int j=0; j < n; j++) dp[i][j] = 1e18;
    for (int i=0; i < n; i++) for (int j=0; j < 20; j++) binup[i][j] = {-1, -1};
    for (int i=0; i < n; i++) data.push_back({});
    for (int i=0; i < n; i++) used.push_back(false);
    for (int i=0; i < n; i++) spec.push_back(-1);
    for (int i=0; i < n; i++) tin.push_back(-1);
    for (int i=0; i < n; i++) tout.push_back(-1);
    for (int i=0; i < n; i++) ht.push_back(-1);
    for (int i=0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        data[a-1].push_back({b-1, d, false});
        data[b-1].push_back({a-1, d, false});
    }
    dfs(0, -1, 0, -1);
    //cout << binup[8][3].first << endl;
    vector<int> r(ctr+1);
    for (int i=0; i < n; i++) if (spec[i] != -1) r[spec[i]] = i;
    for (int i=0; i < ctr; i++) Dfs(i, r[i], 0, -1);
    int q;
    cin >> q;
    //for (int i=0;i<n;i++) for (int j=0; j < n; j++) LCA(i, j);
    for (int i=0; i < q; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        vector<int> vrt = r;
        vrt.back() = u, vrt.push_back(v);
        vector<int> d(vrt.size());
        fill(d.begin(), d.end(), 1e18);
        d[d.size() - 2] = 0;
        vector<bool> A(d.size());
        fill(A.begin(), A.end(), true);
        for (int j=0; j < d.size(); j++){
            int V = -1, Mx = 1e18+1;
            for (int p=0; p < d.size(); p++){
                if (!A[p]) continue;
                if (d[p] < Mx){
                    Mx = d[p];
                    V = p;
                }
            }
            //cout << V << endl;
            A[V] = false;
            for (int p=0; p < d.size(); p++){
                if (!A[p]) continue;
                int H = get(vrt[p], vrt[V]);
                //cout << vrt[p] << " " << vrt[V] << " " << H << endl;
                d[p] = min(d[p], d[V] + get(vrt[p], vrt[V]));
            }
            //cout << d.back() << endl;
        }
        cout << d.back() << "\n";
    }

}