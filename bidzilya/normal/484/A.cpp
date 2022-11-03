#include <bits/stdc++.h>
using namespace std;

const int kMaxBit = 62;

int GetBit(long long mask, int num)
{
    return (mask >> num) & 1;
}

long long GetAnswer(long long l, long long r)
{
    for (int i = 0; i <= kMaxBit; ++i) {
        if (!GetBit(l, i)) {
            if (l + (1LL << i) <= r) {
                l += (1LL << i);
            }
        }
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;

        cout << GetAnswer(l, r) << endl;
    }

    return 0;
}