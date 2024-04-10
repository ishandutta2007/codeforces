/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1000002;

int t;

int n;

int ans[N_MAX];

int cnt[N_MAX];

int first[N_MAX];

bool sieve[N_MAX];

int mi[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve[1] = true;
    for(int i = 2; i * i <= 1000000; i++)
        if(sieve[i] == false)
            for(int j = i * i; j <= 1000000; j += i)
                sieve[j] = true;
    for(int i = 2; i <= 1000000; i++)
        mi[i] = INT_MAX;
    for(int i = 1; i <= 1000000; i++)
        if(sieve[i] == false)
        {
            first[i] = min(1000001LL, 1LL * i * i);
            for(int j = i; j <= 1000000; j += i)
                mi[j] = min(mi[j], first[i]);
        }
        else
            first[i] = 1000001;
    for(int i = 2; i <= 1000000; i++)
        ans[max(i, mi[i])]++;
    for(int i = 1; i <= 1000000; i++)
        ans[i] += ans[i - 1];
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << n - ans[n] << "\n";
    }
    return 0;
}