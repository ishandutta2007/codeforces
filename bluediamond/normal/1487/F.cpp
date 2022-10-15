#include <bits/stdc++.h>

using namespace std;


const int base = 1000000000;
const int base_digits = 9;

struct bongint {
  vector<int> a;
  int sign;

  bongint() :
    sign(1) {
  }

  bongint(long long v) {
    *this = v;
  }

  bongint(const string &s) {
    read(s);
  }

  void operator=(const bongint &v) {
    sign = v.sign;
    a = v.a;
  }

  void operator=(long long v) {
    sign = 1;
    if (v < 0)
      sign = -1, v = -v;
    for (; v > 0; v = v / base)
      a.push_back(v % base);
  }

  bongint operator+(const bongint &v) const {           //Addition Operation
    if (sign == v.sign) {
      bongint res = v;
      for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
        if (i == (int) res.a.size())
          res.a.push_back(0);
        res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
        carry = res.a[i] >= base;
        if (carry)
          res.a[i] -= base;
      }
      return res;
    }
    return *this - (-v);
  }

  bongint operator-(const bongint &v) const {           //Subtraction Function
    if (sign == v.sign) {
      if (abs() >= v.abs()) {
        bongint res = *this;
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
          res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
          carry = res.a[i] < 0;
          if (carry)
            res.a[i] += base;
        }
        res.trim();
        return res;
      }
      return -(v - *this);
    }
    return *this + (-v);
  }

  void operator*=(int v) {                    //Multiplication Function
    if (v < 0)
      sign = -sign, v = -v;
    for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
      if (i == (int) a.size())
        a.push_back(0);
      long long cur = a[i] * (long long) v + carry;
      carry = (int) (cur / base);
      a[i] = (int) (cur % base);
      //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
    }
    trim();
  }

  bongint operator*(int v) const {
    bongint res = *this;
    res *= v;
    return res;
  }

  friend pair<bongint, bongint> divmod(const bongint &a1, const bongint &b1) {
    int norm = base / (b1.a.back() + 1);
    bongint a = a1.abs() * norm;
    bongint b = b1.abs() * norm;
    bongint q, r;
    q.a.resize(a.a.size());
    for (int i = a.a.size() - 1; i >= 0; i--) {
      r *= base;
      r += a.a[i];
      int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
      int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
      int d = ((long long) base * s1 + s2) / b.a.back();
      r -= b * d;
      while (r < 0)
        r += b, --d;
      q.a[i] = d;
    }

    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }

  bongint operator/(const bongint &v) const {               //Division Function
    return divmod(*this, v).first;
  }

  bongint operator%(const bongint &v) const {               //Modulus Operation
    return divmod(*this, v).second;
  }

  void operator/=(int v) {                                //Shorthand Operation
    if (v < 0)
      sign = -sign, v = -v;
    for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
      long long cur = a[i] + rem * (long long) base;
      a[i] = (int) (cur / v);
      rem = (int) (cur % v);
    }
    trim();
  }

  bongint operator/(int v) const {
    bongint res = *this;
    res /= v;
    return res;
  }

  int operator%(int v) const {
    if (v < 0)
      v = -v;
    int m = 0;
    for (int i = a.size() - 1; i >= 0; --i)
      m = (a[i] + m * (long long) base) % v;
    return m * sign;
  }

  void operator+=(const bongint &v) {
    *this = *this + v;
  }
  void operator-=(const bongint &v) {
    *this = *this - v;
  }
  void operator*=(const bongint &v) {
    *this = *this * v;
  }
  void operator/=(const bongint &v) {
    *this = *this / v;
  }

  bool operator<(const bongint &v) const {
    if (sign != v.sign)
      return sign < v.sign;
    if (a.size() != v.a.size())
      return a.size() * sign < v.a.size() * v.sign;
    for (int i = a.size() - 1; i >= 0; i--)
      if (a[i] != v.a[i])
        return a[i] * sign < v.a[i] * sign;
    return false;
  }

  bool operator>(const bongint &v) const {
    return v < *this;
  }
  bool operator<=(const bongint &v) const {
    return !(v < *this);
  }
  bool operator>=(const bongint &v) const {
    return !(*this < v);
  }
  bool operator==(const bongint &v) const {
    return !(*this < v) && !(v < *this);
  }
  bool operator!=(const bongint &v) const {
    return *this < v || v < *this;
  }

  void trim() {
    while (!a.empty() && !a.back())
      a.pop_back();
    if (a.empty())
      sign = 1;
  }

  bool isZero() const {
    return a.empty() || (a.size() == 1 && !a[0]);
  }

  bongint operator-() const {
    bongint res = *this;
    res.sign = -sign;
    return res;
  }

  bongint abs() const {
    bongint res = *this;
    res.sign *= res.sign;
    return res;
  }

  long long longValue() const {
    long long res = 0;
    for (int i = a.size() - 1; i >= 0; i--)
      res = res * base + a[i];
    return res * sign;
  }

  friend bongint gcd(const bongint &a, const bongint &b) {           //GCD Function(Euler Algorithm)
    return b.isZero() ? a : gcd(b, a % b);
  }
  friend bongint lcm(const bongint &a, const bongint &b) {           //Simple LCM Operation
    return a / gcd(a, b) * b;
  }

  void read(const string &s) {                                //Reading a Big Integer
    sign = 1;
    a.clear();
    int pos = 0;
    while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
      if (s[pos] == '-')
        sign = -sign;
      ++pos;
    }
    for (int i = s.size() - 1; i >= pos; i -= base_digits) {
      int x = 0;
      for (int j = max(pos, i - base_digits + 1); j <= i; j++)
        x = x * 10 + s[j] - '0';
      a.push_back(x);
    }
    trim();
  }

  friend istream& operator>>(istream &stream, bongint &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
  }

  friend ostream& operator<<(ostream &stream, const bongint &v) {
    if (v.sign == -1)
      stream << '-';
    stream << (v.a.empty() ? 0 : v.a.back());
    for (int i = (int) v.a.size() - 2; i >= 0; --i)
      stream << setw(base_digits) << setfill('0') << v.a[i];
    return stream;
  }

  static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for (int i = 1; i < (int) p.size(); i++)
      p[i] = p[i - 1] * 10;
    vector<int> res;
    long long cur = 0;
    int cur_digits = 0;
    for (int i = 0; i < (int) a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while (cur_digits >= new_digits) {
        res.push_back(int(cur % p[new_digits]));
        cur /= p[new_digits];
        cur_digits -= new_digits;
      }
    }
    res.push_back((int) cur);
    while (!res.empty() && !res.back())
      res.pop_back();
    return res;
  }

  typedef vector<long long> vll;

  static vll karatsubaMultiply(const vll &a, const vll &b) {      //Multiplication using Karatsuba Algorithm
    int n = a.size();
    vll res(n + n);
    if (n <= 32) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          res[i + j] += a[i] * b[j];
      return res;
    }

    int k = n >> 1;
    vll a1(a.begin(), a.begin() + k);
    vll a2(a.begin() + k, a.end());
    vll b1(b.begin(), b.begin() + k);
    vll b2(b.begin() + k, b.end());

    vll a1b1 = karatsubaMultiply(a1, b1);
    vll a2b2 = karatsubaMultiply(a2, b2);

    for (int i = 0; i < k; i++)
      a2[i] += a1[i];
    for (int i = 0; i < k; i++)
      b2[i] += b1[i];

    vll r = karatsubaMultiply(a2, b2);
    for (int i = 0; i < (int) a1b1.size(); i++)
      r[i] -= a1b1[i];
    for (int i = 0; i < (int) a2b2.size(); i++)
      r[i] -= a2b2[i];

    for (int i = 0; i < (int) r.size(); i++)
      res[i + k] += r[i];
    for (int i = 0; i < (int) a1b1.size(); i++)
      res[i] += a1b1[i];
    for (int i = 0; i < (int) a2b2.size(); i++)
      res[i + n] += a2b2[i];
    return res;
  }

  bongint operator*(const bongint &v) const {
    vector<int> a6 = convert_base(this->a, base_digits, 6);
    vector<int> b6 = convert_base(v.a, base_digits, 6);
    vll a(a6.begin(), a6.end());
    vll b(b6.begin(), b6.end());
    while (a.size() < b.size())
      a.push_back(0);
    while (b.size() < a.size())
      b.push_back(0);
    while (a.size() & (a.size() - 1))
      a.push_back(0), b.push_back(0);
    vll c = karatsubaMultiply(a, b);
    bongint res;
    res.sign = sign * v.sign;
    for (int i = 0, carry = 0; i < (int) c.size(); i++) {
      long long cur = c[i] + carry;
      res.a.push_back((int) (cur % 1000000));
      carry = (int) (cur / 1000000);
    }
    res.a = convert_base(res.a, 6, base_digits);
    res.trim();
    return res;
  }
};

pair<bongint, int> sm(bongint a) {
        bongint r = 1;
        int cnt = 1;
        while (r * 10 + 1 <= a)
                r = r * 10 + 1,
                cnt++;
        return {r, cnt};
}

const int INF = (int) 1e9;
map<bongint, int> memo;
priority_queue<pair<int, bongint>> pq;

int get_value(bongint a) {
        if (memo.count(a))
                return memo[a];
        else
                return INF;
}

void add(bongint a, int x) {
        if (x < get_value(a)) {
                pq.push({-x, a});
                memo[a] = x;
        }
}

int main() {
        bongint a;
        cin >> a;
        add(a, 0);
        while (!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                if (get_value(it.second) != -it.first)
                        continue;
                int cost = -it.first;
                if (cost >= get_value(0))
                        break;
                bongint x = it.second;
                auto itr = sm(x);
                add(x - itr.first, cost + itr.second);
                add(itr.first * 10 + 1 - x, cost + itr.second + 1);
        }
        cout << get_value(0) << "\n";
}