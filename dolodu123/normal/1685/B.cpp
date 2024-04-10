#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 500005, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int a, b, ab, ba;
        string s;
        cin >> a >> b >> ab >> ba >> s;
        if (count(all(s), 'A') != a + ab + ba || count(all(s), 'B') != b + ab + ba) {
            cout << "NO\n";
            continue;
        }
        int n = s.length();
        vector <int> split = {0};
        for (int i = 0; i + 1 < n; ++i) if (s[i] == s[i + 1])
            split.pb(i + 1);
        split.pb(n);
        vector <string> t;
        for (int i = 1; i < split.size(); ++i) {
            t.pb(s.substr(split[i - 1], split[i] - split[i - 1]));
        }
        int atleast = 0;
        vector <int> abcnt, bacnt;
        for (auto s : t) {
            if (s.length() == 1)
                continue;
            if (int(s.length()) % 2 == 0) {
                atleast += int(s.length()) / 2 - 1;
                if (s[0] == 'A' && s[1] == 'B')
                    abcnt.pb(int(s.length()) / 2);
                else
                    bacnt.pb(int(s.length()) / 2);
            } else {
                atleast += int(s.length()) / 2;
            }
        }
        int need = ab + ba - atleast;
        if (need <= 0) {
            cout << "YES\n";
        } else {
            int c = 0;
            sort(all(abcnt));
            for (int i : abcnt) {
                if (i <= ab)
                    ab -= i, c++;
                else
                    break;
            }
            sort(all(bacnt));
            for (int i : bacnt) {
                if (i <= ba)
                    ba -= i, c++;
                else
                    break;
            }
            cout << (need <= c ? "YES\n" : "NO\n");
        }
    }
}