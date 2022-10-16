#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 7;

int add(int x) {  
  return x;
}

template<typename... T>
int add(int x, T... y) {  
  x += add(y...);
  if (x >= mod)
        x -= mod;
  return x;
}

template<typename... T>
int udd(int &x, T... y) { 
  return x = add(x, y...);
}

template<typename... T>
int sub(int x, T... y) { 
  return add(x, mod - add(y...));
}

int mul(int x) { 
  return x;
}

template<typename... T>
int mul(int x, T... y) { 
  return 1ll * x * mul(y...) % mod;
}

int bin(int x, int to) { 
  int y = 1;
  while (to) { 
        if (to & 1)
                  y = mul(x, y);
            x = mul(x, x);
                to >>= 1;
  }
  return y;
}

int inv(int x) { 
  assert(x != 0);
  return bin(x, mod - 2);
}

const int M = 1000100;
int sum = 1;
vector<int> q;
vector<int> t;
vector<int> d = {1};
vector<int> a;

int calc(string s) {
  q.reserve(M);
  t.reserve(M);
  d.reserve(M);
  a.reserve(M);

  assert(s[0] == '1');
  assert(s.back() == '1');

  int last = 0;
  for (int i = 1; i < (int) s.length(); ++i) {
    if (s[i] == '0') {
      ++last;
      continue;
    } else {
      a.push_back(last + 1);
      last = 0;
    }
  }

  //for (int x : a) {
    //cout << x << " ";
  //}
  //cout << endl;
  //
  

  int n = a.size();
  for (int i = 0; i < n; ++i) {
    while (!q.empty() && a[q.back()] < a[i]) {
      sum = sub(sum, t.back());
      q.pop_back();
      t.pop_back();
    }

    if (!q.empty()) {
      sum = sub(sum, t.back());
      t.pop_back();

      int cur = mul(d[q.back()], a[q.back()] - a[i]);
      sum = add(sum, cur);
      t.push_back(cur);
    }

    q.push_back(i);
    t.push_back(mul(d.back(), a[i]));
    sum = add(sum, mul(d.back(), a[i]));

    d.push_back(sum);
  }

  return d.back();
}
 

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int a = 0;
  while (!s.empty() && s.back() == '0') {
    s.pop_back();
    ++a;
  }

  reverse(all(s));

  int b = 0;
  while (!s.empty() && s.back() == '0') {
    s.pop_back();
    ++b;
  }

  if (s.empty()) {
    cout << a << "\n";
    return 14 / 88;
  }


  cout << mul(a + 1, b + 1, calc(s)) << "\n";
}