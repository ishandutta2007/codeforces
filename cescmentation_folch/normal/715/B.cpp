#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;
typedef pair<pi, int> ppi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;

const int N = 1010;

vpi G[N];

ll D[N];
ll P[N];
ll W[N];

void dijtra(ll s, ll val) {
  D[s] = 0;
  priority_queue<pi> Q;
  Q.push(pi(0, s));
  while (!Q.empty()) {
    ll x = Q.top().second;
    ll k = -Q.top().first;
    Q.pop();
    if (D[x] < k) continue;
//     cerr << x << ' ' << D[x] << endl;
    for (ll i = 0; i < G[x].size(); ++i) {
      ll y = G[x][i].first;
      ll t = G[x][i].second;
      if (t == 0) t = val;
      if (D[x] + t < D[y] or D[y] == -1) {
	D[y] = D[x] + t;
	Q.push(pi(-D[y], y));
      }
    }
  }
}

void dfs(ll s, ll val) {
  D[s] = 0;
  priority_queue<ppi> Q;
  Q.push(ppi(pi(0, 0),s));
  while (!Q.empty()) {
    ll x = Q.top().second;
    ll k = -Q.top().first.first;
    ll kt = Q.top().first.second;
    Q.pop();
    if (D[x] < k or kt < W[x]) continue;
//     cerr << x << ' ' << D[x] << endl;
    for (ll i = 0; i < G[x].size(); ++i) {
      ll y = G[x][i].first;
      ll t = G[x][i].second;
      ll kaka = 0;
      if (t == 0) {
	t = val;
	kaka = 1;
      }
      if (D[x] + t < D[y] or D[y] == -1) {
	D[y] = D[x] + t;
	W[y] = W[x] + kaka;
	P[y] = x;
	Q.push(ppi(pi(-D[y], W[y]), y));
      }
      else if (D[x] + t == D[y] and W[y] < W[x] + kaka) {
	D[y] = D[x] + t;
	W[y] = W[x] + kaka;
	P[y] = x;
	Q.push(ppi(pi(-D[y], W[y]), y));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll n, m, l, s, t;
  cin >> n >> m >> l >> s >> t;
  for (ll i = 0; i < m; ++i) {
    ll x, y, k;
    cin >> x >> y >> k;
    G[x].push_back(pi(y, k));
    G[y].push_back(pi(x, k));
  }
  ll a = 0, b = 2*l;
  while (a + 1 < b) {
    ll c = (a + b)/2;
    memset(D, -1, sizeof D);
    dijtra(s, c);
    if (D[t] < l) a = c;
    else b = c;
  }
  memset(D, -1, sizeof D);
  dijtra(s, b);
  if ((b == 0 or (D[t] > l and b == 1) or D[t] < l) and D[t] != l) {
    cout << "NO" << endl;
    return 0;
  }
  
  memset(D, -1, sizeof D);
  memset(P, -1, sizeof P);
  dfs(s, b);
  
  ll k = t;
  ll op = D[t] - l;
  while (op) {
    for (ll i = 0; i < G[k].size(); ++i) {
      ll y = G[k][i].first;
      ll pp = G[k][i].second;
      if (y == P[k]) {
	if (pp == 0) {
	  G[k][i].second = -1;
	  for (ll j = 0; j < G[y].size(); ++j) {
	    ll x = G[y][j].first;
	    if (x == k) {
	      G[y][j].second = -1;
	      break;
	    }
	    
	  }
	  --op;
	  
	}
	k = P[k];
	break;
      }
    }
  }
  
  cout << "YES" << endl;
  for (ll x = 0; x < n; ++x) {
    for (ll i = 0; i < G[x].size(); ++i) {
      ll y = G[x][i].first;
      ll k2 = G[x][i].second;
      if (x > y) continue;
      if (k2 <= 0) k2 += b;
      cout << x << ' ' << y << ' ' << k2 << '\n';
    }
  }
}