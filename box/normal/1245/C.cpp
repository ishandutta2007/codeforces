#include <bits/stdc++.h>
#define MOD 1000000007ull
using namespace std;

int f[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2; f[3] = 3;
    for(int i=4; i <= 100004; i++) f[i] = (f[i-1] + f[i-2]) % MOD;
    long long tot = 1;
    string s; cin >> s;
    int chlen = 0;
    if(s[0] == 'u' || s[0] == 'n') chlen++;
    for(int i=1; i<s.length(); i++) {
        if(s[i] != s[i-1]) {
            tot = (tot * f[chlen]) % MOD;
            chlen = 0;
            if(s[i] == 'u' || s[i] == 'n') chlen++;
        } else if(s[i] == 'u' || s[i] == 'n') chlen++;
    }
    tot = (tot * f[chlen]) % MOD;
    for(int i=0; i<s.length(); i++) if(s[i] == 'm' || s[i] == 'w') tot = 0;
    cout << tot << endl;
}