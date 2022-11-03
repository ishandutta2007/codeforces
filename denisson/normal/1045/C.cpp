#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int binup[200000][20];
int n, m;
vector<vector<int> > tree;

vector<int> Tin, Tout, h;
int cc=0;
void Dfs(int vertex, int last, int H){
    Tin[vertex] = cc++;
    h[vertex] = H;
    if (last != -1){
        binup[vertex][0] = last;
        int V = last, ind = 0;
        while (binup[V][ind] != -1){
            binup[vertex][ind+1] = binup[V][ind];
            V = binup[V][ind];
            ind++;
        }
    }
    for (int i=0; i < tree[vertex].size(); i++){
        int to = tree[vertex][i];
        //if (vertex == 5) cout << to << endl;
        if (to==last) continue;
        //cout << vertex << " " << to << endl;
        Dfs(to, vertex, H+1);
    }
    Tout[vertex] = cc++;
}


bool G(int a, int b){
    return ((Tin[a] <= Tin[b]) && (Tout[a] >= Tout[b]));
}
int get(int a, int b){
    int ha = h[a], hb = h[b];
    if (!G(a, b)){
        for (int i=19; i >= 0; i--){
            int to = binup[a][i];
            if (to==-1) continue;
            if (G(to, b)) continue;
            a = to;
        }
        a = binup[a][0];
    }
    return abs(ha - h[a]) + abs(hb - h[a]);
}
vector<set<int> > edges;
vector<vector<int> > all;
int crtr = 0;
void bfs(int vertex){
    vector<int> e;
    set<int> alr;
    for (auto it = edges[vertex].begin(); it != edges[vertex].end(); it++){
        set<int> ns;
        int to = *it;
       // cout << to << "!!" << endl;
        vector<int> bad = {*it};
        for (auto It = edges[to].begin(); It != edges[to].end(); It++){
            if ((*It != vertex) && (!edges[vertex].count(*It))){
                ns.insert(*It);
            }
            else{
                bad.push_back(*It);
            }
        }
        edges[to] = ns;
        if (alr.count(*it)){
            bfs(*it);
            continue;
        }
        for (int i=0; i < bad.size(); i++){
            all[crtr].push_back(bad[i]);
            alr.insert(bad[i]);
        }
        crtr++;
        bfs(*it);
    }
}
int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int q;
    cin >> n >> m >> q;
    tree.resize(2*n);
    edges.resize(n);
    all.resize(n);
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    bfs(0);
    for (int i=0; i < all.size(); i++){
        for (int j=0; j < all[i].size(); j++){
            int to = all[i][j];
            tree[to].push_back(i+n);
            tree[i+n].push_back(to);
        }
    }
    for (int i=0; i < 2*n; i++) for (int j=0;j<20;j++) binup[i][j] = -1;
    Tin.resize(2*n), Tout.resize(2*n), h.resize(2*n);
    Dfs(0, -1, 0);
    for (int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << get(a, b)/2 << "\n";
    }
}