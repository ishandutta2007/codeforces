#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000

bool cmpx(pair<pair<long long, long long>, long long> a, pair<pair<long long, long long>, long long> b){
    if(a.first.first < b.first.first) return 1;
    if(a.first.first > b.first.first) return 0;
    return a<b;
}

bool cmpy(pair<pair<long long, long long>, long long> a, pair<pair<long long, long long>, long long> b){
    if(a.first.second < b.first.second) return 1;
    if(a.first.second > b.first.second) return 0;
    return a<b;
}

long long n, m;
vector<pair<pair<long long, long long>, long long>> pointsX;
vector<pair<pair<long long, long long>, long long>> pointsY;
vector<pair<long long, long long>> adj[MAXN];
long long d[MAXN];
long long p[MAXN];
long long sx, sy, fx, fy;

void addE(long long a, long long b, long long w){
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}
void addEE(long long a, long long b, long long w){
    adj[a].push_back({b, w});
}

const long long INF = 100000000000000;

void dijkstra(long long s) {
    fill(d, d+MAXN, INF);
    fill(p, p+MAXN, -1);
    d[s] = 0ll;
    using pii = pair<long long, long long>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0ll, s});
    while (!q.empty()) {
        long long v = q.top().second;
        long long d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            long long to = edge.first;
            long long len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    for(long long i = 0; i<m; i++){
        long long a, b; cin >> a >> b;
        pointsX.push_back({{a, b}, i});
        addEE(m, i, min(abs(sx-a),abs(sy-b)));
        addEE(i, m+1, (abs(fx-a)+abs(fy-b)));
    }
    addE(m, m+1, abs(sx-fx)+abs(sy-fy));
    pointsY = pointsX;
    sort(pointsX.begin(), pointsX.end(), cmpx);
    sort(pointsY.begin(), pointsY.end(), cmpy);
    // for(auto p : pointsX){
    //     cout << p.first.first << " " << p.first.second << endl;
    // }
    // cout << pointsX.size() << endl;
    for(int i = 0; i<(int)pointsX.size()-1; i++){
        // cout << 1 << endl;
        addE(pointsX[i].second, pointsX[i+1].second, pointsX[i+1].first.first-pointsX[i].first.first);
    }
    for(long long i = 0; i<(int)pointsY.size()-1; i++){
        addE(pointsY[i].second, pointsY[i+1].second, pointsY[i+1].first.second-pointsY[i].first.second);
    }
    dijkstra(m);
    cout << d[m+1] << endl;
}