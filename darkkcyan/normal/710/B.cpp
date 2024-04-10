#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back

int n;
ve<long> arr, l, r;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i, f, g;

    cin >> n;
    arr.resize(n);
    for (auto& i : arr) cin >> i;

    sort(all(arr));
    r.resize(n);
    l.resize(n);

    for (int i = 1; i < n; ++i) {
        l[i] = l[i - 1] + (arr[i] - arr[i - 1]) * i;
    }
    for (int i = n - 2; i >= 0; --i) {
        r[i] += r[i + 1] + (arr[i + 1] - arr[i]) * (n - 1 - i);
    }

    transform(all(l), r.begin(), l.begin(), plus<long>());
    cout << arr[min_element(all(l)) - l.begin()];

    return 0;
}