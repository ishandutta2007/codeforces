#include <bits/stdc++.h>

using namespace std;

string rep(string a)
{
    reverse(a.begin(), a.end());
    while ((int) a.size() > 1 && a.back() == '0')
    {
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    a = rep(a);
    b = rep(b);
    if (a == b)
    {
        cout << "=\n";
        return 0;
    }
    if ((int) a.size() < (int) b.size() || ((int) a.size() == (int) b.size() && a < b))
    {
        cout << "<\n";
    }
    else
    {
        cout << ">\n";
    }
}