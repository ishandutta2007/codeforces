#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll n, k, c2, c5, n1;

int main()
{
    cin >> n >> k;
    n1 = n;
    while (n1 % 2 == 0) {
        n1 /= 2;
        c2++;
    }
    while (n1 % 5 == 0) {
        n1 /= 5;
        c5++;
    }
    while (c2 < k) {
        n *= 2;
        c2++;
    }
    while (c5 < k) {
        n *= 5;
        c5++;
    }
    cout << n << endl;
    return 0;
}