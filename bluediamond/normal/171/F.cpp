#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int rev(int x)
{
    int sol = 0;
    while (x)
    {
        sol = sol * 10 + x % 10;
        x /= 10;
    }
    return sol;
}

const int N = (int) 1e7;
int lp[N + 7];
bool is[N + 7];
vector<int> primes;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            is[i] = 1;
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i <= N; j++)
        {
            lp[primes[j] * i] = primes[j];
        }
    }
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= N / 10; i++)
    {
        int j = rev(i);
        cnt += (is[i] && is[j] && (i != j));
        if (cnt == n)
        {
            cout << i << "\n";
            return 0;
        }
    }
}