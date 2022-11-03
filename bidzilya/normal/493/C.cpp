#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

typedef pair<int, int> Score;

void UpdateAns(Score& best_score, const Score& cur_score)
{
    if (cur_score.first - cur_score.second > best_score.first - best_score.second ||
        (cur_score.first - cur_score.second == best_score.first - best_score.second &&
            cur_score.first > best_score.first)) {
                best_score = cur_score;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<pair<int, int> > c(n + m);
    for (int i = 0; i < n; ++i) {
        c[i].first = a[i];
        c[i].second = 0;
    }

    for (int i = 0; i < m; ++i) {
        c[n + i].first = b[i];
        c[n + i].second = 1;
    }

    Score score(3 * n, 3 * m);

    UpdateAns(score, make_pair(2 * n, 2 * m));

    sort(c.begin(), c.end());

    int sum3_a = n;
    int sum3_b = m;

    for (int i = 0; i < n + m; ++i) {
        if (c[i].second == 0) {
            --sum3_a;
        } else {
            --sum3_b;
        }

        UpdateAns(score, make_pair(3 * sum3_a + 2 * (n - sum3_a), 3 * sum3_b + 2 * (m - sum3_b)));
    }


    cout << score.first << ":" << score.second << endl;

    return 0;
}