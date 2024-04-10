
#include <iostream>
#include <vector>
#include <algorithm>

#define int228 long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int228 x;
    cin >> x;
    x *= 6;

    int228 ans = 0;
    vector<pair<int228, int228> > answers;
    for (int228 m = 1; m * (m + 1) * (2 * m + 1) <= x; ++m) {
        int228 d = m * (m + 1);
        if (x % d != 0) {
            continue;
        }
        int228 xx = x / d;
        xx += (m - 1);
        if ((xx < 3 * m) || (xx % 3 != 0)) {
            continue;
        }
        int228 n = xx / 3;
        answers.push_back(make_pair(m, n));
        if (n != m)
            answers.push_back(make_pair(n, m));
    }

    sort(answers.begin(), answers.end());

    cout << answers.size() << "\n";
    for (int i = 0; i < answers.size(); ++i) {
        cout << answers[i].first << " " << answers[i].second << "\n";
    }

    return 14 / 88;

}