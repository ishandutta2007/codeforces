#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
struct Edge{int u; int v; double angle;};
bool cmp(Edge &a, Edge &b){
    return (a.angle < b.angle);
}
const int N = 300;
int dp[N][N][6];
main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > pt;
    for (int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pt.push_back({x,y});
    }
    vector<Edge> pts;
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++) if (i != j){
            int dy = pt[j].second - pt[i].second, dx = pt[j].first - pt[i].first;
            pts.push_back({i, j, atan2(dy, dx)});
        }
    }
    sort(pts.begin(), pts.end(), cmp);
    for (int i=0; i < n; i++) dp[i][i][0] = 1;
    for (int i=0; i < pts.size(); i++){
        int u = pts[i].u, v = pts[i].v;
        for (int start=0; start < n; start++) for (int t=0; t < 5; t++){
            dp[start][v][t+1] += dp[start][u][t];
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++) ans += dp[i][i][5];
    cout << ans;
}