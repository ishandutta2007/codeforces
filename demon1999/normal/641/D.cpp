
 #include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n, m;
vector<double> ma, mi, a, b;

void rsh(int i, double b1, double a1, double c1, double b2, double a2, double c2) {
    double A = 1.000000000, B = b2 - a2 - c2 - c1, C = a2 * (c2 + c1) - c2;
    double D = max (B * B - 4.000000000 * C, double(0));
    b[i] = (-B + sqrt(D)) / (2.000000000);
    a[i] = c2 + c1 - b[i];
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("a.in", "r",  stdin));
    cin >> n;
    ma.resize(n);
    mi.resize(n);
    b.resize(n);
    a.resize(n);
    forn (i, n)
        cin >> ma[i];
    forn (i, n)
        cin >> mi[i];
    double k1 = 0, k2 = 0, k3 = 1, k4 = 1;
    forn (i, n) {
        rsh(i, k1, k2, ma[i], k3, k4, mi[i]);
        k1 += a[i];
        k2 += b[i];
        k3 -= a[i];
        k4 -= b[i];
    }
    cout.precision(30);
    forn (i, n)
        cout << a[i] << " ";
    cout << "\n";
    forn (j, n)
        cout << b[j] << " ";
    return 0;
}