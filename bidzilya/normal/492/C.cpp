#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n;

    long long r, avg;

    cin >> n >> r >> avg;

    avg *= n;

    vector<pair<long long, long long> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end());

    long long cur_sum = 0;
    long long cur_ans = 0;
    for (int i = 0; i < n; ++i) {
        cur_sum += a[i].second;
    }

    for (int i = 0; i < n; ++i) {
        long long can_use = min(r - a[i].second, max(0LL, avg - cur_sum));

        cur_sum += can_use;
        cur_ans += can_use * a[i].first;
    }

    cout << cur_ans << endl;

    return 0;
}