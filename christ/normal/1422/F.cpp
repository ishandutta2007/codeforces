#include <bits/stdc++.h>
using namespace std;
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 1e9+7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
const int MN = 2e5+5, B = 450, BB = 10, SZ = 90;
int sp[MN], a[MN], big[MN];
map<int, int> cnt[MN];
Mint pw[B][B];
bool exists[MN];
int psa[SZ][6][MN];
int lst[MN];
Mint ret[MN];
int main () {
	vector<int> small;
	for (int i = 2; i < MN; i++) if (!sp[i]) {
		if (i >= BB && i < B) small.push_back(i);
		sp[i] = i;
		if ((long long)i * i < MN) {
			for (int j = i * i; j < MN; j += i) if (!sp[j]) sp[j] = i;
		}
	}
	for (int x = 2; x < B; x++) {
		pw[x][0] = 1;
		for (int i = 1; i < B; i++) pw[x][i] = pw[x][i-1] * x;
	}
	int n; scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		int cur = a[i];
		while (cur > 1) {
			if (sp[cur] >= B) {
				big[i] = sp[cur];
				exists[sp[cur]] = true;
			}
			else ++cnt[i][sp[cur]];
			cur /= sp[cur];
		}
	}
	int q; scanf ("%d",&q);
	vector<array<int,2>> queries(q);
	for (auto &[l,r] : queries) scanf ("%d %d",&l,&r);
	for (int i = 0; i < q; i++) ret[i] = 1;
	vector<vector<int>> tree(BB);
	auto queryT = [&] (int t, int l, int r) {
		int ret = 0;
		for (l += n-1, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) ret = max(ret,tree[t][l++]);
			if (r&1) ret = max(ret,tree[t][--r]);
		}
		return ret;
	};
	{
		for (int t = 2; t < BB; t++) {
			tree[t].resize(2*n);
			for (int i = n; i < 2*n; i++) {
				auto it = cnt[i-n+1].find(t);
				tree[t][i] = it == cnt[i-n+1].end() ? 0 : it->second;
			}
			for (int i = n-1; i > 0; i--) tree[t][i] = max(tree[t][2*i],tree[t][2*i+1]);
		}
	}
	{
		for (int idx = 0; idx < (int)small.size(); idx++) {
			int t = small[idx];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j < 6; j++) psa[idx][j][i] += psa[idx][j][i-1];
				auto it = cnt[i].find(t);
				if (it != cnt[i].end()) ++psa[idx][it->second][i];
			}
		}
	}
	Mint tot = 1;
	for (int i = 0; i < MN; i++) if (exists[i]) tot *= i;
	vector<vector<pair<int,Mint>>> bit(n+1);
	auto update = [&] (int L, int R, Mint v) {
		for (int i = L; i <= n; i += i & -i) {
			bit[i].push_back({R,v});
		}
	};
	for (int i = 1; i <= n; i++) if (big[i]) {
		int L = lst[big[i]]+1;
		if (L < i) update(L,i-1,((Mint)1)/big[i]); //vAt[L].push_back({i-1,big[i]});
		lst[big[i]] = i;
	}
	for (int i = 0; i < MN; i++) if (lst[i] > 0) {
		int L = lst[i] + 1;
		if (L <= n) update(L,n,((Mint)1)/i);//vAt[L].push_back({n,i});
	}
	for (int i = 1; i <= n; i++) {
		sort(bit[i].begin(),bit[i].end());
		for (int j = (int)bit[i].size() - 2; j >= 0; j--)
			bit[i][j].second *= bit[i][j+1].second;
	}
	auto query = [&] (int L, int R) {
		Mint ret = 1;
		for (int i = L; i > 0; i ^= i & -i) {
			auto it = lower_bound(bit[i].begin(),bit[i].end(),pair<int,Mint>{R,(Mint)0}); //does this even make sense? its technically not sorted...
			if (it != bit[i].end()) ret *= it->second;
		}
		return ret;
	};
	int last = 0;
	for (auto &[l,r] : queries) {
		l = (last + l) % n + 1;
		r = (last + r) % n + 1;
		if (l > r) swap(l,r);
		Mint ret = tot;
		for (int t = 2; t < BB; t++) {
			ret *= pw[t][queryT(t,l,r)];
		}
		for (int idx = 0; idx < (int)small.size(); idx++) {
			int t = small[idx];
			for (int j = 5; j >= 1; j--) if (psa[idx][j][r] > psa[idx][j][l-1]) {
				ret *= pw[t][j];
				break;
			}
		}
		ret *= query(l,r);
		last = ret();
		printf ("%d\n",ret());
	}
	return 0;
}