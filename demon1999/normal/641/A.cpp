#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int maxn = 200000;

int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int c = 0;
    for (int i = 0; i < n + 2; ++i) {
        int x;
        if (s[c] == '>') x = c + a[c];
        else x = c - a[c];
        if (x < 0 || x >= n) {
            cout << "FINITE" << endl;
            return 0;
        }
        c = x;
    }
    cout << "INFINITE" << endl;

    return 0;
}