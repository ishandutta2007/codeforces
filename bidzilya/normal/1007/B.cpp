#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const int MAX_A = 1e5;

int del[MAX_A + 1];
long long divsCount[MAX_A + 1];

void BuildDel()
{
    for (int i = 2; i <= MAX_A; ++i) {
        del[i] = i;
    }
    for (int i = 2; i <= MAX_A; ++i) {
        if (del[i] == i) {
            if (1LL * i * i <= MAX_A) {
                for (int j = i * i; j <= MAX_A; j += i) {
                    if (del[j] == j) {
                        del[j] = i;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= MAX_A; ++i) {
        divsCount[i] = 1;

        int x = i;
        while (x > 1) {
            int p = del[x];
            int c = 0;
            while (x % p == 0) {
                x /= p;
                ++c;
            }
            divsCount[i] *= (c + 1);
        }
    }
}

int GetGcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

const int M = 3;
const int MAX_MASK = (1 << M);

int a[M];
long long maskDivsCount[MAX_MASK];

void BuildMaskDp()
{
    for (int b = 0; b < M; ++b) {
        for (int mask = 0; mask < MAX_MASK; ++mask) {
            if (GetBit(mask, b) == 0) {
                maskDivsCount[mask] -= maskDivsCount[mask | (1 << b)];
            }
        }
    }
}

long long GetC3(long long count)
{
    return count + count * (count - 1) / 2 * 2 + count * (count - 1) * (count - 2) / 6;
}

long long GetC2(long long count)
{
    return count + count * (count - 1) / 2;
}

long long GetC1(long long count)
{
    return count;
}

void ShowMask(int mask)
{
    for (int i = 0; i < M; ++i) {
        cout << GetBit(mask, i);
    }
}

bool IsGood(int m1, int m2, int m3)
{
    int masks[M];
    masks[0] = m1;
    masks[1] = m2;
    masks[2] = m3;

    do {
        bool ok = true;
        for (int i = 0; i < M; ++i) {
            if (!GetBit(masks[i], i)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    } while (next_permutation(masks, masks + M));
    return false;
}

void Solve()
{
    maskDivsCount[0] = MAX_A;
    for (int mask = 1; mask < MAX_MASK; ++mask) {
        int r = 0;
        for (int i = 0; i < M; ++i) {
            if (GetBit(mask, i)) {
                r = GetGcd(r, a[i]);
            }
        }
        assert(r != 0);
        maskDivsCount[mask] = divsCount[r];
    }
    BuildMaskDp();
    long long result = 0;
    for (int mask = 0; mask < MAX_MASK; ++mask) {
        if (IsGood(mask, mask, mask)) {
            result += GetC3(maskDivsCount[mask]);
        }
    }
    for (int mask1 = 0; mask1 < MAX_MASK; ++mask1) {
        for (int mask2 = mask1 + 1; mask2 < MAX_MASK; ++mask2) {
            if (IsGood(mask1, mask2, mask2)) {
                result += GetC1(maskDivsCount[mask1]) * GetC2(maskDivsCount[mask2]);
            }
            if (IsGood(mask1, mask1, mask2)) {
                result += GetC2(maskDivsCount[mask1]) * GetC1(maskDivsCount[mask2]);
            }
        }
    }
    for (int mask1 = 0; mask1 < MAX_MASK; ++mask1) {
        for (int mask2 = mask1 + 1; mask2 < MAX_MASK; ++mask2) {
            for (int mask3 = mask2 + 1; mask3 < MAX_MASK; ++mask3) {
                if (IsGood(mask1, mask2, mask3)) {
                    result += GetC1(maskDivsCount[mask1]) * GetC1(maskDivsCount[mask2]) * GetC1(maskDivsCount[mask3]);
                }
            }
        }
    }
    cout << result << endl;
}

bool Read()
{
    if (!(cin >> a[0] >> a[1] >> a[2])) {
        return false;
    }
    return true;
}

int main()
{
    BuildDel();

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testsCount;
    cin >> testsCount;
    for (int test = 0; test < testsCount; ++test) {
        Read();
        Solve();
    }

    return 0;
}