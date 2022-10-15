#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
int q;
int bad;
bool a[3][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int r, c;
        cin >> r >> c;
        if (a[r][c] == 0)
        {
            a[r][c] = 1;
            bad += (a[r][c] && a[3 - r][c]);
            bad += (a[r][c] && a[3 - r][c - 1]);
            bad += (a[r][c] && a[3 - r][c + 1]);
        }
        else
        {
            bad -= (a[r][c] && a[3 - r][c]);
            bad -= (a[r][c] && a[3 - r][c - 1]);
            bad -= (a[r][c] && a[3 - r][c + 1]);
            a[r][c] = 0;
        }
        if (bad == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }


}