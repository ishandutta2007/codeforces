#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
 
struct edge {
    int X, Y;
    long long W, P;
} v[MAXN];
 
int N;
long long weight[MAXN];
vector<edge> tree[MAXN];
 
void Minimize(int node) {
    for (edge nxt : tree[node]) {
        Minimize(nxt.Y);
        if (weight[nxt.Y] > nxt.P) {
            cout << "-1\n";
            exit(0);
        }
 
        long long rem = min(v[nxt.X].W - 1, v[nxt.X].P - weight[nxt.Y]);
        v[nxt.X].W -= rem;
        v[nxt.X].P -= rem;
        weight[node] += weight[nxt.Y] + v[nxt.X].W;
    }
}
 
void Maximize(int node, long long max_weight) {
    for (edge nxt : tree[node]) {
        long long new_weight = min(nxt.W, v[nxt.X].W + max_weight - weight[node]);
 
        weight[node] -= weight[nxt.Y] + v[nxt.X].W;
        v[nxt.X].P += new_weight - v[nxt.X].W;
        v[nxt.X].W = new_weight;
 
        Maximize(nxt.Y, min(v[nxt.X].P, max_weight - weight[node] - v[nxt.X].W));
        weight[node] += weight[nxt.Y] + new_weight;
    }
}
 
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
 
    for (int i = 0; i < N - 1; i++) {
        cin >> v[i].X >> v[i].Y >> v[i].W >> v[i].P;
        tree[v[i].X].push_back(v[i]);
        tree[v[i].X].back().X = i;
    }
 
    Minimize(1);
    Maximize(1, LLONG_MAX);
 
    cout << N << "\n";
    for (int i = 0; i < N - 1; i++)
        cout << v[i].X << " " << v[i].Y << " " << v[i].W << " " << v[i].P << "\n";
}