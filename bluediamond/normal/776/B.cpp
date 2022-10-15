#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100000 + 7;
int n;
bool prie[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) /// {2}
    {
        cout << "1\n";
        cout << "1\n";
        return 0;
    }

    if (n == 2) /// {2, 3}
    {
        cout << "1\n";
        cout << "1 1\n";
        return 0;
    }

    cout << "2\n";
    prie[2] = 1;
    for (int i = 3; i <= n + 1; i += 2)
    {
        prie[i] = 1;
    }

    for (int i = 3; i * i <= n + 1; i += 2)
    {
        if (prie[i])
        {
            for (int j = i * i; j <= n + 1; j += 2 * i)
            {
                prie[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n + 1; i++)
    {
        cout << prie[i] + 1 << " ";
    }
    cout << "\n";



}