#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

#define maxn 101010
#define rem ((llong)1e9+7)
int n;
llong x, y;
ii a[maxn];

struct query {
  int type, id;
  llong pos;
  query() {}
  query(int _type, int _id, llong _pos): type(_type), id(_id), pos(_pos) {}
};

vector<query> qr;

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> x >> y;
  rep1(i, n) {
    cin >> a[i].xx >> a[i].yy;
    qr.push_back(query(1, i, a[i].xx));
    qr.push_back(query(2, i, a[i].yy));
  }

  sort(qr.begin(), qr.end(), [](const query& u, const query& v) {
      llong t = u.pos - v.pos;
      if (t == 0) return u.type < v.type;
      return t < 0;
      });

  vector<llong> lastrent;
  llong ans = 0;
  for (auto i: qr) {
    if (i.type == 2) {
      lastrent.push_back(i.pos);
      continue;
    }
    llong rentnew = x;
    llong contrent = len(lastrent) ? y * (i.pos - lastrent.back()) : LLONG_MAX;
    llong renttime = y * (llong)(a[i.id].yy - a[i.id].xx) % rem;
    if (rentnew <= contrent) {
      //clog << a[i.id] << " rent new" << endl;
      (ans += x + renttime) %= rem;
    } else {
      //clog << a[i.id] << " continue rent" << ' ' << lastrent.back() << endl;
      (ans += contrent + renttime + rem) %= rem;
      lastrent.pop_back();
    }
  }
  cout << ans;


  return 0;
}