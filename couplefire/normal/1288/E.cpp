#include <bits/stdc++.h>
using namespace std;
#define MAXN 300100
int n, m;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

struct query{
    int l, r, idx;
    bool operator < (query const b) const{
        if(r < b.r) return 1;
        if(r > b.r) return 0;
        if(l < b.l) return 1;
        return 0;
    }
};

FenwickTree BIT(2*MAXN);

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int arr[n+m];
    vector<int> pos[n+1];
    for(int i = 0; i<n; i++){
        arr[i] = n-i;
        pos[arr[i]].push_back(i);
    }
    for(int i = 0; i<m; i++){
        int a; cin >> a;
        arr[i+n] = a;
        pos[arr[i+n]].push_back(i+n);
    }
    int mi[n+1];
    fill(mi, mi+n+1, 0);
    int ma[n+1];
    fill(ma, ma+n+1, -1);
    for(int i = 1; i<=n; i++){
        if(pos[i].size() == 1) mi[i] = i;
        else mi[i] = 1;
    }
    vector<query> queries;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<pos[i].size()-1; j++){
            queries.push_back({pos[i][j], pos[i][j+1], i});
        }
        queries.push_back({pos[i][pos[i].size()-1], n+m-1, i});
    }
    sort(queries.begin(), queries.end());
    int q = queries.size();
    int visited[n+1];
    int cnt = 0;
    fill(visited, visited+n+1, -1);
    for(int i = 0; i<n+m; i++){
        if(visited[arr[i]] != -1){
            BIT.add(visited[arr[i]], -1);
        }
        visited[arr[i]] = i;
        BIT.add(i, 1);
        while(cnt < q && queries[cnt].r == i){
            ma[queries[cnt].idx] = max(ma[queries[cnt].idx], BIT.sum(queries[cnt].l, queries[cnt].r));
            cnt++;
        }
    }
    for(int i = 1; i<=n; i++){
        cout << mi[i] << " " << ma[i] << endl;
    }
}