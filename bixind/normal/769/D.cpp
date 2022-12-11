#include <iostream>
#include <vector>

using namespace std;

long long d[1 << 14];

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> msk;
    for (long long i = 0; i < (1 << 14); ++i) {
        if (__builtin_popcount(i) == k)
            msk.push_back(i);
    }
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < msk.size(); ++j) {
            ans += d[a[i] ^ msk[j]];
        }
        ++d[a[i]];
    }
    cout << ans;
    return 0;
}