#include <bits/stdc++.h>


#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
#define prev previouss
using namespace std;


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

ll k1, k2, n;
vector<ll> a, b;
string qq;
char sign, p;
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("division.in", "r",  stdin));
    cin >> p;
    k1++;
    qq = "+";
    while (true) {
        cin >> p;
        if (p == '=') break;
        qq += p;
        assert(p != '?');
        if (p == '+') {
            k1++;
        }
        else k2++;
        cin >> p;
    }
    cin >> n;
    a.resize(0);
    b.resize(0);
    forn (i, k1)
        a.push_back(1);
    forn (j, k2) {
        b.push_back(n);
    }
    ll sum = k1 - k2 * n;
    if (sum > n) {
        cout << "Impossible";
        re 0;
    }
    //cout << k1 << " " << k2 << " " << sum << " " << sz(b) << " " << sz(a) << endl;
    ll i = 0, pp;
    while (sum < n && i < k1 + k2) {
        //cout << i << " " << sum << " " << endl;
        if (i < k1) {
            pp = n - a[i];
            if (sum + pp > n) pp = n - sum;
            a[i] += pp;
            sum += pp;
            if (a[i] == n) i++;
        }
        else {
            pp = n - sum;
            if (b[i - k1] - pp < 1) {
                pp = b[i - k1] - 1;
            }
            //cout << pp << " " << i - k1 << " " << sz(b) << endl;
            b[i - k1] -= pp;
            sum += pp;
            if (b[i - k1] == 1) i++;
            continue;
        }
    }
    //assert(sum <= n);
    if (sum != n) {
        cout << "Impossible";
        re 0;
    }
    int k = 0, j = 0;
    cout << "Possible\n";
    sum = 0;
    forn (i, sz(qq)) {
        if (i) cout << " " << qq[i] << " ";
        if (qq[i] == '+') {
            sum += a[k];
            //assert(a[k] >= 1);
            //assert(a[k] <= n);
            cout << a[k]; k++;
        }
        else {
            //assert(b[j] >= 1);
            //assert(b[j] <= n);
            sum -= b[j];
            cout << b[j];
            j++;
        }
    }
    //assert(sum == n);
    cout << " = " << n;
    return 0;
}