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

#define maxn 301010
bool iscoprime[maxn] = {0};
int n, k;
llong divcnt[maxn] = {0};
llong en[maxn] = {0};

vector<int> rem;
void printAns() {
  cout << "Yes\n";
  cout << n - len(rem) << '\n';
  rep1(i, n) {
    if (len(rem) and i == rem.back()) {
      rem.pop_back();
    } else {
      cout << i << ' ';
    }
  }
  exit(0);
}
void btr(int i, int left) {
  if (left == 0) {
    reverse(rem.begin(), rem.end());
    printAns();
  }
  if (i == n + 1) return ;
  btr(i + 1, left);
  int t = (int)divcnt[i] + (n / i) - 1;
  if (t > left) return;
  left -= t;
  for (int f = i * 2; f <= n; f += i) {
    divcnt[f] --;
  }
  rem.push_back(i);
  btr(i + 1, left);
  for (int f = i * 2; f <= n; f += i) divcnt[f] ++;
  rem.pop_back();
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  en[0] = 0;
  for (int i = 2; i <= n; ++i) {
    divcnt[i]++;
    en[i] = en[i - 1] + divcnt[i];
    for (int f = i * 2; f <= n; f += i) {
      iscoprime[f] = 1;
      divcnt[f] ++;
    }
  }

  if (en[n] < k) {
    cout << "No";
    return 0;
  }

  while (en[n - 1] >= k) n--;
  if (n <= 120) {
    btr(1, (int)en[n] - k);
    cout << "NO";
  } else {
    for (int i = n; en[n] - len(rem) != k; i--) {
     if (!iscoprime[i]) rem.push_back(i);
    }
    printAns();
  }

  return 0;
}