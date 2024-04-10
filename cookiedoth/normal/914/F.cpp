#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 1e5 + 100;
const int K = 26;
int n, q;
bitset<mx> a[K], res, full;
string s, s1;

int main()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        a[s[i] - 'a'][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        full[i] = 1;
    }
    cin >> q;
    for (int qn = 0; qn < q; ++qn) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            char c, c0;
            cin >> i >> c;
            i--;
            c0 = s[i];
            a[c0 - 'a'][i] = 0;
            a[c - 'a'][i] = 1;
            s[i] = c;
        }
        else {
            int l, r;
            cin >> l >> r >> s1;
            l--;
            r--;
            int slen = (r - l + 1), len = s1.length();
            if (slen < len) {
                cout << 0 << endl;
                continue;
            }
            res = full;
            for (int i = 0; i < len; ++i) {
                res = res & (a[s1[i] - 'a'] >> i);
                //cout << res << endl;
            }
            //cout << "ans " << l - 1 << " " << r - len + 1 << endl;
            int ans = (res >> l).count() - (res >> (r - len + 2)).count();
            cout << ans << endl;
        }
    }
    return 0;
}