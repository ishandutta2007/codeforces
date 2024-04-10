#include <bits/stdc++.h>


using namespace std;

#define int long long
typedef long double ld;
typedef long long ll;
bool home = 1;
vector<int> rushdivs;
vector<int> rushdivs2;


int mul(int a, int b, int m) {
  int sol = a * b - m * (ll)((ld)1 / m * a * b);
  sol %= m;
  if (sol < 0) sol += m;
  return sol;
}

int pw(int a, int b, int mod) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a, mod);
    a = mul(a, a, mod);
    b /= 2;
  }
  return r;
}

int findk(int m, int x, int phi) {
  int k = phi;
  for (auto& d : rushdivs2) {
    if (d == 1) continue;

    while (k % d == 0 && pw(x, k / d, m) == 1) {
      k /= d;
    }
  }

  return k;
}

vector<int> cop;

int solve(int m, int x) {
  if (x == 0) {
    return 1;
  }
  int phi = m, aux = m;
  for (auto& d : cop) {
    if (d == 1) continue;
    if (aux % d == 0) {
      while (aux % d == 0) aux /= d;
      phi /= d;
      phi *= (d - 1);
    }
  }
  int k = findk(m, x, phi);
  return phi / k;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);



#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int m, x;
  cin >> m >> x;

  int mm = m;

  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      cop.push_back(i);
      while (m % i == 0) {
        m /= i;
      }
    }
  }
  if (m > 1) cop.push_back(m);
  m = mm;

  vector<int> dvs;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      dvs.push_back(i);
      if (i * i == m) break;
      dvs.push_back(m / i);
    }
  }
  sort(dvs.begin(), dvs.end());

  rushdivs = dvs;
  rushdivs2 = cop;
  for (auto& d : cop) {
    int dd = d - 1;
    for (int i = 2; i * i <= dd; i++) {
      if (dd % i == 0) {
        rushdivs2.push_back(i);
        while (dd % i == 0) dd /= i;
      }
    }
    if (dd > 1) {
      rushdivs2.push_back(dd);
    }
  }
  sort(rushdivs2.begin(), rushdivs2.end());
  {
    int y = 1;
    for (int i = 1; i < (int)rushdivs2.size(); i++) {
      if (rushdivs2[i] == rushdivs2[i - 1]) {
        continue;
      }
      rushdivs2[y++] = rushdivs2[i];
    }
    rushdivs2.resize(y);
    rushdivs2.shrink_to_fit();
  }
  int print = 0;
  for (auto& g : dvs) {
    print += solve(m / g, x % (m / g));
  }

  cout << print << "\n";


}