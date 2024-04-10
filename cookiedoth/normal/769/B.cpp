#include <bits/stdc++.h>

using namespace std;

const int mx = 500;
int n;
pair<int, int> a[mx];
vector<pair<int, int> > ans;

int main()
{
    int temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a[i] = make_pair(temp, i+1);
    }
    sort(a+1, a+n);
    for (int i = 1; i <= (n / 2); ++i) {
        swap(a[i], a[n-i]);
    }
    int lst = 0;
    for (int i = 0; i < n; ++i) {
        if (lst >= (n - 1)) {
            break;
        }
        if (lst < i) break;
        for (int j = 0; j < a[i].first; ++j) {
            ans.push_back(make_pair(a[i].second, a[lst+1].second));
            lst++;
            if (lst >= (n - 1)) {
                break;
            }
        }
        if (lst >= (n - 1)) {
            break;
        }
    }
    if (lst >= (n - 1)) {
        cout << (n - 1) << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    else {
        cout << "-1" << '\n';
    }
    return 0;
}