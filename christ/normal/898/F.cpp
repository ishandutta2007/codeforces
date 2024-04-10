#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+3, MA = 1e4 + 3;
using ll = long long;
const ll MOD = 10000000000000061LL;
ll hsh[MN], pw[MN];
char s[MN];
void uadd (ll &a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
}
ll madd (ll a, ll b) {
    a += b;
    return a >= MOD ? a-MOD : a;
}
ll mul (ll a, ll b) {
    if (a < b) swap(a,b);
    ll res = 0;
    while (b) {
        if (b&1) uadd(res,a);
        uadd(a,a);
        b>>=1;
    }
    return res;
}
ll substr (int l, int r) {
    return madd(hsh[r]-mul(hsh[l-1],pw[r-l+1]),MOD);
}
int main() {
    scanf ("%s",s+1);
    int n = strlen(s+1); pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        hsh[i] = (hsh[i-1]*10+s[i]-'0')%MOD;
        pw[i] = pw[i-1]*10%MOD;
    }
    vector<int> splits;
    for (int suf = n; suf >= 3; suf--) {
        int len = n-suf+1;
        int pre = suf-1;
        if (pre < len) break;
        //length of longest increases by at most one
        if ((pre+1)/2 > len) continue;
        ll sufhsh = substr(suf,n);
        splits = {len,len-1,pre-len,pre-len+1};
        for (int sp : splits) {
            if (sp+1 <= pre && sp >= 1 && (s[1] != '0' || sp == 1) && (s[sp+1] != '0' || sp+1 == pre) && madd(substr(1,sp),substr(sp+1,pre)) == sufhsh) {
                for (int i = 1; i <= sp; i++) putchar(s[i]);
                putchar('+');
                for (int i = sp+1; i <= pre; i++) putchar(s[i]);
                putchar('=');
                for (int i = suf; i <= n; i++) putchar(s[i]);
                putchar('\n');
                return 0;
            }
        }
    }
    return 0;
}