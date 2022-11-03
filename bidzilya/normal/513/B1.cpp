#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetValue(const vector<int>& a)
{
    int res = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        int mn = a[i];
        for (int j = i; j < (int) a.size(); ++j) {
            mn = min(mn, a[j]);
            res += mn;
        }
    }
    return res;
}

void Show(const vector<int>& a)
{
    for (int i = 0; i < (int) a.size(); ++i) {
        cout << a[i] + 1 << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    int max_val = GetValue(a);

    do {
        int val = GetValue(a);
        max_val = max(max_val, val);
    } while (next_permutation(a.begin(), a.end()));

    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    int m;
    cin >> m;
    do {
        int val = GetValue(a);
        if (val == max_val) {
            --m;
            if (m == 0) {
                Show(a);
                break;
            }
        }
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}