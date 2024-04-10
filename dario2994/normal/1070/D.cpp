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

    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    LL b = 0;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (b > 0) {
            res++;
            a[i] -= min(a[i], k-b);
        }
        res += a[i]/k;
        //~ cout << res << endl;
        a[i] %= k;
        b = a[i];
    }
    if (b > 0) res++;
    cout << res << "\n";
}