#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get(ll x)
{
    vector<int> a;
    while (x)
    {
        a.push_back(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

int calc(vector<int> a)
{
    int ans = 0;
    for (auto &c : a)
    {
        ans += c;
    }
    return ans;
}

vector<int> ans;

void upd(vector<int> a)
{
    if (calc(a) > calc(ans))
    {
        ans = a;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<int> a = get(n);
    ans = a;
    int sz = (int) a.size();

    for (int p = sz - 2; p >= -1; p--)
    {
        vector<int> b;
        for (int j = 0; j <= p; j++)
        {
            b.push_back(a[j]);
        }
        if (a[p + 1] >= 1 + (p == -1))
        {
            b.push_back(a[p + 1] - 1);
            for (int j = p + 2; j < sz; j++)
            {
                b.push_back(9);
            }
            upd(b);
        }
    }

    vector<int> b;
    for (int i = 0; i < sz - 1; i++)
    {
        b.push_back(9);
    }

    upd(b);

    for (auto &x : ans)
    {
        cout << x;
    }
    cout << "\n";

}