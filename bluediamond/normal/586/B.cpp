/**
 *
 * With Love from New York
 *
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 50 + 7;

int n;
int a[2][N];
int b[N];

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        for(int i = 1; i < n; i++)
        {
                cin >> a[0][i];
        }
        for(int i = 1; i < n; i++)
        {
                cin >> a[1][i];
        }
        for(int i = 1; i <= n; i++)
        {
                cin >> b[i];
        }
        vector <int> vals;
        for(int i = 1; i <= n; i++)
        {
                int cost = 0;
                for(int j = 1; j < i; j++)
                {
                        cost += a[0][j];
                }
                cost += b[i];
                for(int j = i; j < n; j++)
                {
                        cost += a[1][j];
                }
                vals.push_back(cost);
        }
        sort(vals.begin(), vals.end());
        int res = vals[0] + vals[1];
        cout << res << "\n";
        return 0;
}
/**

**/