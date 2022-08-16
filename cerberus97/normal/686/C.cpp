#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double log2_7 = log2(7);
int p7[15], p10[15], fact[15];

void pre()
{
    p7[0] = 1;
    p10[0] = 1;
    fact[0] = 1;

    for (int i = 1; i < 15; ++i)
    {
        p7[i] = 7 * p7[i - 1];
        p10[i] = 10 * p10[i - 1];
        fact[i] = i * fact[i - 1];
    }
}

int getDigitsInBase7(int x)
{
    if (!x)
        return 1;

    return floor(log2(x)/log2_7) + 1;
}

int base10to7(int x)
{
    int ans = 0;

    for (int i = 10; i >= 0; --i)
    {
        if (p7[i] > x)
            continue;

        ans += p10[i] * (x/p7[i]);
        x %= p7[i];
    }

    return ans;
}

int getDisp(int x)
{
    return fact[7 - x];
}

int arrToNum(int *x, int l, int r)
{
    int ans = 0;

    for (int i = l, j = r - l; i <= r; ++i, --j)
    {
        ans += p10[j] * x[i];
    }

    return ans;
}

void testFunction()
{
    int arr[5];

    for (int i = 0; i < 5; ++i)
        cin >> arr[i];

    cout << arrToNum(arr, 0, 4);
}

int main()
{
    pre();

    //testFunction();
    //return 0;

    int n, m, maxHour, maxMin;

    cin >> n >> m;

    int hrDig = getDigitsInBase7(n - 1), minDig = getDigitsInBase7(m - 1);

    if (hrDig + minDig > 7)
    {
        cout << 0;
        return 0;
    }

    maxHour = base10to7(n - 1);
    maxMin = base10to7(m - 1);

    int ans = 0, totalDig = hrDig + minDig;
    int disp = getDisp(totalDig);
    int cur[7] = {0, 1, 2, 3, 4, 5, 6};

    for (int i = 0; i < fact[7]; ++i)
    {
        int hr = arrToNum(cur, 0, hrDig - 1);
        int mn = arrToNum(cur, hrDig, totalDig - 1);

        if (hr <= maxHour and mn <= maxMin)
            ++ans;

        next_permutation(cur, cur + 7);
    }

    ans /= disp;
    cout << ans;

    return 0;
}