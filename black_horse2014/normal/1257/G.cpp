#include <bits/stdc++.h>
using namespace std;
 
/* 
	Copied from Gennady Korotkevitch's template
*/
 
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
			if (-mod() <= x && x < mod()) {
				v = static_cast<Type>(x);
			}
			else {
				v = static_cast<Type>(x % mod());
			}
			(v < 0) && (v += mod());
			return v;
		}
 
		const Type& operator()() const {
			return value;
		}
 
		template <typename U>
		explicit operator U() const {
			return static_cast<U>(value);
		}
 
		constexpr static Type mod() {
			return T::value;
		}
 
		Modular& operator+=(const Modular& other) {
			((value += other.value) >= mod()) && (value -= mod());
			return *this;
		}
 
		Modular& operator-=(const Modular& other) {
			((value -= other.value) < 0) && (value += mod());
			return *this;
		}
 
		template <typename U> Modular& operator+=(const U& other) {
			return *this += Modular(other);
		}
 
		template <typename U> Modular& operator-=(const U& other) {
			return *this -= Modular(other);
		}
 
		Modular& operator++() {
			return *this += 1;
		}
 
		Modular& operator--() {
			return *this -= 1;
		}
 
		Modular operator++(int) {
			Modular result(*this);
			*this += 1;
			return result;
		}
 
		Modular operator--(int) {
			Modular result(*this);
			*this -= 1;
			return result;
		}
 
		Modular operator-() const {
			return Modular(-value);
		}
 
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
 
		Modular& operator/=(const Modular& other) {
			return *this *= Modular(inverse(other.value, mod()));
		}
 
		template <typename U>
		friend const Modular<U>& abs(const Modular<U>& v) {
			return v;
		}
 
		template <typename U>
		friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
		template <typename U>
		friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
		template <typename U>
		friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
	private:
		Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
	return lhs.value == rhs.value;
}
 
template <typename T, typename U> bool operator==(const Modular<T>& lhs, const U& rhs) {
	return lhs == Modular<T>(rhs);
}
 
template <typename T, typename U> bool operator==(const U& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) == rhs;
}
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
	return !(lhs == rhs);
}
 
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, const U& rhs) {
	return !(lhs == rhs);
}
 
template <typename T, typename U> bool operator!=(const U& lhs, const Modular<T>& rhs) {
	return !(lhs == rhs);
}
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
	return lhs.value < rhs.value;
}
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) += rhs;
}
 
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, const U& rhs) {
	return Modular<T>(lhs) += rhs;
}
 
template <typename T, typename U> Modular<T> operator+(const U& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) += rhs;
}
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) -= rhs;
}
 
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) {
	return Modular<T>(lhs) -= rhs;
}
 
template <typename T, typename U> Modular<T> operator-(const U& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) -= rhs;
}
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) *= rhs;
}
 
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, const U& rhs) {
	return Modular<T>(lhs) *= rhs;
}
 
template <typename T, typename U> Modular<T> operator*(const U& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) *= rhs;
}
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) /= rhs;
}
 
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, const U& rhs) {
	return Modular<T>(lhs) /= rhs;
}
 
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) /= rhs;
}
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	for (U p = b; p > 0; p >>= 1, x *= x) {
		if (p & 1) {
			res *= x;
		}
	}
	return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
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
	if (!stream.eof()) {
		stream >> x;
		assert(!stream.fail());
		number.value = Modular<T>::normalize(x);
	}
	return stream;
}
 
/*
//	for dynamic modulo
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
 
//	for static modulo
constexpr int P = 998244353;
using ModInt = Modular<std::integral_constant<decay<decltype(P)>::type, P>>;
 
namespace FFT {
	const int N = 1 << 18;
	using float_type = long double;
	struct Complex {
		float_type x, y;
		Complex(float_type x = 0, float_type y = 0) : x(x), y(y) {}
		Complex& operator+=(const Complex &rhs) {
			x += rhs.x, y += rhs.y;
			return *this;
		}
		Complex& operator-=(const Complex &rhs) {
			x -= rhs.x, y -= rhs.y;
			return *this;
		}
		Complex& operator*=(const Complex &rhs) {
			float_type tx = x * rhs.x - y * rhs.y, ty = x * rhs.y + y * rhs.x;
			x = tx, y = ty;
			return *this;
		}
		Complex operator!() const {
			return {x, -y};
		}
	} f[N], g[N], h[N];
	Complex operator+(const Complex &lhs, const Complex &rhs) {
		return Complex(lhs) += rhs;
	}
	Complex operator-(const Complex &lhs, const Complex &rhs) {
		return Complex(lhs) -= rhs;
	}
	Complex operator*(const Complex &lhs, const Complex &rhs) {
		return Complex(lhs) *= rhs;
	}
	const float_type PI = acos(-1);
	void FFT(Complex* __first, Complex* __last, int D) {
		int N = __last - __first;
		for (int i = 1, j = 0; i < N - 1; i++) {
			for (int k = N / 2; (j ^= k) < k; k >>= 1);
			if (i < j) {
				swap(__first[i], __first[j]);
			}
		}
		for (int n = 1; n < N; n <<= 1) {
			Complex *a = __first, *b = __first + n;
			Complex w = {cos(PI / n), sin(D * PI / n)}, x, cur = 1;
			for (int i = 0; i < N; i += n << 1, cur = 1) {
				for (int j = 0; j < n; j++, a++, b++, cur *= w) {
					(x = cur) *= *b;
					*b = *a - x; *a += x;
				}
				if (i + (n << 1) < N) {
					a += n;
					b += n;
				}
			}
		}
		if (D < 0) {
			for (int i = 0; i < N; i++) {
				__first[i].x /= N;
				__first[i].y /= N;
			}
		}
	}
	template<typename T>
	void multiply(T* a, T* b, int n, int P) {
		for (int i = 0; i < n; i++) {
			f[i] = {(int)a[i] >> 15, (int)a[i] & 32767};
		}
		FFT(f, f + n, 1);
		for (int i = 0; i < n; i++) {
			int j = i ? n - i : 0;
			g[i] = ((!(f[j] * f[j])) - f[i] * f[i]) * Complex(0, 0.5);
		}
		FFT(g, g + n, -1);
		for (int i = 0; i < n; i++) {
			b[i] = ((long long)(g[i].x + 0.5) % P << 15) % P;
		}
		for (int i = 0; i < n; i++) {
			int j = i ? n - i : 0;
			g[i] = (!(f[j] * f[j]) + f[i] * f[i]) * Complex(-0.25, 0.25) + !f[j] * f[i] * Complex(0.5, 0.5);
		}
		FFT(g, g + n, -1);
		for (int i = 0; i < n; i++) {
			b[i] = (b[i] + (long long)(g[i].x + 0.5) + (((long long)(g[i].y + 0.5) % P) << 30)) % P;
		}
	}
	template<typename T> // T can be int or ModInt
	void multiply(T* a, T* b, T* c, int n, int P) {
		for (int i = 0; i < n; i++) {
			f[i] = {(int)a[i] >> 15, (int)a[i] & 32767};
			g[i] = {(int)b[i] >> 15, (int)b[i] & 32767};
		}
		FFT(f, f + n, 1);
		FFT(g, g + n, 1);
		for (int i = 0; i < n; i++) {
			int j = i ? n - i : 0;
			h[i] = (!(f[j] * g[j]) - f[i] * g[i]) * Complex(0, 0.5);
		}
		FFT(h, h + n, -1);
		for (int i = 0; i < n; i++) {
			c[i] = (((long long)(h[i].x + 0.5) % P) << 15) % P;
		}
		for (int i = 0; i < n; i++) {
			int j = i ? n - i : 0;
			h[i] = (!(f[j] * g[j]) + f[i] * g[i]) * Complex(-0.25, 0.25) + (!f[j] * g[i] + f[i] * !g[j]) * Complex(0.25, 0.25);
		}
		FFT(h, h + n, -1);
		for (int i = 0; i < n; i++) {
			c[i] = (long long)(c[i] + (long long)(h[i].x + 0.5) + (((long long)(h[i].y + 0.5) % P) << 30)) % P;
		}
	}
};
 
const int N = 1 << 18;
 
template <typename T>
vector<T> multiply(const vector<T> &a, const vector<T> &b, int P) {
	if (a.empty()) {
		return b;
	}
	if (b.empty()) {
		return a;
	}
	int m = a.size() + b.size() - 2;
	if (m <= 32) {
		vector<T> ret(m + 1);
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				ret[i + j] += a[i] * b[j];
			}
		}
		return ret;
	}
	int n = 1 << 32 - __builtin_clz(m);
	assert(n <= N);
	static T __a[N], __b[N], __c[N];
	for (int i = 0; i < n; i++) {
		__a[i] = i < a.size() ? a[i] : 0;
		__b[i] = i < b.size() ? b[i] : 0;
	}
	FFT::multiply(__a, __b, __c, n, P);
	return vector<T>(__c, __c + m + 1);
}
 
using Polynomial = vector<ModInt>;
 
Polynomial& operator *= (Polynomial &lhs, const Polynomial &rhs) {
	return lhs = multiply(lhs, rhs, ModInt::mod());
}
 
Polynomial operator * (const Polynomial &lhs, const Polynomial &rhs) {
	Polynomial ret(lhs);
	return ret *= rhs;
}
 
Polynomial product(const vector<Polynomial> &a) {
	function<bool(Polynomial, Polynomial)> compare = [&](Polynomial lhs, Polynomial rhs) {
		return lhs.size() > rhs.size();
	};
	priority_queue<Polynomial, vector<Polynomial>, decltype(compare)> Q(a.begin(), a.end(), compare);
	while (Q.size() > 1) {
		auto x = Q.top(); Q.pop();
		auto y = Q.top(); Q.pop();
		Q.push(x * y);
	}
	return Q.top();
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	vector<Polynomial> a;
	for (auto t : cnt) {
		a.push_back(Polynomial(t.second + 1, 1));
	}
	cout << product(a)[n / 2] << '\n';
	return 0;
}