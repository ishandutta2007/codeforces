// https://codeforces.com/problemset/problem/1195/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1000000000

long long n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n >> k;
    long long r = floor(pow(9+(8*(n+k)),0.5))-3;
    r /= 2;
    cout << n-r;
    return 0;
}