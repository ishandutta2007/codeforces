#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<ll> dlist;
typedef vector<dlist> matrix;

void solve(int tc){
    int n, m, s;
    cin >> n >> m >> s;

    matrix ady(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        ady[u].push_back(v);
    }
    vector<int> dad(n + 1), color(n + 1);

    queue<tuple<int, int, int>> q;
    for(auto &x:ady[s]){
        q.push({x, s, x});
    }

    auto make_path = [&](int v){
        vector<int> data;
        while(v != 0){
            data.push_back(v);
            v = dad[v];
        }
        reverse(all(data));
        cout << data.size() << "\n";
        for(auto &x:data) cout << x << " \n"[&x == &data.back()];
    };

    while(!q.empty()){
        int cur, d, col;
        tie(cur, d, col) = q.front();
        q.pop();

        if((color[cur] != 0) && (color[cur] != col)){
            cout << "Possible\n"; 
            stack<int> p1, p2;
            make_path(cur);
            dad[cur] = d;
            make_path(cur);
            return;      
        }
        if(color[cur] != 0) continue;

        dad[cur] = d;
        color[cur] = col;
        for(auto &x:ady[cur]){
            if((x != d) && (x != s))
                q.push({x, cur, col});
        }
    }

    cout << "Impossible\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    for(int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}//RUL0