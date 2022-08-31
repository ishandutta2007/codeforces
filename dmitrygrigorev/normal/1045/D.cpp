#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
int n;
vector<vector<int> > data;
vector<double> my, sons, f;
void dfs(int vertex, int last){
    f[vertex] = last;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to==last) continue;
        sons[vertex] += my[to];
        dfs(to, vertex);
    }
}
int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n;
    data.resize(n), my.resize(n), sons.resize(n, 0.), f.resize(n);
    for (int i=0; i < n; i++) cin >> my[i];
    for (int i=0; i < n; i++) my[i] = 1.-my[i];
    //return 0;
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    dfs(0, -1);
    double ans = 0;
    for (int i=0;i<n;i++) ans += my[i] * (1.-sons[i]);
    //cout << ans << endl;
    //return 0;
    int q;
    cin >> q;
    cout << fixed << setprecision(6);
    for (int i=0; i < q; i++){
        int a;
        double x;
        cin >> a >> x;
        x = 1.-x;
        double old = my[a] * (1. - sons[a]);
        int F = f[a];
        if (F != -1) old += my[F] * (1. - sons[F]);
        if (F != -1) sons[F] += x - my[a];
        my[a] = x;
        double nw = my[a] * (1. - sons[a]);
        if (F != -1) nw += my[F] * (1. - sons[F]);
        ans += nw-old;
       // cout << old << " " << nw << endl;
        //return 0;
        cout << ans << "\n";
    }
}