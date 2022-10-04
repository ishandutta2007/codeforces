#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

int n;

int main()
{
    cin >> n;
    if (n % 2 == 0) {
        cout << (n / 2 + 1) * (n / 2) << endl;
    }
    if (n % 2 == 1) {
        cout << (n / 2 + 1) * (n / 2 + 1) << endl;
    }
    return 0;
}