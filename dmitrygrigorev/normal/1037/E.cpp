#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int> > > friends(n);
    vector<int> pointers(n);
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        friends[a-1].push_back(make_pair(b-1, i));
        friends[b-1].push_back(make_pair(a-1, i));
    }
    queue<int> q;
    set<pair<int, int> > good;
    for (int i=0; i < n; i++){
        if (friends[i].size() >= k){
            good.insert(make_pair(friends[i][k-1].second, i));
            pointers[i] = k-1;
        }
        else{
            pointers[i] = -1;
            q.push(i);
        }
    }
    int u = m;
    vector<int> ans(m);
    fill(ans.begin(), ans.end(), 0);
    vector<bool> used(n);
    fill(used.begin(), used.end(), false);
    while (good.size()){
        while (q.size()){
            int V = q.front();
            q.pop();
            used[V] = true;
            for (int i=0; i < friends[V].size(); i++){
                int to = friends[V][i].first, tm = friends[V][i].second;
                if (pointers[to] == -1) continue;
                int T = friends[to][pointers[to]].second;
                if (tm > T) continue;
                pointers[to]++;
                while (pointers[to] < friends[to].size()){
                    int K = friends[to][pointers[to]].first;
                    if (used[K] || friends[to][pointers[to]].second >= u) pointers[to]++;
                    else break;
                }
                if (pointers[to] >= friends[to].size()){
                    good.erase(good.find(make_pair(T, to)));
                    pointers[to] = -1;
                    q.push(to);
                }
                else{
                    good.erase(good.find(make_pair(T, to)));
                    T = friends[to][pointers[to]].second;
                    good.insert(make_pair(T, to));
                }
            }
        }
        int S = good.size();
        if (S==0) break;
        set<pair<int, int> > ::iterator it = good.end();
        it--;
        pair<int, int> P = *it;
        int tt = P.first;
        for (int i=tt; i < u; i++) ans[i] = S;
        u = tt;
        while (good.size()){
            set<pair<int, int> > ::iterator it = good.end();
            it--;
            pair<int, int> P = *it;
            int ttt = P.first;
            if (tt != ttt){
                break;
            }
            good.erase(it);
            pointers[P.second] = -1;
            q.push(P.second);
        }
    }
    for (int i=0;i<m;i++) cout << ans[i] << "\n";

}