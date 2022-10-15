#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
int n, a[N];
bool done[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            done[i] = 0;
        }

        for (int x = 1; x <= n; x++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == x)
                {
                    while (i - 1 >= 1 && done[i - 1] == 0 && a[i] < a[i - 1])
                    {
                        done[i - 1] = 1;
                        swap(a[i], a[i - 1]);
                        i--;
                    }
                    break;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

}