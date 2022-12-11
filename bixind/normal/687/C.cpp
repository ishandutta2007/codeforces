#include <iostream>
#include <set>

using namespace std;

const int MAXN = 510;

int d[MAXN][MAXN];
int d1[MAXN][MAXN];
int a[MAXN];

int main()
{
    int n, k, i, j, h;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    d[0][0] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= k; j++)
            for (h = 0; h <= j; h++)
        {
            d1[j][h] |= d[j][h];
            if (j + a[i] <= k)
            {
                d1[j + a[i]][h] |= d[j][h];
                d1[j + a[i]][h + a[i]] |= d[j][h];
            }
        }
        swap(d, d1);
    }
    set<int> s;
        for (j = 0; j <= k; j++)
        if (d[k][j])
        s.insert(j);
    cout << s.size() << endl;
    for (auto w : s)
        cout << w << ' ';
    cout << endl;
    return 0;
}