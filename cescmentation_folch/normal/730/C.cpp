#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;

struct Shop {
  ll num, price, id;
  Shop(ll num, ll price, ll id) : num(num), price(price), id(id) {}
  Shop() : id(-1) {}
};

bool operator<(const Shop& a, const Shop& b) {
  if (a.price < b.price) return true;
  if (a.price > b.price) return false;
  return a.id < b.id;
}
ostream& operator<<(ostream& os, const Shop& s) {
  return os << "(n: " << s.num << ", price: " << s.price << ", id: " << s.id << " )";
}

int N;
const int inf = 1e9;
VVI G;
using VS = vector<Shop>;
using VVS = vector<VS>;
VVS shops;

int solve(ll num, int city, ll total) {
  VI dist(N, inf);
  ll snum = 0;
  ll sprice = 0;
  priority_queue<Shop> pq;
  dist[city] = 0;
  queue<int> q;
  q.push(city);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (const Shop s : shops[u]) {
      pq.push(s);
      snum += s.num;
      sprice += s.num * s.price;
    }
    while (snum > num) {
      const Shop s = pq.top(); pq.pop();
      snum -= s.num;
      sprice -= s.num * s.price;
      if (snum < num) {
        ll dif = num - snum;
        snum += dif;
        sprice += dif * s.price;
        pq.push(Shop(dif, s.price, s.id));
      }
    }
    if (snum == num && sprice <= total) {
      return dist[u];
    }
    int nd = dist[u] + 1;
    for (int v : G[u]) {
      if (nd < dist[v]) { 
        dist[v] = nd;
        q.push(v);
      }
    }
  }
  return -1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  N = n;
  G = VVI(n);
  for (int i = 0; i < m; ++i) {
    int from, to; cin >> from >> to; --from; --to;
    G[from].push_back(to);
    G[to].push_back(from);
  }
  int w; cin >> w;
  shops = VVS(n);
  for (int i = 0; i < w; ++i) {
    int c, k, p;
    cin >> c >> k >> p;
    --c;
    shops[c].push_back(Shop(k, p, i));
  }
  int q; cin >> q;
  while (q--) {
    int city;
    ll num, total;
    cin >> city >> num >> total;
    --city;
    cout << solve(num, city, total) << "\n";
    //cout << endl << endl << endl;
  }


}