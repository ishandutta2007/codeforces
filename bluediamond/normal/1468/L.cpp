#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

ll prod (ll a, ll b, ll m)
{
    if(b == 0)
        return 0;
    if(b & 1)
        return (a + prod(a, (b ^ 1), m)) % m;
    ll aux = prod(a, (b >> 1), m);
    return (aux + aux) % m;
}

ll pwr (ll a, ll b, ll m)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return prod(a, pwr(a, (b ^ 1), m), m) % m;
    ll aux = pwr(a, (b >> 1), m);
    return prod(aux, aux, m);
}



ll nn;

bool rmail(ll p)
{
    if(nn == p)
        return true;
    ll e = 0;
    while((nn - 1) % (1LL << (e + 1)) == 0)
        e++;
    ll d = (nn - 1) / (1LL << e);
    ll pd = pwr(p, d, nn);
    if(pd == 1 || pd == nn - 1)
        return true;
    for(ll i = 1; i <= e; i++)
    {
        pd = prod(pd, pd, nn);
        if(pd == nn - 1)
            return true;
    }
    return false;
}


const int N = (int) 1e3 + 7;
const int L = (int) 1e6 + (int) 1e3 + 7;
const int INF = (int) 2e18;
int n;
int k;
int v[N];
int a[N];
bool prime[L];
vector<int> primes;


bool is_prime(int x) {
  nn = x;
  if (x <= 1) return 0;
  return rmail(2) && rmail(3) && rmail(5) && rmail(7) && rmail(11) && rmail(13) && rmail(17) && rmail(19) && rmail(23) && rmail(29) && rmail(31) && rmail(37) && rmail(41) && rmail(43) && rmail(47) && rmail(53) && rmail(59) && rmail(61) && rmail(67) && rmail(71) && rmail(73) && rmail(79) && rmail(83) && rmail(89) && rmail(97);
}

int mul(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  int c = a * b;
  if (c % a == 0 && c / a == b && c <= INF) {
    return c;
  } else {
    return INF;
  }
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

bool ok[N];
int par[N], cnt[N];
bool neaparat[N];

void test(vector<int> prm) {
  vector<int> sol;
  for (int i = 1; i <= n; i++) {
    if (neaparat[i]) {
      sol.push_back(v[i]);
      continue;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (neaparat[i]) continue;
    int x = v[i];
    for (auto &it : prm) {
      while (x % it == 0) {
        x /= it;
      }
    }
    if (x == 1 && (int) sol.size() < k) {
      sol.push_back(v[i]);
    }
  }
  if ((int) sol.size() == k) {
    for (auto &x : sol) {
      cout << x << " ";
    }
    cout << "\n";
    exit(0);
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


 // freopen ("input", "r", stdin);

  prime[2] = 1;
  for (int i = 3; i < L; i += 2) {
    prime[i] = 1;
  }
  for (int i = 3; i * i < L; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j < L; j += 2 * i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 1; i < L; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }


  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = 0;
    if (is_prime(v[i])) {
      a[i] = v[i];
      continue;
    }
    int l = 0, r = INF, rad = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (pw(m, 2) <= v[i]) {
        rad = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (rad * rad == v[i] && is_prime(rad)) {
      a[i] = rad;
    } else {
      for (int pt = 3; pt <= 60; pt++) {
        int l = 0, r = (int) primes.size() - 1, sol = 0;
        while (l <= r) {
          int m = (l + r) / 2;
          if (pw(primes[m], pt) <= v[i]) {
            sol = m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        if (pw(primes[sol], pt) == v[i]) {
          a[i] = primes[sol];
          break;
        }
      }
    }
  }
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      mp[a[i]].push_back(i);
    }
  }
  vector<pair<int, int>> lol;
  for (auto &it : mp) {
    if ((int) it.second.size() >= 2)
      lol.push_back({(int) it.second.size(), it.first});
  }
  sort(lol.rbegin(), lol.rend());
  if (lol.empty()) {
    cout << "0\n";
    return 0;
  }
  if (k == 1) {
    cout << "0\n";
    return 0;
  }
  for (int cnt = min(k, lol[0].first); cnt >= min(k, lol[0].first) - 1 && cnt >= 2; cnt--) {
   /// cout << " = " << cnt << "\n";
    vector<int> nums;
    int step = 0;
    for (int j = 1; j <= cnt; j++) nums.push_back(mp[lol[0].second][step++]);
    int need = k - cnt;
    for (int i = 1; i < (int) lol.size(); i++) {
      if (need >= 2) {
        int use = min(lol[i].first, need);
        need -= use;
        step = 0;
        for (int j = 1; j <= use; j++) nums.push_back(mp[lol[i].second][step++]);
      }
    }
    if (need == 0) {
      for (auto &x : nums) {
        cout << v[x] << " ";
      }
      cout << "\n";
      return 0;
    }
  }
  for (int skip = 0; skip <= (int) lol.size(); skip++) {
    for (int i = 1; i <= n; i++) neaparat[i] = 0;
    vector<int> rofl;
    for (int i = 0; i < (int) lol.size(); i++) {
      if (i != skip) {
        rofl.push_back(lol[i].second);
        for (auto &ind : mp[lol[i].second]) neaparat[ind] = 1;
      }
    }
    test(rofl);
  }
  for (int i = 1; i <= n; i++) {
    /// il bag pe i si dupa bag toti cu care e el divizibil
    vector<int> nums;
    if (a[i]) continue;
    nums.push_back(v[i]);
    int x = v[i];
    for (int j = 0; j < (int) lol.size(); j++) {
      if (v[i] % lol[j].second == 0) {
        while (x % lol[j].second == 0) x /= lol[j].second;
        for (auto &it : mp[lol[j].second]) nums.push_back(v[it]);
      }
    }
    if (x != 1) continue;
    for (int j = 0; j < (int) lol.size(); j++) {
      if (v[i] % lol[j].second != 0 && (int) nums.size() < k - 1) {
        for (auto &it : mp[lol[j].second]) {
          nums.push_back(v[it]);
          if ((int) nums.size() == k) break;
        }
      }
    }
    if ((int) nums.size() == k) {
      for (auto &x : nums) {
        cout << x << " ";
      }
      cout << "\n";
      exit(0);
    }
  }
  cout << "0\n";
  return 0;
  cout << pw(primes[0], 100) << "\n";


}