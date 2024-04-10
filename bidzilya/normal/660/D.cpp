#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int GetGcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

void Normalize(int& dx, int& dy) {
    /*
    int g = GetGcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    */

    if (dx < 0) {
        dx *= -1;
        dy *= -1;
    } else if (dx == 0 && dy < 0) {
        dy *= -1;
    }
}

#define count count123123

map<pair<int, int>, int> count;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = a[j].first - a[i].first;
            int dy = a[j].second - a[i].second;

            Normalize(dx, dy);

            ++count[make_pair(dx, dy)];
        }
    }

    long long result = 0;
    for (const auto& itr : count) {
        long long x = itr.second;
        result += x * (x - 1) / 2;
    }
    cout << result / 2 << endl;

    return 0;
}