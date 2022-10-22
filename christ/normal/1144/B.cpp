#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int tot = 0;
    scanf("%i", &n);
    vector<int> ev, od;
    for (int x = 0; x < n; x++)
    {
        int a;
        scanf("%i", &a);
        tot += a;
        if (a&1)
            od.push_back(a);
        else
            ev.push_back(a);
    }
    sort(od.rbegin(), od.rend());
    sort(ev.rbegin(), ev.rend());
    for (int x = 0; x < min(od.size(), ev.size()); x++)
        tot -= od[x] + ev[x];
    if (ev.size() > od.size())
        tot -= ev[od.size()];
    else if (ev.size() < od.size())
        tot -= od[ev.size()];
    cout << tot << endl;
}