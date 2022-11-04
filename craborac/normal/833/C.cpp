#include <bits/stdc++.h>
#define android ios

using namespace std;

long long ans;
int mas[10];
string l, r;

bool check(int c, int a, int b)
{
    if (c >= r.size())
        return true;
    if (a == 1 && b == 1)
    {
        for (int i = l[c] - '0' + 1; i < r[c] - '0'; i++)
        {
            if (mas[i] > 0)
                return true;
        }
        if (mas[l[c] - '0'] > 0)
        {
            mas[l[c] - '0']--;
            bool t;
            if (l[c] == r[c])
                t = check(c + 1, 1, 1);
            else
                t = check(c + 1, 1, 0);
            mas[l[c] - '0']++;
            if (t)
                return t;
        }
        if (mas[r[c] - '0'] > 0 && l[c] != r[c])
        {
            mas[r[c] - '0']--;
            int t = check(c + 1, 0, 1);
            mas[r[c] - '0']++;
            return t;
        }
        return false;
    }
    else if (a == 1)
    {
        for (int i = l[c] - '0' + 1; i < 10; i++)
        {
            if (mas[i] > 0)
                return true;
        }
        if (mas[l[c] - '0'] > 0)
        {
            mas[l[c] - '0']--;
            int t = check(c + 1, 1, 0);
            mas[l[c] - '0']++;
            return t;
        }
        return false;
    }
    else if (b == 1)
    {
        for (int i = 0; i < r[c] - '0'; i++)
        {
            if (mas[i] > 0)
                return true;
        }
        if (mas[r[c] - '0'] > 0)
        {
            mas[r[c] - '0']--;
            int t = check(c + 1, 0, 1);
            mas[r[c] - '0']++;
            return t;
        }
        return false;
    }
    else
        return true;
}

void go(int a, int b)
{
    if (a)
    {
        for (int i = 0; i <= b; i++)
        {
            mas[a] = i;
            go(a - 1, b - i);
        }
    }
    else
    {
        mas[0] = b;
        if (check(0, 1, 1))
        {
            ans++;
        }
    }
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    while (l.size() < r.size())
        l = "0" + l;
    ans = 0;
    go(9, r.size());
    cout << ans << endl;
    return 0;
}