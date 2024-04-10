#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> first_pos(n + 1, -1);
    vector<int> second_pos(n + 1, -1);

    vector<int> first_sum(n);
    vector<int> second_sum(n);

    if (a[0] == 1) {
        first_sum[0] = 1;
        second_sum[0] = 0;
        first_pos[1] = 0;
    } else {
        first_sum[0] = 0;
        second_sum[0] = 1;
        second_pos[1] = 0;
    }

    for (int i = 1; i < n; ++i) {
        first_sum[i] = first_sum[i - 1];
        second_sum[i] = second_sum[i - 1];
        if (a[i] == 1) {
            ++first_sum[i];
            first_pos[first_sum[i]] = i;
        } else {
            ++second_sum[i];
            second_pos[second_sum[i]] = i;
        }
    }

    vector<pair<int, int> > ans;

    for (int t = 1; t <= n; ++t) {
        int last;
        int first = 0;
        int second = 0;
        int cur_first_sum = 0;
        int cur_second_sum = 0;

        bool good = true;
        while (cur_first_sum != first_sum[n - 1] || cur_second_sum != second_sum[n - 1]) {
            int f;
            if (cur_first_sum + t > first_sum[n - 1]) {
                f = -1;
            } else {
                f = first_pos[cur_first_sum + t];
            }
            int s;
            if (cur_second_sum + t > second_sum[n - 1]) {
                s = -1;
            } else {
                s = second_pos[cur_second_sum + t];
            }

            if (f == -1 && s == -1) {
                good = false;
                break;
            }
            if (f == -1 || (s != -1 && s < f)) {
                cur_first_sum = first_sum[s];
                cur_second_sum = second_sum[s];
                ++second;
                last = 2;
            } else {
                cur_first_sum = first_sum[f];
                cur_second_sum = second_sum[f];
                ++first;
                last = 1;
            }
        }

        if (!good) {
            continue;
        }

        if (last == 1) {
            if (first > second) {
                ans.push_back(make_pair(first, t));
            }
        } else {
            if (second > first) {
                ans.push_back(make_pair(second, t));
            }
        }
    }


    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }


    return 0;
}