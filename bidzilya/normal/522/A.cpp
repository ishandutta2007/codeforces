#include <bits/stdc++.h>
using namespace std;

void ToLower(string& s)
{
    for (int i = 0; i < (int) s.length(); ++i) {
        s[i] = tolower(s[i]);
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> a;
    a["polycarp"] = 1;
    int mx = 1;
    for (int i = 0; i < n; ++i) {
        string name1, name2;
        cin >> name1 >> name2 >> name2;
        ToLower(name1);
        ToLower(name2);
        a[name1] = a[name2] + 1;
        mx = max(mx, a[name1]);
    }

    cout << mx << endl;

    return 0;
}