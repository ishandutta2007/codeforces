#include <iostream>
#include <vector>
using namespace std;

int ask(vector<int> a, vector<int> b)
{
    cout << "? " << a.size() << " " << b.size() << endl;
    for (int e : a)
        cout << e << " ";
    cout << endl;
    for (int e : b)
        cout << e << " ";
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> lefts = {1};
    vector<int> magnet(n + 1, 0);
    int scnd = 2;
    while (true) {
        if (ask(lefts, {scnd}) != 0)
            break;
        lefts.push_back(scnd++);
    }
    magnet[scnd] = true;
    for (int i = scnd + 1; i <= n; i++) {
        if (ask(lefts, {i}) != 0)
            magnet[i] = true;
    }
    int bottom = 1, top = scnd;
    while (top - bottom > 1) {
        int mid = (top + bottom) / 2;
        vector<int> l;
        for (int i = 1; i < mid; i++)
            l.push_back(i);
        if (!l.empty() && ask(l, {scnd}) != 0)
            top = mid;
        else
            bottom = mid;
    }
    magnet[bottom] = true;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (!magnet[i])
            ans.push_back(i);
    cout << "! " << ans.size();
    for (auto e : ans)
        cout << " " << e;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}