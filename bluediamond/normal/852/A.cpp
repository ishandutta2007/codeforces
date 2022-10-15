#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937 rng((long long) (new char));

string get(ll x)
{
    if (x == 0)
    {
        return "0";
    }
    string sol;
    while (x)
    {
        sol += (char) ('0' + x % 10);
        x /= 10;
    }
    reverse(sol.begin(), sol.end());
    return sol;
}


vector<string> all;

void op(string s, int step)
{
    if (step == 4)
    {
        if ((int) s.size() > 1)
        {
            return;
        }
        for (auto &t : all)
        {
            cout << t << "\n";
        }
        exit(0);
    }
    ll sum = 0, cur = 0;
    string t;
    int n = (int) s.size();
    for (int i = 0; i < n; i++)
    {
        t += s[i];
        cur = 10 * cur + s[i] - '0';
        if (rng() % 10 && i != n - 1)
        {
            sum += cur;
            cur = 0;
            t += "+";
        }
    }
    sum += cur;
    all.push_back(t);
    op(get(sum), step + 1);
    all.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    while (1)
    {
        op(s, 1);
    }

}