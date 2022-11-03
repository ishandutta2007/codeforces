#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    unordered_map<int, int> hasX, hasY;
    map<pair<int, int>, int> has;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        ++hasX[a[i].first];
        ++hasY[a[i].second];
        ++has[a[i]];
    }

    long long result = 0;
    for (const pair<int, int>& p : hasX) {
        result += 1LL * (p.second - 1) * p.second / 2;
    }
    for (const pair<int, int>& p : hasY) {
        result += 1LL * (p.second - 1) * p.second / 2;
    }
    for (const pair<pair<int, int>, int>& p : has) {
        result -= 1LL * (p.second - 1) * p.second / 2;
    }

    cout << result << endl;

    return 0;
}