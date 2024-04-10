#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int j = 0;
    while (s[j] == t[j]) j++;
    int k = n - 1;
    while (s[k] == t[k]) k--;
    if (j == k) {
        cout << 2 << endl;
        return 0;
    }
    int ans = 0;
    bool fl = true;
    for (int i = j; i < k; ++i) {
        if (s[i] != t[i + 1]) fl = false;
    }
    if (fl) ans++;
    fl = true;
    for (int i = j; i < k; ++i) {
        if (t[i] != s[i + 1]) fl = false;
    }
    if (fl) ans++;

    cout << ans << endl;

    return 0;
}