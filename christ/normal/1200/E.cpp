#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e6+5, BASE = 131, MOD = 999997771;
string a,b;
ll hsh[MN], pw[MN];
ll substr (int l, int r) {
    return ((hsh[r] - hsh[l-1] * pw[r-l+1])%MOD+MOD)%MOD;
}
void merge () {
    ll bhsh = b[0];
    int alast = a.length()-1;
    int len = bhsh == substr(alast,alast);
    for (int i = 1; i < b.length() && alast-i >= 0; i++) {
        bhsh = (bhsh * BASE + b[i])%MOD;
        if (bhsh == substr(alast-i,alast)) len = i+1;
    }
    for (int i = len; i < b.length(); i++) {
        a += b[i];
        hsh[a.length()-1] = (hsh[a.length()-2] * BASE + b[i])%MOD;
    }
}
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin >> a;
    pw[0] = 1, hsh[0] = a[0];
    for (int i = 1; i < MN; i++) pw[i] = pw[i-1] * BASE % MOD;
    for (int i = 1; i < a.length(); i++) hsh[i] = (hsh[i-1] * BASE + a[i])%MOD;
    for (int i = 1; i < n; i++) {
        cin >> b;
        merge();
    }
    cout << a << '\n';
    return 0;
}