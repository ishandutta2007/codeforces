#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
double sum[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + 1.0 / i;
    }
    int n;
    cin >> n;
    cout << fixed << setprecision(6) << sum[n] << "\n";
}