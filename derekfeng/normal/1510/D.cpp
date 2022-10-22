#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

constexpr int64_t BASE        = 1000000000;
constexpr int     BASE_DIGITS = 9;
struct BigInt
{
    using i64 = int64_t;
    using vi  = vector<i64>;
    using vvi = vector<vi>;
    vi  a;
    int sign;

    int size() const
    {
        if (a.empty()) return 0;
        int ret = (a.size() - 1) * BASE_DIGITS;
        i64 ca  = a.back();
        while (ca)
        {
            ret++;
            ca /= 10;
        }
        return ret;
    }

    BigInt pow(const BigInt &v)
    {
        BigInt ret = 1, a = *this, b = v;
        while (!b.isZero())
        {
            if (b % 2) { ret *= a; }
            a *= a, b /= 2;
        }
        return ret;
    }

    string to_string()
    {
        stringstream ss;
        ss << *this;
        return ss.str();
    }

    int sumof()
    {
        string s   = to_string();
        int    ret = 0;
        for (char c : s) ret += c - '0';
        return ret;
    }

    BigInt() : sign(1) {}
    BigInt(i64 v) { *this = v; }
    BigInt(const string &s) { read(s); }

    void operator=(const BigInt &v)
    {
        sign = v.sign;
        a    = v.a;
    }

    void operator=(i64 v)
    {
        sign = 1;
        a.clear();
        if (v < 0) { sign = -1, v = -v; }
        for (; v > 0; v = v / BASE) { a.push_back(v % BASE); }
    }

    BigInt operator+(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            BigInt res = v;
            for (int i = 0, carry = 0; i < max(a.size(), v.a.size()) || carry; i++)
            {
                if (i == res.a.size()) { res.a.push_back(0); }
                res.a[i] += carry + (i < a.size() ? a[i] : 0);
                carry = res.a[i] >= BASE;
                if (carry) { res.a[i] -= BASE; }
            }
            return res;
        }
        return *this - (-v);
    }

    BigInt operator-(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            if (abs() >= v.abs())
            {
                BigInt res = *this;
                for (int i = 0, carry = 0; i < v.a.size() || carry; i++)
                {
                    res.a[i] -= carry + (i < v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) { res.a[i] += BASE; }
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(i64 v)
    {
        if (v < 0) { sign = -sign, v = -v; }
        for (int i = 0, carry = 0; i < a.size() || carry; i++)
        {
            if (i == a.size()) { a.push_back(0); }
            i64 cur = a[i] * v + carry;
            carry   = cur / BASE;
            a[i]    = cur % BASE;
        }
        trim();
    }

    BigInt operator*(i64 v) const
    {
        BigInt res = *this;
        res *= v;
        return res;
    }

    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1)
    {
        i64    norm = BASE / (b1.a.back() + 1);
        BigInt a    = a1.abs() * norm;
        BigInt b    = b1.abs() * norm;
        BigInt q, r;
        q.a.resize(a.a.size());

        for (int i = int(a.a.size()) - 1; i >= 0; i--)
        {
            r *= BASE;
            r += a.a[i];
            i64 s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            i64 s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            i64 d  = (BASE * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0) { r += b, d--; }
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    BigInt operator/(const BigInt &v) const { return divmod(*this, v).first; }

    BigInt operator%(const BigInt &v) const { return divmod(*this, v).second; }

    void operator/=(i64 v)
    {
        if (v < 0) { sign = -sign, v = -v; }
        for (int i = int(a.size()) - 1, rem = 0; i >= 0; i--)
        {
            i64 cur = a[i] + rem * BASE;
            a[i]    = cur / v;
            rem     = cur % v;
        }
        trim();
    }

    BigInt operator/(i64 v) const
    {
        BigInt res = *this;
        res /= v;
        return res;
    }

    i64 operator%(i64 v) const
    {
        if (v < 0) v = -v;
        i64 m = 0;
        for (int i = int(a.size()) - 1; i >= 0; i--) { m = (a[i] + m * BASE) % v; }
        return m * sign;
    }

    void operator+=(const BigInt &v) { *this = *this + v; }

    void operator-=(const BigInt &v) { *this = *this - v; }

    void operator*=(const BigInt &v) { *this = *this * v; }

    void operator/=(const BigInt &v) { *this = *this / v; }

    bool operator<(const BigInt &v) const
    {
        if (sign != v.sign) { return sign < v.sign; }
        if (a.size() != v.a.size()) { return a.size() * sign < v.a.size() * sign; }
        for (int i = int(a.size()) - 1; i >= 0; i--)
        {
            if (a[i] != v.a[i]) { return a[i] * sign < v.a[i] * sign; }
        }
        return false;
    }

    bool operator>(const BigInt &v) const { return v < *this; }

    bool operator<=(const BigInt &v) const { return !(v < *this); }

    bool operator>=(const BigInt &v) const { return !(*this < v); }

    bool operator==(const BigInt &v) const { return !(*this < v) && !(v < *this); }

    bool operator!=(const BigInt &v) const { return *this < v || v < *this; }

    void trim()
    {
        while (!a.empty() && !a.back()) { a.pop_back(); }
        if (a.empty()) { sign = 1; }
    }

    bool isZero() const { return a.empty() || (a.size() == 1 && !a[0]); }

    BigInt operator-() const
    {
        BigInt res = *this;
        res.sign   = -sign;
        return res;
    }

    BigInt abs() const
    {
        BigInt res = *this;
        res.sign   = 1;
        return res;
    }

    i64 i64Value() const
    {
        i64 res = 0;
        for (int i = int(a.size()) - 1; i >= 0; i--) { res = res * BASE + a[i]; }
        return res * sign;
    }

    friend BigInt gcd(const BigInt &a, const BigInt &b) { return b.isZero() ? a : gcd(b, a % b); }
    friend BigInt lcm(const BigInt &a, const BigInt &b) { return a / gcd(a, b) * b; }

    void read(const string &s)
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-') { sign = -sign; }
            pos++;
        }
        for (int i = int(s.size()) - 1; i >= pos; i -= BASE_DIGITS)
        {
            i64 x = 0;
            for (int j = max(pos, i - BASE_DIGITS + 1); j <= i; j++) { x = x * 10 + s[j] - '0'; }
            a.push_back(x);
        }
        trim();
    }

    friend istream &operator>>(istream &stream, BigInt &v)
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const BigInt &v)
    {
        if (v.sign == -1) { stream << '-'; }
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = int(v.a.size()) - 2; i >= 0; i--)
        { stream << setw(BASE_DIGITS) << setfill('0') << v.a[i]; } return stream;
    }

    static vi convert_base(const vi &a, int old_digits, int new_digits)
    {
        vi p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < p.size(); i++) { p[i] = p[i - 1] * 10; }
        vi  res;
        i64 cur        = 0;
        int cur_digits = 0;
        for (int i = 0; i < a.size(); i++)
        {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits)
            {
                res.push_back(cur % p[new_digits]);
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back(cur);
        while (!res.empty() && !res.back()) { res.pop_back(); }
        return res;
    }

    static vi karatsuba(const vi &a, const vi &b)
    {
        int n = a.size();
        vi  res(n * 2);
        if (n <= 32)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++) { res[i + j] += a[i] * b[j]; }
            }
            return res;
        }

        int k = n >> 1;
        vi  a1(a.begin(), a.begin() + k);
        vi  a2(a.begin() + k, a.end());
        vi  b1(b.begin(), b.begin() + k);
        vi  b2(b.begin() + k, b.end());

        vi a1b1 = karatsuba(a1, b1);
        vi a2b2 = karatsuba(a2, b2);

        for (int i = 0; i < k; i++)
        {
            a2[i] += a1[i];
            b2[i] += b1[i];
        }

        vi r = karatsuba(a2, b2);
        for (int i = 0; i < a1b1.size(); i++) { r[i] -= a1b1[i]; }
        for (int i = 0; i < a2b2.size(); i++) { r[i] -= a2b2[i]; }

        for (int i = 0; i < r.size(); i++) { res[i + k] += r[i]; }
        for (int i = 0; i < a1b1.size(); i++) { res[i] += a1b1[i]; }
        for (int i = 0; i < a2b2.size(); i++) { res[i + n] += a2b2[i]; }
        return res;
    }

    BigInt karatsubaMultiply(const BigInt &v) const
    {
        vi a = convert_base(this->a, BASE_DIGITS, 6);
        vi b = convert_base(v.a, BASE_DIGITS, 6);
        while (a.size() < b.size()) { a.push_back(0); }
        while (b.size() < a.size()) { b.push_back(0); }
        while (a.size() & (a.size() - 1))
        {
            a.push_back(0);
            b.push_back(0);
        }
        vi     c = karatsuba(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < c.size(); i++)
        {
            i64 cur = c[i] + carry;
            res.a.push_back(cur % 1000000);
            carry = cur / 1000000;
        }
        res.a = convert_base(res.a, 6, BASE_DIGITS);
        res.trim();
        return res;
    }

    static void fft(vector<complex<double>> &a, bool inv = false)
    {
        int n = int(a.size());
        if (n == 1) return;
        vector<complex<double>> even(n / 2), odd(n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            even[i] = a[2 * i];
            odd[i]  = a[2 * i + 1];
        }
        fft(even, inv);
        fft(odd, inv);
        complex<double> omega     = polar(1.0, (-2 * inv + 1) * 2 * acos(-1) / n);
        complex<double> pow_omega = 1.0;
        for (int i = 0; i < n / 2; i++)
        {
            a[i]         = even[i] + pow_omega * odd[i];
            a[i + n / 2] = even[i] - pow_omega * odd[i];
            pow_omega *= omega;
        }
    }

    static void conv(vector<complex<double>> &a, vector<complex<double>> &b)
    {
        fft(a);
        fft(b);
        int n = int(a.size());
        for (int i = 0; i < n; i++) { a[i] *= b[i] / complex<double>(n); }
        fft(a, true);
    }

    static vi conv(const vi &a, const vi &b)
    {
        int n = max(a.size(), b.size());
        int N = 1;
        while (N <= n) N <<= 1;
        N <<= 1;
        vector<complex<double>> ac(N), bc(N);
        for (int i = 0; i < a.size(); i++) { ac[i] = a[i]; }
        for (int i = 0; i < b.size(); i++) { bc[i] = b[i]; }
        conv(ac, bc);
        vi ret(ac.size());
        for (int i = 0; i < ac.size(); i++) { ret[i] = long(real(ac[i]) + 0.5); }
        return ret;
    }

    BigInt fftMultiply(const BigInt &v) const
    {
        vi     a = convert_base(this->a, BASE_DIGITS, 1);
        vi     b = convert_base(v.a, BASE_DIGITS, 1);
        vi     c = conv(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < c.size(); i++)
        {
            i64 cur = c[i] + carry;
            res.a.push_back(cur % 10);
            carry = cur / 10;
        }
        res.a = convert_base(res.a, 1, BASE_DIGITS);
        res.trim();
        return res;
    }

    BigInt operator*(const BigInt &v) const
    {
        if (max(size(), v.size()) < 300000) { return karatsubaMultiply(v); }
        else
        {
            return fftMultiply(v);
        }
    }
};

int n,d,lenval[20];
vector <int> v[20];
vector <pair <int,BigInt> > val[20];
long double dp[20][20],vall[20][20];
pair <pii,int> lst[20][20];

void deal(int w)
{
  sort(v[w].begin(),v[w].end());reverse(v[w].begin(),v[w].end());
  int p=w;
  vector <int> vv;vv.clear();vv.pb(w);
  while(true)
  {
    p*=w;
    if(p%10==w) break;
    vv.pb(p%10);
  }
  if(v[w].size()==0) return; 
  BigInt base=1;
  p=1;
  int pos;
  long double basee=0;
  rep(i,v[w].size())
  {
    if(v[w].size()-i<=vv.size())
    {
      pos=i;
      break;
    }
    BigInt tmp=v[w][i];
    //base=base*tmp;
    basee+=log(v[w][i]);
    p=p*v[w][i]%10;
  }
  //cout<<pos<<' '<<vv.size()<<"adfkflajslkdj\n";
  while(pos<v[w].size())
  {
    p=p*v[w][pos]%10;
    BigInt tmp=v[w][pos++];
    //base=base*tmp;
    basee+=log(v[w][pos-1]);
    val[w].pb(mpr(p,base));
    vall[w][val[w].size()-1]=basee;
  }
  //cout<<w<<'p'<<endl;
  //cout<<vv.size()<<"stane\n";
  //rep(i,v[w].size()) cout<<v[w][i]<<' ';cout<<"l1";cout<<endl;
  //rep(i,val[w].size()) cout<<val[w][i].se<<' ';cout<<"l2"<<endl<<endl;
}

int main()
{
  cin>>n>>d;
  int x;
  rep(i,n)
  {
    scanf("%d",&x);
    v[x%10].pb(x);
  }
  rep(i,10) deal(i);
  rep(i,15) rep(j,15) dp[i][j]=0;
  dp[0][1]=1;
  rep(i,10) rep(j,10)
  {
    if(dp[i][j]==0) continue;
    if(dp[i+1][j]<dp[i][j]) dp[i+1][j]=dp[i][j],lst[i+1][j]=mpr(mpr(i,j),-1);
    rep(k,val[i].size())
    {
      double tmp=dp[i][j]+vall[i][k];
      int nxt=j*val[i][k].fi%10;
      if(dp[i+1][nxt]<tmp) dp[i+1][nxt]=tmp,lst[i+1][nxt]=mpr(mpr(i,j),val[i].size()-k-1);
    }
  }
  if(dp[10][d]==0) puts("-1");
  else
  {
    vector <int> ans;ans.clear();
    int x=10,y=d;
    while(!(x==0&&y==1))
    {
      if(lst[x][y].se!=-1)
      {
        //cout<<x<<endl;
        for(int i=0;i<v[x-1].size()-lst[x][y].se;++i) ans.pb(v[x-1][i]);
      }
      pii tmp=lst[x][y].fi;
      x=tmp.fi;y=tmp.se;
    }
    if(ans.size()==0) puts("-1");
    else
    {
      cout<<ans.size()<<endl;
      rep(i,ans.size()) cout<<ans[i]<<' ';
      cout<<endl;
    }
  }
	return 0;
}