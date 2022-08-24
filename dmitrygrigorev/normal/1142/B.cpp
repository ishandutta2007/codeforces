#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
vector<int> tet;
int n, m, q;
vector<bool> used;
void dfs(int vertex, deque<int> &d){
    used[vertex] = true;
    d.push_back(vertex);
    int T = -1;
    if (d.size() > n){
        T = d.front();
        d.pop_front();
    }
    if (d.size() == n){
        tet[vertex] = d[0];
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs(to, d);
    }
    d.pop_back();
    if (T!=-1) d.push_front(T);
}
vector<int> rmq;
int INF = 1e9;
void build(int i, int l, int r){
    if (r-l==1){
        rmq[i] = tet[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid, r);
    rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
}
int get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return INF;
    if (l1==l && r1==r) return rmq[i];
    int mid = (l+r)/2;
    return min(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    vector<int> p(n);
    for (int i=0; i < n; i++) cin >> p[i];
    vector<int> v(m);
    for (int i=0; i < m; i++) cin >> v[i];
    vector<int> go(n);
    for (int i=0; i < n; i++) p[i]--;
    for (int i=0; i < m; i++) v[i]--;
    for (int i=0; i < n; i++) go[p[i]] = i;
    for (int i=0; i < m; i++) v[i] = go[v[i]];
    int where[n];
    for (int i=0; i < n; i++) where[i] = -1;
    vector<int> links(m);
    for (int i=m-1; i >= 0; i--){
        int element = (v[i]+1)%n;
        links[i] = where[element];
        where[v[i]] = i;
    }
    tet.resize(m, INF);
    data.resize(m, {});
    for (int i=0; i < links.size(); i++){
        if (links[i]!=-1) data[links[i]].push_back(i);
    }
    used.resize(m, false);
    for (int i=m-1; i >= 0; i--){
        if (!used[i]){
            deque<int> d;
            dfs(i, d);
        }
    }
    //for (int i=0;i<m;i++) cout << tet[i] << " ";
    rmq.resize(4*m, INF);
    build(0, 0, m);
    for (int i=0; i < q; i++){
        int l, r;
        cin >> l >> r;
        int T = get(0, 0, m, l-1, r);
        if (T <= r-1) cout << 1;
        else cout << 0;
    }
}