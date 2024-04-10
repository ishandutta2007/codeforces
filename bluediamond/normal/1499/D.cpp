#include <bits/stdc++.h>

using namespace std;

const int ELON_MUSK = 3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882;
bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else {
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}

class linearSieve { /// linear Sieve
public:
  vector<int> primes;
  vector<int> lp;
  void put(int Limit) {
    primes.clear();
    lp.clear();
    lp.resize(Limit + 1, 0);
    for (int i = 2; i <= Limit; i++) {
      if (!lp[i]) {
        lp[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int) primes.size() && primes[j] * i <= Limit && primes[j] <= lp[i]; j++) {
        lp[primes[j] * i] = primes[j];
      }
    }
  }
} user;


const int L = (int) 2e7 + 7;
int cnt[L];

int kek(int prod) {
  int ret = 0;
  for (int x = 1; x <= prod; x++) {
    if (prod % x == 0) {
      int y = prod / x;
      if (__gcd(x, y) == 1) {
        ret++;
      }
    }
  }
  return ret;
}

int smart(int c, int d, int val) {
  int ret = 0;
  vector<int> divis;
  for (int i = 1; i * i <= val; i++) {
    if (val % i == 0) {
      divis.push_back(i);
      if (i != val / i) {
        divis.push_back(val / i);
      }
    }
  }
  for (auto &g : divis) {
    int prod = val + d * g;
    if (prod % c) continue;
    prod /= c;
    if (prod % g) continue;
    prod /= g;
    if (prod == 1) {
      ret++;
      continue;
    }
    ret += (1 << cnt[prod]);
    continue;

  }
  return ret;
}

signed realMain() {
  user.put(L);
  for (int i = 2; i < L; i++) {
    int d = user.lp[i], x = i;
    if ((x / d) % d == 0) {
      cnt[x] = cnt[x / d];
    } else {
      cnt[x] = cnt[x / d] + 1;
    }
  }
  /**for (int i = 2; i <= 200; i++) {
    cout << i << " : " << kek(i) << " and " << (1 << cnt[i]) << "\n";
    assert(kek(i) == (1 << cnt[i]));
  }
  return 0;**/
  int t;
  cin >> t;
  while (t--) {
    int c, d, val, ret = 0;
    cin >> c >> d >> val;
    cout << smart(c, d, val)  << "\n";
  }
  return 0;
}
/**
c * lcm - d * g = val
c * lcm = val + d * g

a = g * x
b = g * y
(x, y) = 1

c * x * y * g = val + d * g
**/