#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
int n, xx, yy;
int x[N];
int y[N];

bool on(int r1, int c1, int r2, int c2, int r, int c)
{
    return min(r1, r2) <= r && r <= max(r1, r2) && min(c1, c2) <= c && c <= max(c1, c2);
}

vector<int> get(int r, int c)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (on(xx, yy, x[i], y[i], r, c))
        {
            ans.push_back(i);
        }
    }
    ans.push_back(r);
    ans.push_back(c);
    return ans;
}

vector<int> best(vector<int> a, vector<int> b)
{
    if ((int) a.size() > (int) b.size())
    {
        return a;
    }
    else
    {
        return b;
    }
}

vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> xx >> yy;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ans = best(ans, get(xx - 1, yy));
    ans = best(ans, get(xx + 1, yy));
    ans = best(ans, get(xx, yy - 1));
    ans = best(ans, get(xx, yy + 1));
    int c = ans.back();
    ans.pop_back();
    int r = ans.back();
    ans.pop_back();
    cout << (int) ans.size() << "\n";
    cout << r << " " << c << "\n";
}