#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a;
int b;
int c;
int sol;
int pot1;
int pot2;
multiset<int> s;


int lungime()
{
    return (int) s.size();
}

int mare()
{
    if (lungime() == 0)
    {
        cout << "eroare\n";
        exit(0);
    }
    auto it = s.end();
    it--;
    return *it;
}

int maxim_sub(int x)
{
    auto it = s.lower_bound(x + 1);
    if (it == s.begin())
    {
        return -1;
    }
    else
    {
        it--;
        return *it;
    }
}

void sterge(int val)
{
    pot1 -= (val <= a + b);
    pot2 -= (val <= c);
    s.erase(s.find(val));
}

int func()
{
    int mn = min(pot1, pot2);
    int mx = max(pot1, pot2);
    /// 1...mn
    /// 1..........mx
    int only_mx = mx - mn;
    int com = mn;
    int sol = 0;
    int t = min(com, only_mx);
    com -= t;
    only_mx -= t;
    sol += t;
    sol += only_mx;
    sol += (com + 1) / 2;
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (a + b + c < mare())
    {
        cout << "-1\n";
        return 0;
    }
    if (b < a)
    {
        swap(a, b);
    }
    if (c < a)
    {
        swap(a, c);
    }
    if (c < b)
    {
        swap(b, c);
    }
    for (auto &x : s)
    {
        pot1 += (x <= a + b);
        pot2 += (x <= c);
    }
    /// a + b + c, b + c, a + c, max(c, a + b)
    while (lungime() > 0 && b + c < mare())
    {
        sol++;
        sterge(mare());
    }
    while (lungime() > 0 && a + c < mare())
    {
        sol++;
        sterge(mare());
        if (maxim_sub(a) != -1)
        {
            sterge(maxim_sub(a));
        }
    }
    while (lungime() > 0 && max(c, a + b) < mare())
    {
        sol++;
        sterge(mare());
        if (maxim_sub(b) != -1)
        {
            sterge(maxim_sub(b));
        }
    }
    int best = (int) 1e9, cur = 0;
    best = min(best, cur + func());
    while (1)
    {
        int init = (int) s.size();
        if (maxim_sub(a) != -1)
        {
            sterge(maxim_sub(a));
        }
        if (maxim_sub(b) != -1)
        {
            sterge(maxim_sub(b));
        }
        if (maxim_sub(c) != -1)
        {
            sterge(maxim_sub(c));
        }
        cur++;
        best = min(best, cur + func());
        if ((int) s.size() == init)
        {
            break;
        }
    }
    cout << sol + best << "\n";
}
/**
7 8
  b   b   b
x x x x x x x
y y y y y y y y
a   a   a   a
**/