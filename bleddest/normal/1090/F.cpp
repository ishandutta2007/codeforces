#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const int N = 1043;

int n;
li a[N];
li b[11];

vector<int> w[10];

li findsum(vector<int> a)
{
    sort(all(a));
    forn(i, 10) if(w[i] == a) return b[i];
    return 0;
}

bool comp(int x, int y)
{
    if(x == y) return false;
    forn(i, 5) forn(j, i)
    {
            if(i == x || i == y || j == x || j == y)
                continue;
            vector<int> ww = {i, j, x};
            vector<int> ww2 = {i, j, y};
            li aa = findsum(ww);
            li bb = findsum(ww2);
            if(aa != bb)
                return aa < bb;
    }
    return false;
}

li ask(int a, int b, int c)
{
    cout << "? " << a << " " << b << " " << c << endl;
    li ans;
    cin >> ans;
    return ans;
}

void solve5(int x)
{
    forn(i, 10) b[i] = ask(w[i][0] + x + 1, w[i][1] + x + 1, w[i][2] + x + 1);
    vector<int> ng = {0, 1, 2, 3, 4};
    sort(all(ng), comp);
//    cerr << ng << endl;
    a[ng[0] + x] = (findsum({ng[0], ng[1], ng[2]}) + findsum({ng[0], ng[1], ng[4]}) - findsum({ng[2], ng[3], ng[4]})) / 2;
    a[ng[2] + x] = findsum({ng[0], ng[1], ng[2]}) - a[ng[0] + x];
    a[ng[3] + x] = findsum({ng[0], ng[1], ng[3]}) - a[ng[0] + x];
    a[ng[4] + x] = findsum({ng[0], ng[1], ng[4]}) - a[ng[0] + x];
    a[ng[1] + x] = findsum({ng[1], ng[2], ng[3]}) - a[ng[3] + x];
}

bool read() {
    cin >> n;
    return true;
}

void solve() {
    w[0] = {0, 1, 2};
    w[1] = {0, 1, 3};
    w[2] = {0, 1, 4};
    w[3] = {0, 2, 3};
    w[4] = {0, 2, 4};
    w[5] = {0, 3, 4};
    w[6] = {1, 2, 3};
    w[7] = {1, 2, 4};
    w[8] = {1, 3, 4};
    w[9] = {2, 3, 4};
    forn(i, n / 5)
        solve5(i * 5);
    if(n % 5 > 0)
        solve5(n - 5);
    cout << "!";
    forn(i, n) cout << " " << a[i];
    cout << endl;
}

int main() {
#ifdef _DEBUG
    //freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}