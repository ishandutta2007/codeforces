#include <iostream>

using namespace std;

const int mod = (int)1e9 + 7;
long long a[100005];

long long fastModExp(long long x, long long e, long long mod)
{
	//Calculates x raised to the power e modulo m
	//Time Complexity is O(log2(e))
	//Works as long as mod^2 fits in long long

    long long ans = 1;
    x %= mod;

    while (e != 0)
    {
        if (e % 2 == 1)
            ans = (ans * x) % mod;

        x = (x * x) % mod;
        e /= 2;
    }

    return ans;
}

long long modInv3 = fastModExp(3, mod-2, mod), modInv2 = fastModExp(2, mod-2, mod);

void printEvenAnswer(int k)
{
    long long num = 4, den = 2;
    bool flag = false;

    for (int i = 0; i < k; ++i)
    {
        if (!flag and a[i] % 2 == 0)
        {
            num = fastModExp(num, a[i]/2, mod);
            flag = true;
        }

        else
            num = fastModExp(num, a[i], mod);

        den = fastModExp(den, a[i], mod);
    }

    num = (num + 2) % mod;
    num = (num * modInv3) % mod;
    num = (num * modInv2) % mod;

    den = (den * modInv2) % mod;

    cout << num << '/' << den;
}

bool isN1(int k)
{
    for (int i = 0; i < k; ++i)
        if (a[i] != 1)
            return false;

    return true;
}

void printOddAnswer(int k)
{
    if (isN1(k))
    {
        cout << 0 << '/' << 1;
        return;
    }

    long long num = 2;

    for (int i = 0; i < k; ++i)
        num = fastModExp(num, a[i], mod);

    long long den = num;

    num = (num * modInv2) % mod;
    num = (num - 1 + mod) % mod;
    num = (num * modInv3) % mod;

    den = (den * modInv2) % mod;

    cout << num << '/' << den;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;

    bool even = false;

    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];

        if (a[i] % 2 == 0)
            even = true;
    }

    if (even)
    {
        printEvenAnswer(k);
    }

    else
    {
        printOddAnswer(k);
    }

    return 0;
}