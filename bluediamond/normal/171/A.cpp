#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int x[100];
int y[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, top = 0, sol;
    cin >> a >> b;
    sol = a;
    while (a)
    {
        x[top++] = a % 10;
        a /= 10;
    }
    top = 0;
    while (b)
    {
        y[top++] = b % 10;
        b /= 10;
    }
    int x = 1;
    for (int i = 0; i < top; i++)
    {
        sol += y[top - 1 - i] * x;
        x *= 10;
    }
    cout << sol << "\n";
}