#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> edges;
vector<int> in;
vector<pii> can_win;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    vector<pii> b(N);
    edges.resize(N+1);
    can_win = vector<pii>(N+1, pii(0, 0));
    in = vector<int>(N+1, 0);
    for(int i=0;i<N;++i) {
        cin >> a[i];
        b[i] = pii(a[i], i);
    }
    sort(b.begin(), b.end());
    queue<int> q;
    for(auto& x : b) {
        int ind = x.second;
        int val = x.first;
        for(int i=ind%val;i<N;i+=val) {
            if(a[i] > val) {
                edges[i].push_back(ind);
                in[ind]++;
            }
        }
    }
    for(int i=0;i<N;++i) {
        if(in[i] == 0) {
            q.push(i);
            can_win[i] = pii(false, true);
        }
    }
    while(!q.empty()) {
        int u = q.front();q.pop();
        for(auto& v : edges[u]) {
            can_win[v].first |= !can_win[u].first;
            can_win[v].second|= !can_win[u].second;
            if(--in[v] == 0) {
                q.push(v);
            }
        }
    }
    //cerr; for(int i=0;i<N;++i) {
        //cerr; for(auto& v : edges[i]) {
            //cerr << i << "->" << v << endl;
        //cerr; }
    //cerr; }
    for(int i=0;i<N;++i) {
        cout << (can_win[i].first ? 'A' : 'B');
    }
    cout << endl;

    
    return 0;
}