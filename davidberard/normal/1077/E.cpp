#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);
    map<int, int> mp;
    for(auto& x : v) {
        cin >> x;
        mp[x]++;
    }
    vector<pii> ord;
    for(auto& p : mp)
    {
        ord.emplace_back(p.second, p.first);
    }
    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());
    int bottleneck = N*2;
    int layers = 0;
    int best = 0;
    for(int i=0;i<ord.size() && bottleneck > 0;++i)
    {
        bottleneck /= 2;
        bottleneck = min(bottleneck, ord[i].first);
        ++layers;
        best = max(best, ((1<<layers)-1)*bottleneck);
    }
    cout << best << endl;
    return 0;
}