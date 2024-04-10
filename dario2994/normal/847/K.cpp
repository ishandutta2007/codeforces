#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif

const int MAXN = 310;

string from[MAXN], to[MAXN];
int c[MAXN];
vector<pair<string, string>> routes;
vector<int> cost_route;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    for (int i = 0; i < n; i++) {
        cin >> from[i] >> to[i];
    }
    c[0] = a;
    for (int i = 1; i < n; i++) {
        if (from[i] == to[i-1]) c[i] = b;
        else c[i] = a;
    }
    
    for (int i = 0; i < n; i++) {
        int at = -1;
        for (int j = 0; j < (int)routes.size(); j++) {
            auto r = routes[j];
            if (from[i] == r.first and to[i] == r.second) at = j;
            if (to[i] == r.first and from[i] == r.second) at = j;
        }
        if (at == -1) {
            routes.push_back({from[i], to[i]});
            cost_route.push_back(0);
            at = routes.size() - 1;
        }
        cost_route[at] += c[i];
    }
    sort(cost_route.begin(), cost_route.end(), [&](int i, int j) {return i > j;});

    int res = 0;
    for (int i = 0; i < n; i++) res += c[i];
    
    for (int i = 0; i < min(k, (int)cost_route.size()); i++) {
        if (cost_route[i] > f) res += (f - cost_route[i]);
    }
    cout << res << "\n";
}