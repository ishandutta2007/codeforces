#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

long long spikes[100001], t[100001];
vector<pair<int,int>> asdf;

int main() {
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        if (x > y) {
            int z = y;
            y = x;
            x = z;
        }
        spikes[x]++;
        spikes[y]++;
        asdf.push_back(make_pair(x,y));
    }

    sort(asdf.begin(),asdf.end());

    for (int i = 0; i < m; ++i) {
        if (t[asdf[i].first]+1 > t[asdf[i].second]) t[asdf[i].second] = t[asdf[i].first]+1;
    }
    for (int i = 1; i <= n; ++i) {
        if (spikes[i]*(t[i]+1) > ans) ans = spikes[i]*(t[i]+1);
    }
    cout << ans;
    // cout << asdf[make_pair(4,5)];
}