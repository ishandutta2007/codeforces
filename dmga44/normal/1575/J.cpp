#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<ll> dlist;
typedef vector<dlist> matrix;
typedef pair<int, int> pii;

struct DS{
    vector<int> p, sz;
    vector<pii> data;
    DS(int n): p(n, 0), sz(n, 1), data(n){
        iota(all(p), 0);
    }
    int SetOf(int x){
        return (p[x] == x)? x : p[x] = SetOf(p[x]);
    }
    bool Merge(int x, int y){
        x = SetOf(x);
        y = SetOf(y);
        if(x == y)
            return false;
        if(sz[x] < sz[y])
            swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
    void setData(int x, pii y){
        data[SetOf(x)] = y;
    }
    pii getData(int i){
        return data[SetOf(i)];
    }
};

void solve(int tc){
    int n, m, k;
    cin >> n >> m >> k;

    int id = 0;
    
    vector<int> cols(k);
    vector<vector<int>> data(n + 2, vector<int>(m + 2, -1));
    vector<vector<int>> ids(n + 2, vector<int>(m + 2, -1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> data[i][j];
            ids[i][j] = id++;
        }
    }

    for(auto &x:cols) cin >> x;
    DS ds(id);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            ds.setData(ids[i][j], pii(i, j));
        }
    }

    vector<vector<int>> row(n + 2, vector<int>(m + 2, -1));
    vector<vector<int>> col(n + 2, vector<int>(m + 2, -1));
    for(auto &c:cols){
        int xi = 1, yi = c;

        int x, y;
        tie(x, y) = tie(xi, yi);
        while((0 < x && x <= n) && (0 < y && y <= m)){
            tie(x, y) = ds.getData(ids[x][y]);
            tie(xi, yi) = tie(x, y);
            int cur = data[x][y];
            data[x][y] = 2;
            if(data[x + 1][y] == 2){
                auto foo = ds.getData(ids[x + 1][y]);
                ds.Merge(ids[x][y], ids[x+1][y]);
                ds.setData(ids[x][y], foo);
            }
            y += (cur == 1);
            y -= (cur == 3);
            x += (cur == 2);
        }
        cout << ds.getData(ids[xi][yi]).second << " \n"[&c == &cols.back()];
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    for(int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}//UH Top