#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b;
    vector<vector<int>> seq;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(b.begin(), b.end(), a[i], [&](int u, int v) {return u > v;}) - b.begin();
        if (k == (int)b.size()) {
            b.push_back(a[i]);
            seq.push_back({a[i]});
        }
        else {
            b[k] = a[i];
            seq[k].push_back(a[i]);
        }
    }
    for (vector<int> s : seq) {
        for (int x : s) cout << x << " ";
        cout << "\n";
    }
}