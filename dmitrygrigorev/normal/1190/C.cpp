#include<bits/stdc++.h>
#define int long long
using namespace std;
string F = "tokitsukaze", S = "quailty", Dr = "once again";
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool D = false;
    for (int i=1; i < n; i++){
        if (s[i] != s[i-1]){
            D = true;
        }
    }
    if (!D){
        cout << F;
        return 0;
    }
    int ld = -1;
    for (int i=1; i < n; i++){
        if (s[i] != s[i-1]){
            ld = i;
            break;
        }
    }
    int rd = -1;
    for (int i=n-1; i >= 1; i--){
        if (s[i] != s[i-1]){
            rd = i;
            break;
        }
    }
    if (ld==rd){
        int L = ld, R = n-ld;
        if (min(L, R) <= k){
            cout << F << endl;
            return 0;
        }
        cout << Dr << endl;
        return 0;
    }
    int mn = min(n-ld, rd);
    if (mn <= k){
        cout << F << endl;
        return 0;
    }
    int delta = rd-ld;
    if (delta > k){
        cout << Dr << endl;
        return 0;
    }
    if (s[ld-1] == s[rd]){
        cout << F << endl;
        return 0;
    }
    int L = max(n-1-ld, rd-1);
    if (L > k){
        cout << Dr << endl;
        return 0;
    }
    cout << S << endl;
    return 0;
}