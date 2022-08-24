#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int e = 0;
    for (int i=0; i < s.size(); i++) if (s[i] == '8') e++;
    e = min(e, (int)s.size() / 11);
    cout << e;
}