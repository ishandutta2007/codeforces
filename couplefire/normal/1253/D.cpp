//https://codeforces.com/problemset/problem/1253/D

#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 1000000000

int parent[MAXN];
int siz[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i<n; i++) make_set(i);
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        union_sets(a, b);
    }
    int mi[n];
    int ma[n];
    fill(mi, mi+n, INF);
    fill(ma, ma+n, -1);
    for(int i = 0; i<n; i++){
        int t = find_set(i);
        mi[t] = min(mi[t], i);
        ma[t] = max(ma[t], i);
    }
    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++){
        if(ma[i] == -1) continue;
        v.push_back({mi[i], ma[i]});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int cma = v[0].second;
    for(int i = 0; i<v.size()-1; i++){
        if(v[i+1].first < cma){
            cma = max(cma, v[i+1].second);
            ans++;
        }
        else{
            cma = v[i+1].second;
        }
    }
    cout << ans << endl;
}