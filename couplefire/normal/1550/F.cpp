#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n, q, s, len;
int dist[N][3], arr[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> s >> len; --s;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    memset(dist, INF, sizeof dist);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    set<int> good;
    for(int i = 0; i<n; i++)
        good.insert(i);
    auto add = [&](int v, int d, int t){
        if(dist[v][t] > d){
            dist[v][t] = d;
            pq.push({d, v, t});
        }
    };
    add(s, 0, 0);
    while(!pq.empty()){
        auto [d, v, t] = pq.top(); pq.pop();
        if(dist[v][t] != d) continue;
        if(t == 0){
            good.erase(v);
            for(auto pos : {arr[v]-len, arr[v]+len}){
                int l = lower_bound(arr, arr+n, pos-d)-arr;
                int r = lower_bound(arr, arr+n, pos+d+1)-arr;
                for(auto it = good.lower_bound(l); it != good.end() && (*it) < r; it = good.erase(it))
                    add((*it), d, 0);
                if(l) add(l-1, pos-arr[l-1], 2);
                if(r<n) add(r, arr[r]-pos, 1);
            }
        } else if(t == 1){
            add(v, d, 0);
            if(v<n-1) add(v+1, d+arr[v+1]-arr[v], 1);
        } else{
            add(v, d, 0);
            if(v) add(v-1, d+arr[v]-arr[v-1], 2);
        }
    }
    while(q--){
        int id, k; cin >> id >> k; --id;
        cout << (dist[id][0]<=k?"YES":"NO") << '\n';
    }
}