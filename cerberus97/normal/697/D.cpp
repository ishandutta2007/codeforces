#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int p[100005], sub[100005] = {0};
double ans[100005], temp[100005];
vector <int> g[100005];

void calcSub(int i)
{
    sub[i] = 1;
    temp[i] = 0;

    for (vector <int>::iterator j = g[i].begin(); j != g[i].end(); ++j)
    {
        calcSub(*j);
        sub[i] += sub[*j];
        temp[i] += sub[*j]/2.0;
    }
}

void calcAns(int cur)
{
    ans[cur] = 1;

    if (cur != 1)
    {
        int par = p[cur];
        ans[cur] = ans[par] + 1 + temp[par] - sub[cur]/2.0;
    }

    for (vector <int>::iterator i = g[cur].begin(); i != g[cur].end(); ++i)
        calcAns(*i);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    calcSub(1);
    calcAns(1);

    for (int i = 1; i <= n; ++i)
        cout << fixed << setprecision(6) << ans[i] << ' ';

    return 0;
}