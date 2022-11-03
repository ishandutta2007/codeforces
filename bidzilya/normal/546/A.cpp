#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long k, n, w;
    cin >> k >> n >> w;
    long long sum = 0;
    for (long long i = 1; i <= w; ++i) {
        sum += i * k;
    }
    if (sum <= n) {
        cout << 0 << endl;
    } else {
        cout << sum - n << endl;
    }
    return 0;
}