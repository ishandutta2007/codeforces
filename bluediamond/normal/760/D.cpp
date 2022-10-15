#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
int n;
int t[N];
int c[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

  ///  freopen ("hacker.in", "r", stdin);

    cin >> n;

    int last_of = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];

        c[i] = c[i - 1] + 20;

        if (t[i] < last_of)
        {
            c[i] = c[i - 1];
        }
        else
        {
            int j = i;
            while (j - 1 >= 1 && t[i] - t[j - 1] < 90)
            {
                j--;
            }
            c[i] = min(c[i], c[j - 1] + 50);
            int j2 = j;

            while (j - 1 >= 1 && t[i] - t[j - 1] < 1440)
            {
                j--;
            }
            c[i] = min(c[i], c[j - 1] + 120);

            swap(j, j2);
            if (c[i] == c[j - 1] + 50)
            {
                last_of = t[j] + 90;
            }
            swap(j, j2);
            if (c[i] == c[j - 1] + 120)
            {
                last_of = t[j] + 1440;
            }
        }


        cout << c[i] - c[i - 1] << "\n";
    }


}