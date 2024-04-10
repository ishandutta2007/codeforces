#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int T, k;
bool done[26];
vi v, ans, ret;
string s,a,b;

vi oc[26][2];

int getFst(vi& v) {
    return sz(v) ? v[0] : MOD;
}

void ins(int par, int ind) {
    int c = s[ind]-'a';
    if (sz(oc[c][par]) > 1) return;
    if (par == 0) {
        if (sz(oc[c][par]) == 1 && a[oc[c][par][0]] == a[ind]) return;
    } else {
        if (sz(oc[c][par]) == 1 && b[oc[c][par][0]] == b[ind]) return;
    }
    oc[c][par].pb(ind);
}

bool check1() {
    int firstDif = sz(s);
    F0R(i,k) F0R(j,sz(oc[i][0])) {
        if (ans[i] != a[oc[i][0][j]]-'a') {
            ckmin(firstDif,oc[i][0][j]);
            break;
        }
    }
    if (firstDif == sz(s)) return 1;
    return a[firstDif]-'a' < ans[s[firstDif]-'a'];
}

bool check2() {
    int firstDif = sz(s);
    F0R(i,k) F0R(j,sz(oc[i][1])) {
        if (ans[i] != b[oc[i][1][j]]-'a') {
            ckmin(firstDif,oc[i][1][j]);
            break;
        }
    }
    if (firstDif == sz(s)) return 1;
    return b[firstDif]-'a' > ans[s[firstDif]-'a'];
}

void tri(int a, int b) {
    done[b] = 1; ans[a] = b;
}

void undo(int a) {
    done[ans[a]] = 0;
    ans[a] = -1;
}

int getNex(int lst) {
    while (lst < k && done[lst]) lst ++;
    if (lst == k) return MOD;
    return lst;
}

int co = 0;

void search(int ind, int b, int lst = 0) {
    if (sz(ret)) return;
    if (ind < k && sz(oc[v[ind]][0]) == 0) ind = k;
    
    if (ind == k) {
        // if (1) ret = ans;
        if (check1() && check2()) ret = ans;
        return;
    }
    
    if (oc[v[ind]][0].front() >= sz(s)) {
        pr(k,oc[v[ind]][0].front());
        exit(0);
    }
    if (b == 0) {
        int c = a[oc[v[ind]][0].front()]-'a';
        if (!done[c]) {
            tri(v[ind],c);
            search(ind+1,0);
            undo(v[ind]);
        }
        int t = getNex(c+1);
        if (t != MOD) {
            tri(v[ind],t);
            search(ind+1,1);
            undo(v[ind]);
        }
    } 
    lst = getNex(lst);
    tri(v[ind],lst);
    search(ind+1,1,lst);
    undo(v[ind]);
}

void solve() {
    re(k,s,a,b); 
    v.clear(); F0R(i,k) v.pb(i);
    ret.clear(); ans.resz(k);
    F0R(i,k) {
        done[i] = 0;
        ans[i] = -1;
    }
    F0R(i,k) F0R(j,2) oc[i][j].clear();
    F0R(i,sz(s)) F0R(j,2) ins(j,i);
    
    sort(all(v),[](int a, int b) { return getFst(oc[a][0]) < getFst(oc[b][0]); });
    search(0,0);
    if (sz(ret)) {
        pr("YES");
        F0R(i,k) done[i] = 0;
        trav(x,ret) if (x != -1) done[x] = 1;
        trav(x,ret) if (x == -1) {
            x = getNex(0);
            done[x] = 1;
        }
        trav(x,ret) cout << char('a'+x);
        pr("");
    } else pr("NO");
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); 
    re(T);
    F0R(i,T) solve();
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/