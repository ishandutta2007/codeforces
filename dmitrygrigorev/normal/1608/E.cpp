#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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

int ans = 0;

void get(vector<tuple<int, int, int> > v) {
  
  sort(all(v));
  ordered_set twos;
  ordered_set ones;
  ordered_set ktwos;
  ordered_set kones;

  int cnt = v.size() / 3;
  int s = 0;

  while (s < v.size()) {
    int f = s;
    while (f < v.size() && get<0>(v[f]) == get<0>(v[s])) f++;
    for (int i = s; i < f; ++i) {
      if (get<2>(v[i]) == 0) cnt--;
      else if (get<2>(v[i]) == 1) {
        ones.insert(mp(get<0>(v[i]), get<1>(v[i])));
        kones.insert(mp(get<1>(v[i]), get<0>(v[i])));
      }
      else {
        twos.insert(mp(get<0>(v[i]), get<1>(v[i])));
        ktwos.insert(mp(get<1>(v[i]), get<0>(v[i])));
      }
    }

    for (int want = cnt; want >= cnt && want > ans; --want) {
      if (twos.size() >= want && ones.size() >= want) {
        auto p1 = *ones.find_by_order(want - 1);
        auto p2 = *twos.find_by_order(twos.size() - want);
        if (p1.x < p2.x) ans = max(ans, want); 
      }
      if (ktwos.size() >= want && kones.size() >= want) {
        auto p1 = *kones.find_by_order(want - 1);
        auto p2 = *ktwos.find_by_order(twos.size() - want);
        if (p1.x < p2.x) ans = max(ans, want); 
      }
    }

    s = f;
  }


}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<tuple<int, int, int> > v(n);
  for (auto &x : v) {
    cin >> get<0>(x) >> get<1>(x) >> get<2>(x);
    get<2>(x)--;
  }

  for (int sw = 0; sw < 2; ++sw) {
    for (int r = 0; r < 2; ++r) {
      vector<int> perm;
      for (int i = 0; i < 3; ++i) perm.pb(i);
      do {
        vector<tuple<int, int, int> > t;
        for (auto x : v) {
          get<2>(x) = perm[get<2>(x)];
          if (sw) swap(get<0>(x), get<1>(x));
          if (r) {
            get<0>(x) *= -1;
          }
          t.pb(x);
        }
        get(t);
      }
      while (next_permutation(all(perm)));
    }
  }

  cout << 3*ans;

}