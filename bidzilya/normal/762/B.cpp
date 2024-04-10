#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a, b, c;
int m;
vector<int> as[2];

void Solve() {
    sort(as[0].begin(), as[0].end(), greater<int>());
    sort(as[1].begin(), as[1].end(), greater<int>());
    long long result = 0;
    int count = 0;
    while (a > 0 && as[0].size() > 0) {
        --a;
        result += as[0].back();
        count += 1;
        as[0].pop_back();
    }
    while (b > 0 && as[1].size() > 0) {
        --b;
        result += as[1].back();
        count += 1;
        as[1].pop_back();
    }

    as[0].insert(as[0].end(), as[1].begin(), as[1].end());
    sort(as[0].begin(), as[0].end());

    {
        int d = min(c, (int) as[0].size());
        count += d;
        for (int i = 0; i < d; ++i) {
            result += as[0][i];
        }
    }

    cout << count << " " << result << endl;
}

bool Read() {
    if (!(cin >> a >> b >> c)) {
        return false;
    }
    as[0].clear();
    as[1].clear();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        string tp;
        cin >> tp;
        const int id = (tp == string("USB") ? 0 : 1);
        as[id].push_back(value);
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}