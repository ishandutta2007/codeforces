#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin >> a;
    for (int i=0; i < a.size(); i++) cout << a[i];
    for (int i=0; i < a.size(); i++) cout << a[a.size() - i - 1];
}