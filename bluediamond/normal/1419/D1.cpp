#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int y;
int a[N];
int b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i < n; i += 2)
    {
        b[i] = a[++y];
    }
    cout << y << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            b[i] = a[++y];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}