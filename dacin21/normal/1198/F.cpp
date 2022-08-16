#include <bits/stdc++.h>
using namespace std;
 
 
// Integer factorization in O(N^{1/4}
// uses squfof from msieve https://github.com/radii/msieve
// with fixes to work for n = p^3
// works up to 10^18
// probably fails on 5003^5 which is ~10^{18.5}
 
namespace Factor {
    template<typename T, typename SFINAE = void> struct bigger_type{};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 4>::type>{using type = long long;};
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 4>::type>{using type = unsigned long long;};
    /*template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 8>::type>{using type = __int128;};
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 8>::type>{using type = unsigned __int128;};*/
 
    template<typename int_t = unsigned long long>
    struct Mod_Int{
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = a+b;
            if(ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
            return a*static_cast<bigger_type_t<int_t>>(b)%mod;
        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = 1;
            int_t base = a;
            for(int i=0;b>>i;++i){
                if((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };
 
    template<typename T>
    bool is_prime(T x){
        static_assert(is_integral<T>::value);
        if(x<T(4)) return x>T(1);
        for(T i=2;i*i<=x;++i){
            if(x%i == 0) return false;
        }
        return true;
    }
 
    template<typename T>
    bool miller_rabin_single(T const&x, T base){
        static_assert(is_integral<T>::value);
        if(x<T(4)) return x>T(1);
        if(x%2 == 0) return false;
        base%=x;
        if(base == 0) return true;
 
        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0){ // could use __builtin_ctz
            d/=2;
            ++j;
        }
        T t = Mod_Int<T>::pow(base, d, x);
        if(t==T(1) || t==T(xm1)) return true;
        for(int k=1;k<j;++k){
            t = Mod_Int<T>::mul(t, t, x);
            if(t == xm1) return true;
            if(t<=1) break;
        }
        return false;
    }
 
    template<typename T>
    bool miller_rabin_multi(T const&){return true;}
    template<typename T, typename... S>
    bool miller_rabin_multi(T const&x, T const&base, S const&...bases){
        static_assert(is_integral<T>::value);
        if(!miller_rabin_single(x, base)) return false;
        return miller_rabin_multi(x, bases...);
    }
 
    template<typename T>
    bool miller_rabin(T const&x){
        static_assert(is_integral<T>::value);
        if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }
 
    template<typename T>
    T isqrt(T const&x){
        static_assert(is_integral<T>::value);
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    T icbrt(T const&x){
        static_assert(is_integral<T>::value);
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    vector<uint16_t> saved;
    // fast prime factorization from
    // https://github.com/radii/msieve
    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        //cerr << "try: " << x << " " << k << "\n";
        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn-p1*p1;
 
        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }
 
        uint32_t multiplier = 2*k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        //cerr << "at: " << multiplier << "\n";
 
        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;
 
        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;
 
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (q1 < coarse_cutoff) {
                tmp = q1 / __gcd(q1, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }
 
            bits = 0;
            tmp = q0;
            while(!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {
 
                sqrtq = (uint32_t)isqrt(q0);
 
                if (sqrtq * sqrtq == q0) {
                    for(j=0;j<saved.size();++j){
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    //else cerr << "skip " << i << "\n";;
                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (q0 < coarse_cutoff) {
                tmp = q0 / __gcd(q0, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }
 
        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}
 
        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
 
        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;
 
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (p0 == p1) {
                q0 = q1;
                break;
            }
 
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (p0 == p1)
                break;
        }
        if(j==it_max) {cerr << "RNG\n"; return 1;} // random fail
 
        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t squfof(uint64_t const&x){
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
 
        uint64_t cbrt_x = icbrt(x);
        if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;
 
        //uint32_t iter_lim = isqrt(isqrt(x))+10;
        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; //would overflow
                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        return 1;
    }
 
    template<typename T>
    vector<T> factorize(T x){
        static_assert(is_integral<T>::value);
        vector<T> ret;
        const uint32_t trial_limit = 1000;
        auto trial = [&](int i){while(x%i == 0){x/=i; ret.push_back(i);}};
        trial(2); trial(3);
        for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
            trial(i);
        }
        if(x>1){
            static stack<T> s;
            s.push(x);
            while(!s.empty()){
                x = s.top(); s.pop();
                if(!miller_rabin(x)){
                    T factor = squfof(x);
                    if(factor == 1 || factor == x){assert(0); return ret;}
                    s.push(factor);
                    s.push(x/factor);
                } else {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
}
 
 
 
 
#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)
 
template <typename T>
void debug_out(T t) {
  cerr << t;
}
 
template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
 
template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << ", ";
  }
}
 
template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << endl;
  }
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__), cerr << endl;
 
 
namespace factorizer {
 
vector<int> least = {0, 1};
vector<int> primes;
int precalculated = 1;
 
void RunLinearSieve(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > least[i] || i * x > n) {
        break;
      }
      least[i * x] = x;
    }
  }
  precalculated = n;
}
 
void RunSieve(int n) {
  RunLinearSieve(n);
}
 
template <typename T>
vector<pair<T, int>> Factorize(T x) {
  vector<pair<T, int>> ret;
  for (T i : primes) {
    T t = x / i;
    if (i > t) {
      break;
    }
    if (x == t * i) {
      int cnt = 0;
      while (x % i == 0) {
        x /= i;
        cnt++;
      }
      ret.emplace_back(i, cnt);
    }
  }
  if (x > 1) {
    ret.emplace_back(x, 1);
  }
  return ret;
}
 
}
 
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
 
int n;
 
int main() {
  srand(time(0));
  scanf("%d", &n);
  vector<int> a(n);
  range(i, 0, n) {
    scanf("%d", &a[i]);
  }
  unordered_map<int, vector<int>> cnt;
  range(i, 0, n) {
    auto foo = Factor::factorize(a[i]);
    auto foo_2 = set<decltype(foo)::value_type> (foo.begin(), foo.end());
    for(auto j : foo_2) cnt[j].push_back(i);
  }
  vector<int> t(n);
  vector<vector<int>> edges(n);
  for(auto i : cnt) {
    if((int) i.second.size() >= n - 1) {
      printf("NO");
      return 0;
    }
    if((int) i.second.size() == n - 2) {
      vector<int> was(n);
      for(auto j : i.second) was[j] = 1;
      int u = -1, v = -1;
      range(i, 0, n) {
        if(!was[i]) {
          if(~u) v = i;
          else u = i;
        }
      }
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
  }
  bool ok = true;
  int iter = 0;
  A:;
  iter++;
  fill(t.begin(), t.end(), 0);
  function<void(int, int)> dfs = [&] (int v, int c) {
    if(t[v]) {
      if(t[v] != c) ok = false;
      return;
    }
    t[v] = c;
    for(auto i : edges[v]) {
      dfs(i, 3 - c);
    }
  };
  range(i, 0, n) {
    if(!t[i]) {
      dfs(i, uniform_int_distribution<int>(0, 1)(rng) + 1);
    }
  }
  if(!ok) {
    printf("NO");
    return 0;
  }
  vector<int> check(2);
  range(i, 0, n) check[t[i] - 1] = __gcd(check[t[i] - 1], a[i]);
  if(check[0] != 1 || check[1] != 1) {
    if(iter * (int64_t) n > 5000000) {
      printf("NO");
      return 0;
    }
    goto A; 
  }
  printf("YES\n");
  for(auto i : t) printf("%d ", i);
  return 0;
}