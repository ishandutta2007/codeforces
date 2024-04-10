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

using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;

const int MN = 1e5 + 5;
int a[MN], spf[MN];
Mint pw[9][20 * MN];
int id[MN];
vector<int> pf;
vector<int> get (int x) {
	if (x >= MN) {
		vector<int> ret;
		for (int i = 2; i * i <= x; i++) if (x % i == 0) {
			while (x % i == 0) {
				ret.push_back(i);
				x /= i;
			}
		}
		if (x > 1) ret.push_back(x);
		return ret;
	}
	vector<int> ret;
	while (x > 1) {
		ret.push_back(spf[x]);
		x /= spf[x];
	}
	return ret;
}
struct Node {
	vector<int> ppw, lzpw;
	Mint val,lz,lzval,sum;
} tree[MN<<2];
#define lc ind<<1
#define rc ind<<1|1
void build (int ind, int l, int r) {
	tree[ind].lz = tree[ind].lzval = 1;
	if (l == r) {
		tree[ind].sum = a[l];
		tree[ind].val = 1;
		tree[ind].ppw.resize((int)pf.size());
		tree[ind].lzpw.resize((int)pf.size());
		for (int p : get(a[l])) {
			if (id[p] == -1) tree[ind].val *= p;
			else tree[ind].ppw[id[p]]++;
		}
		return;
	}
	int mid = (l + r) / 2;
	build(lc,l,mid); build(rc,mid+1,r);
	tree[ind].ppw.resize((int)pf.size());
	tree[ind].lzpw.resize((int)pf.size());
	tree[ind].sum = tree[lc].sum + tree[rc].sum;
}
void push_down (int ind, int l, int r) {
	tree[ind].sum *= tree[ind].lz;
	tree[ind].val *= tree[ind].lzval;
	for (int j = 0; j < (int)tree[ind].ppw.size(); j++)
		tree[ind].ppw[j] += tree[ind].lzpw[j];
	if (l != r) {
		for (int i : {lc,rc}) {
			tree[i].lz *= tree[ind].lz;
			tree[i].lzval *= tree[ind].lzval;
			for (int j = 0; j < (int)tree[ind].ppw.size(); j++)
				tree[i].lzpw[j] += tree[ind].lzpw[j];
		}
	}
	tree[ind].lz = tree[ind].lzval = 1;
	for (int j = 0; j < (int)tree[ind].ppw.size(); j++)
		tree[ind].lzpw[j] = 0;
}
void update (int ind, int tl, int tr, int l, int r, int v) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return;
	if (l <= tl && tr <= r) {
		tree[ind].lz *= v;
		for (int p : get(v)) {
			if (id[p] == -1) tree[ind].lzval *= p;
			else tree[ind].lzpw[id[p]]++;
		}
		push_down(ind,tl,tr);
		return;
	}
	int mid = (tl + tr) / 2;
	update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	tree[ind].sum = tree[lc].sum + tree[rc].sum;
}
Mint query (int ind, int tl, int tr, int l, int r) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return 0;
	if (l <= tl && tr <= r) return tree[ind].sum;
	int mid = (tl + tr) / 2;
	return query(lc,tl,mid,l,r) + query(rc,mid+1,tr,l,r);
}
void div (int ind, int tl, int tr, int i, int v) {
	push_down(ind,tl,tr);
	if (tl == tr) {
		for (int p : get(v)) {
			if (id[p] == -1) tree[ind].val /= p;
			else tree[ind].ppw[id[p]]--;
		}
		tree[ind].sum = tree[ind].val;
		for (int j = 0; j < (int)tree[ind].ppw.size(); j++) {
			tree[ind].sum *= pw[j][tree[ind].ppw[j]];
		}
		return;
	}
	int mid = (tl + tr) / 2;
	if (i <= mid) {
		div(lc,tl,mid,i,v);
		push_down(rc,mid+1,tr);
	} else {
		div(rc,mid+1,tr,i,v);
		push_down(lc,tl,mid);
	}
	tree[ind].sum = tree[lc].sum + tree[rc].sum;
}
int main () {
	{
		for (int i = 2; i < MN; i++) if (!spf[i]) {
			spf[i] = i;
			if ((long long)i * i < MN)
				for (int j = i*i; j < MN; j += i)
					if (!spf[j])
						spf[j] = i;
		}
	}
	int n,m; scanf ("%d %d",&n,&m);
	md = m;
	pf = get(m);
	sort(pf.begin(),pf.end());
	pf.erase(unique(pf.begin(),pf.end()),pf.end());
	memset(id,-1,sizeof id);
	for (int i = 0; i < (int)pf.size(); i++) {
		if (pf[i]<MN) id[pf[i]] = i;
		pw[i][0] = 1;
		for (int j = 1; j < 20 * MN; j++)
			pw[i][j] = pw[i][j-1] * pf[i];
	}
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	build(1,1,n);
	int q; scanf ("%d",&q);
	while (q--) {
		int t; scanf ("%d",&t);
		if (t == 1) {
			int l,r,x; scanf ("%d %d %d",&l,&r,&x);
			update(1,1,n,l,r,x);
		} else if (t == 2) {
			int i,x; scanf ("%d %d",&i,&x);
			div(1,1,n,i,x);
		} else {
			int l,r; scanf ("%d %d",&l,&r);
			printf ("%d\n",query(1,1,n,l,r)());
		}
	}
	return 0;
}
/*
5 2
4 1 2 3 5
3
1 2 3 6
2 3 4
3 3 4
*/