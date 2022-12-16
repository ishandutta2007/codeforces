#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1e9+7;

ll alen, len;
char s[1001000];

void solve() {
    ll x;
    cin >> x;
    cin >> s;
    alen = len = strlen(s);
    //cerr << " len " << len << endl;
    for (int i=0; i<x;) {
        i+=1;
        ll xf = len-i;
        int amt = s[i-1]-'1';
        int fin = len + amt*xf;
        int j = 0;
        while (alen < x && alen < fin) {
            //cerr << "    ? " << i << " " << j << " " << i+j%xf << endl;
            s[alen++] = s[i+j%xf];
            ++j;
        }
        //cerr << " amt " << amt << " xf " << xf << endl;
        //cerr << "  " << s << endl;
        len = (len+amt*xf+MOD*4)%MOD;
    }
    cout << len << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}