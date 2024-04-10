#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const ll MD = (ll)1e9 + 9;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n,m;
int ans[5555][5555];
bool f[5555][5555];

void upd(int str, int stl, int zn)
{
    if (f[str][stl])
        ans[str][stl] = min(ans[str][stl], zn);
    else
    {
        ans[str][stl] = zn;
        f[str][stl] = true;
    }
}

int main()
{
    for (int i=0; i<5555; i++)
        for (int j=0; j<5555; j++)
            f[i][j] = false;
    cin >> n >> m;
    upd(0, 0, 0);
    for (int i=0; i<n; i++)
    {
        int cur;
        double notused;
        cin >> cur >> notused;
        for (int j=0; j<=m; j++)
            if (f[i][j])
            {
                if (cur < j)
                    upd(i+1, j, ans[i][j]+1);
                else
                if (cur == j)
                    upd(i+1, cur, ans[i][j]);
                else
                {
                    upd(i+1, j, ans[i][j]+1);
                    upd(i+1, cur, ans[i][j]);
                }
            }
    }
    int mn = ans[n][0];
    for (int i=1; i<=m; i++)
        mn = min(mn, ans[n][i]);
    cout << mn << endl;

    return 0;
}