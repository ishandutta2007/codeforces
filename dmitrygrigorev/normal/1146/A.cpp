#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int a = 0;
    for (int i=0; i < s.size(); i++) if (s[i] == 'a') a++;
    cout << min(2*a-1, (int) s.size());
}