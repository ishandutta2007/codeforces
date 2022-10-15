#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 

bool home = true;

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

const int N = (int)1e6 + 7;
int lp[N];
vector<int> primes;

void add(map<int, int>& mp, int x) {
  while (x > 1) {
    mp[lp[x]]++;
    x /= lp[x];
  }
}

void add(map<int, int>& mp, int x, int y) {
  add(mp, x);
  add(mp, y);
}

void add(map<int, int>& mp, int x, int y, int z) {
  add(mp, x);
  add(mp, y);
  add(mp, z);
}

void add(map<int, int>& mp, int x, int y, int z, int o) {
  add(mp, x);
  add(mp, y);
  add(mp, z);
  add(mp, o);
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  for (int i = 2; i < N; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && primes[j] * i < N; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }


  int t;
  cin >> t;
  while (t--) {
    map<int, int> mp_n, mp_m, mp_s;
    int n1, n2, n3, m1, m2, m3, s1, s2, s3;
    cin >> n1 >> n2 >> n3 >> m1 >> m2 >> m3 >> s1 >> s2 >> s3;

    add(mp_n, n1, n2, n3);
    add(mp_m, m1, m2, m3);
    add(mp_s, s1, s2, s3, 2);

    ll n = (ll)n1 * n2 * n3;
    ll m = (ll)m1 * m2 * m3;
    ll s = (ll)s1 * s2 * s3;
    ll sol = 0;

    s *= 2;

    {
      vector<ll> divis, nw_divis;
      int total = 1;
      for (auto& it : mp_s) {
        total *= (it.second + 1);
      }
      divis.reserve(total);
      nw_divis.reserve(total);

      divis.push_back(1);
      for (auto& it : mp_s) {
  
        int p = it.first, emax = it.second;
        nw_divis.clear();
        for (auto& num : divis) {
          ll prod = 1;
          for (int e = 0; e <= emax && num * prod <= n; e++) {
            nw_divis.push_back(num * prod);
            prod *= p;
          }
        }

        swap(divis, nw_divis);
      }

      sol += (int)divis.size();

    }

    vector<ll> nu;

    for (auto& it : mp_n) {
      int prime = it.first, e_n = it.second;
      int e_s = (!mp_s.count(prime) ? 0 : mp_s[prime]);

      if (e_n <= e_s) continue;
      if (e_n > e_s) {
        ll cur = 1;
        for (int j = 1; j <= e_s + 1; j++) {
          cur *= prime;
        }
        nu.push_back(cur);
      }
    }


    int dim = (int)nu.size();
    for (int mask = 0; mask < (1 << dim); mask++) {
      ll prod = 1, sgn = +1;
      for (int i = 0; i < dim; i++) {
        if (mask & (1 << i)) {
          prod *= nu[i];
          sgn *= -1;
        }
      }
      sol += (m / prod) * sgn;
    }
    cout << sol << "\n";
  }

}