#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, i;
    cin >> n;
    vector<pair<string, string>> m(n);
    vector<pair<int, int>> k(n);
    pair<int, int> el;
    pair<string, string> p;
    string last;
    for (i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;
        m[i] = p;
    }
    int a;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        el.second = a - 1;
        el.first = i;
        k[i] = el;
    }
    sort(k.begin(), k.end());
    bool fl = true;
    p = m[k[0].second];
    last = p.first < p.second ? p.first : p.second;
    for (i = 1; i < n; i++)
    {
        p = m[k[i].second];
        if (p.second < p.first) swap(p.second, p.first);
        if (p.first > last) last = p.first;
        else
        {
            if (p.second > last) last = p.second;
            else{fl = false; break;}
        }
    }
    if (fl) cout << "YES"; else cout << "NO";
    return 0;
}