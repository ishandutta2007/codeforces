#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


struct punkt{ 
    vector<pair<int, int>> e;
    int it;
} v[100005];

vector<pair<int, int>> ans;
bool used[500005];
int n, m, ecount;

void euler(int a) {
    while(v[a].it < v[a].e.size()) {
        pair<int, int> b = v[a].e[v[a].it];
        if(!used[b.second]) {
            used[b.second] = 1;
            euler(b.first);
            ans.emplace_back(a, b.first);
        }
        v[a].it++;
    }
}

void join(int a, int b) {
    v[a].e.emplace_back(b, ecount);
    v[b].e.emplace_back(a, ecount);
    ecount++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }
    vector<int> q;
    for(int i = 1; i <= n; i++) 
        if(v[i].e.size()&1)
            q.push_back(i);
    
    for(int i = 0; i < q.size(); i+=2)
        join(q[i], q[i+1]);
    
    if(ecount & 1)
        join(1, 1);
    
    euler(1);
    cout << ecount << "\n";
    for(int i = 0; i < ans.size(); i++) {
        if(i&1)
            cout << ans[i].first << " " << ans[i].second << "\n";
        else
            cout << ans[i].second << " " << ans[i].first << "\n";
    }
    return 0;
}