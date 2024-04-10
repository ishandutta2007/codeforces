#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------
// from https://oj.uz/submission/572571
int send(int s);
int receive();
typedef long long ll;
 
using namespace std;
 
struct interval {
  ll l, r;
  interval(ll l, ll r) : l(l), r(r) {}
  bool contains(ll x) {
    return l <= x && x < r;
  }
  ll length() {
    return r - l;
  }
  interval shrink(ll o, ll s) {
    return interval(min(r, l + o), min(r, l + o + s));
  }
};
 
vector<interval> splitIntervals(vector<interval> c, ll o, ll s) {
  vector<interval> r;
  for (interval &it : c) {
    if (s > 0 && it.length() - o > 0)
      r.push_back(it.shrink(o, s));
    s -= max(0LL, min(s, it.length() - o));
    o -= min(o, it.length());
  }
  return r;
}
 
bool contains(vector<interval> c, ll x) {
  for (interval &it : c)
    if (it.contains(x))
      return true;
  return false;
}
 
struct state {
  ll s[2] = {0, 0};
  vector<vector<interval>> c;
  state(ll N): c(2) {
    s[1] = N;
    c[1].emplace_back(1, N + 1);
  }
  state(vector<vector<vector<interval>>> &cs): c(2) {
    for (int g = 0; g < 2; g++)
      for (vector<interval> &c : cs[g])
        add(g, c);
  }
  void add(int g, interval it) {
    s[g] += it.length();
    c[g].push_back(it);
  }
  void add(int g, vector<interval> &c) {
    for (interval &it : c)
      add(g, it);
  }
  vector<vector<vector<interval>>> split() {
    vector<vector<vector<interval>>> r(2);
    for (int g = 0; g < 2; g++) {
      int s1 = (s[g] + g) / 2, s2 = s[g] - s1;
      r[g].push_back(splitIntervals(c[g], 0, s1));
      r[g].push_back(splitIntervals(c[g], s1, s2));
    }
    return r;
  }
  ll size() {
    return s[0] + s[1];
  }
  vector<ll> remaining() {
    vector<ll> r;
    for (int g = 0; g < 2; g++)
      for (interval &it : c[g])
        for (ll v = it.l; v < it.r; v++)
          r.push_back(v);
    return r;
  }
};
 
 int read() {
    string s;
    cin >> s;
    return s == "YES";
 }
std::pair<int, int> solve(int N, int X = -1) {
  state s(N);
  while (s.size() > 3) {
    vector<vector<vector<interval>>> c = s.split();
    vi qq(N+1);
    for (interval &it : c[0][0]) {
        for (int i = it.l; i < it.r; i++) qq[i] = 1;
    }
    for (interval &it : c[1][0]) {
        for (int i = it.l; i < it.r; i++) qq[i] = 1;
    }
    vi vv;
    for (int i = 1; i <= N; i++) {
        if (qq[i]) vv.pb(i);
    }
    cout << "? " << vv.size();
    for (int v: vv) cout << " " << v;
    cout << endl;
    int b;
    b = read();
    //int b = X != -1 ? send(contains(c[0][0], X) || contains(c[1][0], X)) : receive();
    c[0].erase(c[0].begin() + b);
    swap(c[0][0], c[1][b]);
    s = state(c);
  }
  vector<ll> r = s.remaining();
  if ((int) r.size() == 3) {
    int b1 = 1, b2;
    for (int i = 0; i < 2 && b1; i++) {
        cout << "? 2 " << r[0] << " " << r[1] << endl;
        b1 = read();
    }
      //b1 = X != -1 ? send(r[0] == X || r[1] == X) : receive();
    if (!b1) {
        cout << "? 1 " << r[0] << endl;
        b2 = read();
    }
      //b2 = X != -1 ? send(r[0] == X) : receive();
    r.erase(r.begin() + (b1 ? 2 : (b2 ? 1 : 0)));
  }
  return {r[0], r.back()};
}

int main() {
    int N;
    cin >> N;
    string s;
    if (N == 1) {
        cout << "! 1" << endl;
        cin >> s;
        return 0;
    }
    else if (N == 2) {
        cout << "! 1" << endl;
        cin >> s;
        if (s == ":(") {
            cout << "! 2" << endl;
            cin >> s;
        }
        return 0;
    }
    pii p = solve(N);
    cout << "! " << p.first << endl;
    cin >> s;
    if (s == ":(") {
        cout << "! " << p.second << endl;
        cin >> s;
    }
    return 0;
}