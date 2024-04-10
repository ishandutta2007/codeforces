#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int A = 1, B = 0, C = 0, D = 0;
    for (int i=0; i < s.size(); i++){
        if (i > 0 && s[i] == 'v' && s[i-1] == 'v'){
            D += C;
            B += A;
        }
        if (s[i] == 'o') C += B;
    }
    cout << D;
}