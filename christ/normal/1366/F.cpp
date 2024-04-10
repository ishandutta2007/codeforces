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
const int MN = 2e3 + 5;
long long dist[MN];
int len[MN];
vector<array<int,2>> adj[MN];
int main () {
	int n,m,q; scanf ("%d %d %d",&n,&m,&q);
	vector<array<int,3>> edges(m);
	for (auto &[u,v,w] : edges) {
		scanf ("%d %d %d",&u,&v,&w);
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<array<long long, 2>> got;
	for (auto &[u,v,W] : edges) { 
		//end with this edge
		//minimize L_p * W - V_p
		memset(dist,0x3f,sizeof dist);
		dist[1] = len[1] = 0;
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long, int>>> pq;
		pq.push({0,1});
		while (!pq.empty()) {
			auto [d,cur] = pq.top(); pq.pop();
			for (auto [i,w] : adj[cur]) if (w <= W && dist[cur] + W - w < dist[i]) {
				dist[i] = dist[cur] + W - w;
				len[i] = len[cur] + 1;
				pq.push({dist[i],i});
			}
		}
		if (min(dist[u],dist[v]) > 1e18) continue;
		got.push_back({W,-min(dist[u],dist[v])});
	}
	auto intersect = [&] (int i, int j) {
		return (got[i][1] - got[j][1]) / (got[j][0] - got[i][0]);
	};
	auto go = [&] (int i, int j, int k) { //intersect(i,k) >= intersect(j,k)
		return (__int128)(got[i][1] - got[k][1])*(got[k][0] - got[j][0])  >= (__int128)(got[k][0] - got[i][0])*(got[j][1] - got[k][1]);
	};
	auto f = [&] (long long x) {
		return ((Mint)x) * (x + 1) / 2;
	};
	sort(got.begin(),got.end());
	//x + 0 = 7x - 5
	//5 = 8x
	//x = 5/8 = 0
	vector<int> cmp;
	for (int i = 0; i < (int)got.size(); i++) {
		while ((int)cmp.size() > 1 && (got[cmp.back()][0] == got[i][0] || go(cmp.end()[-2],cmp.back(),i)))
			cmp.pop_back();
		if (!cmp.empty() && got[cmp.back()][0] == got[i][0])
			cmp.pop_back();
		cmp.push_back(i);
	}
	int p = 0;
	while (p+1<(int)cmp.size() && intersect(cmp[p],cmp[p+1]) <= 0) p++;
	int st = 1;
	Mint ret = 0;
	while (st <= q && p < (int)cmp.size()) {
		int ed = (p + 1 == (int)cmp.size()) ? md : intersect(cmp[p],cmp[p+1]);
		ed = min(ed,q);
		// cmp[p][0] * x + cmp[p][1] for x in range [st,ed]
		if (st <= ed) {
			ret += got[cmp[p]][1] * (ed - st + 1) + (f(ed) - f(st-1)) * got[cmp[p]][0];
			st = ed + 1;
		}
		++p;
	}
	printf ("%d\n",ret());
	return 0;
}