#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int ci, cj, dx;
int amount;

void Inc()
{
    --amount;
    cj += dx;
    if (cj < 0 || cj == m) {
        cj -= dx;
        dx *= -1;
        ++ci;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    ci = cj = 0;
    dx = +1;
    amount = n * m;

    while (k > 1) {
        --k;
        cout << 2 << " ";
        cout << ci + 1 << " " << cj + 1 << " ";
        Inc();
        cout << ci + 1 << " " << cj + 1 << endl;
        Inc();
    }

    cout << amount << " ";
    while (amount > 0) {
        cout << ci + 1 << " " << cj + 1 << " ";
        Inc();
    }
    cout << endl;

    return 0;
}