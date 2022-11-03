#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}



int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  sort(all(v));
  string s;
  cin >> s;

  deque<int> a, b;
  ll A = 0, B = 0;

  for (auto x : v) {
    if (A <= B) {
      a.pb(x);
      A += x;
    }
    else {
      b.pb(x);
      B += x;
    }
  }


  if (s.back() == 'L') {
    if (A < B) {
      swap(A, B);
      swap(a, b);
    }
  }

  else {
    if (A > B) {
      swap(A, B);
      swap(a, b);
    }
  }


  vector<pair<int, int> > ans;
  int cur = n;

  while (cur >= 2) {
    if (s[cur - 1] != s[cur - 2]) {
      if (A > B) {
        ans.pb(mp(a.back(), 0));
        A -= a.back();
        a.pop_back();
      }
      else {
        ans.pb(mp(b.back(), 1));
        B -= b.back();
        b.pop_back();
      }
      cur--;
    }
    else if (cur == 2 || s[cur - 1] == s[cur - 3]) {
      if (A > B) {
        ans.pb(mp(b.back(), 1));
        ans.pb(mp(a.back(), 0));
        A -= a.back();
        B -= b.back();
        a.pop_back();
        b.pop_back();
      }
      else {
        ans.pb(mp(a.back(), 0));
        ans.pb(mp(b.back(), 1));
        A -= a.back();
        B -= b.back();
        a.pop_back();
        b.pop_back();
      }
      cur -= 2;
    }
    else {
      if (A > B) {
        if (a.size() > b.size()) {
          ans.pb(mp(a.front(), 0));
          ans.pb(mp(a.back(), 0));
          A -= a.back();
          A -= a.front();
          a.pop_back();
          a.pop_front();
        }
        else {
          ans.pb(mp(b.front(), 1));
          ans.pb(mp(a.back(), 0));
          A -= a.back();
          B -= b.front();
          b.pop_front();
          a.pop_back();
        }
      } 
      else {
        if (b.size() > a.size()) {
          ans.pb(mp(b.front(), 1));
          ans.pb(mp(b.back(), 1));
          B -= b.back();
          B -= b.front();
          b.pop_back();
          b.pop_front();
        }
        else {
          ans.pb(mp(a.front(), 0));
          ans.pb(mp(b.back(), 1));
          B -= b.back();
          A -= a.front();
          a.pop_front();
          b.pop_back();
        }
      }
      cur -= 2;
    }
  }

  if (cur == 1) {
    if (a.size()) ans.pb(mp(a.back(), 0));
    else ans.pb(mp(b.back(), 1));
  }

  reverse(all(ans));
  for (auto x : ans) {
    cout << x.x << " ";
    if (x.y == 0) cout << "L\n";
    else cout << "R\n";
  }

}