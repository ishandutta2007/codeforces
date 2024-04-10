// +----------------------------------
// | BigInteger Library Version 1.1
// | Author: square1001, E869120
// | Date: July 24th, 2016
// | Language: C++11 / C++14
// +---------------------------------

#ifndef ___Class_BasicInteger
#define ___Class_BasicInteger

// ------ Includes ------ //
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <complex>
#include <iostream>
#include <algorithm>

// ------ BasicInteger ------ //
class BasicInteger {
public:
	// ------ Variable ------ //
	int size_;
	std::vector<int> v;

	// ------ Private Function ------ //
	void resize(int size__) {
		size_ = size__;
		v.resize(size_, 0);
	}
	int digit() {
		int digit = 1;
		for (int i = size_ - 1; i >= 1; i--) {
			if (v[i] != 0) {
				digit = i + 1;
				break;
			}
		}
		return digit;
	}
	void revalue() {
		int r = digit();
		while (size_ >= r * 2) size_ >>= 1;
		v.resize(size_);
	}

	// ------ Constants ------ //
	static const int maxdigit = 4; // maxdigit <= 4
	static const int maxvalue = 10000; // maxvalue = pow(10, maxdigit)

									   // ------ Constructor ------ //
	BasicInteger() {
		size_ = 1;
		v.resize(size_, 0);
	}
	BasicInteger(const std::string &b) {
		std::string s = b;
		int r = (s.size() + maxdigit - 1) / maxdigit;
		size_ = 1;
		while (size_ < r) size_ <<= 1;
		v.resize(size_);
		std::reverse(s.begin(), s.end());
		int val = 0, cnt = 0, t = 0, p = 1;
		for (char c : s) {
			val += (c - 48) * p; p *= 10;
			if (++cnt == maxdigit) {
				v[t++] = val;
				val = 0, cnt = 0, p = 1;
			}
		}
		if (cnt > 0) v[t] = val;
	}
	BasicInteger(long long x) {
		assert(x >= 0);
		(*this) = x;
	}
	BasicInteger(const BasicInteger& b) {
		size_ = b.size_;
		v = b.v;
	}

	// ------ Functions ------ //
	int size() const {
		return size_;
	}
	int digit() const {
		for (int i = size_ - 1; i >= 1; i--) {
			if (v[i] > 0) return i + 1;
		}
		return 1;
	}
	std::string to_string() const {
		std::string ret = "";
		for (int i = size_ - 1; i >= 0; i--) {
			std::string t = std::to_string(v[i]);
			while (t.size() < BasicInteger::maxdigit) t = "0" + t;
			ret += t;
		}
		int r = 0;
		while (r < size_ * 4 && ret[r] == '0') r++;
		if (r == size_ * 4) return "0";
		return ret.substr(r, size_ * 4);
	}

	// ------ Basic Operators ------ //
	BasicInteger& operator=(const long long x) {
		(*this) = BasicInteger(std::to_string(x));
		return (*this);
	}
	BasicInteger& operator=(const BasicInteger& b) {
		if (&b != this) {
			size_ = b.size_;
			v = b.v;
		}
		return (*this);
	}

	// ------ Comparision Operators ------ //
	friend bool operator==(const BasicInteger& b1, const BasicInteger& b2) {
		return b1.v == b2.v;
	}
	friend bool operator!=(const BasicInteger& b1, const BasicInteger& b2) {
		return b1.v != b2.v;
	}
	friend bool operator<(const BasicInteger& b1, const BasicInteger& b2) {
		if (b1.size_ != b2.size_) return b1.size_ < b2.size_;
		int n = b1.size_;
		for (int i = n - 1; i >= 0; i--) {
			if (b1.v[i] != b2.v[i]) return b1.v[i] < b2.v[i];
		}
		return false;
	}
	friend bool operator>(const BasicInteger& b1, const BasicInteger& b2) {
		return b2 < b1;
	}
	friend bool operator<=(const BasicInteger& b1, const BasicInteger& b2) {
		return !(b1 > b2);
	}
	friend bool operator>=(const BasicInteger& b1, const BasicInteger& b2) {
		return !(b1 < b2);
	}

	// ------ Addition Operator ------ //
	friend BasicInteger operator+(const BasicInteger& b1, const BasicInteger& b2) {
		BasicInteger ret(b1);
		int n = std::max(b1.size_, b2.size_);
		ret.resize(n);
		for (int i = 0; i < b2.size_; i++) ret.v[i] += b2.v[i];
		for (int i = 0; i < n - 1; i++) {
			if (ret.v[i] >= BasicInteger::maxvalue) {
				ret.v[i] -= BasicInteger::maxvalue;
				ret.v[i + 1]++;
			}
		}
		if (ret.v[n - 1] >= BasicInteger::maxvalue) {
			ret.resize(n << 1);
			ret.v[n - 1] -= BasicInteger::maxvalue;
			ret.v[n] = 1;
		}
		return ret;
	}

	// ------ Subtraction ------ //
	friend BasicInteger operator-(const BasicInteger& b1, const BasicInteger& b2) {
		assert(b1 >= b2);
		BasicInteger ret(b1);
		for (int i = 0; i < b2.size_; i++) ret.v[i] -= b2.v[i];
		for (int i = 0; i < ret.size_; i++) {
			if (ret.v[i] < 0) {
				ret.v[i] += BasicInteger::maxvalue;
				ret.v[i + 1]--;
			}
		}
		ret.revalue();
		return ret;
	}

	// ------ Multiplication ------ //
	friend BasicInteger operator*(const BasicInteger& b1, const BasicInteger& b2) {
		BasicInteger ret;
		BasicInteger b3(b1 < b2 ? b2 : b1); // large
		BasicInteger b4(b1 < b2 ? b1 : b2); // small
		int d1 = b3.size_, d2 = b4.size_;
		ret.resize(d1 << 1);
		for (int i = 0; i < d1; i += d2) {
			std::vector<int> sub(b3.v.begin() + i, b3.v.begin() + i + d2);
			std::vector<int> res;
			if (d1 <= 8192) res = BasicInteger::FastFourierTransform(sub, b4.v);
			else res = BasicInteger::NumberTheoreticConvolution(sub, b4.v);
			for (int j = 0; j < (d2 << 1); j++) {
				ret.v[j + i] += res[j];
				if (ret.v[j + i] >= BasicInteger::maxvalue) {
					ret.v[j + i] -= BasicInteger::maxvalue;
					ret.v[j + i + 1]++;
				}
			}
		}
		ret.revalue();
		return ret;
	}

	// ------ Normal Multiplication ------ //
	inline static std::vector<int> NormalMul(const std::vector<int>& b1, const std::vector<int>& b2) {
		int n = b1.size(); // n <= 2^30, b1 and b2 is the same size!
		std::vector<long long> ret(n << 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret[i + j] += 1LL * b1[i] * b2[j];
			}
		}
		for (int i = 0; i < (n << 1) - 1; i++) {
			ret[i + 1] += ret[i] / BasicInteger::maxvalue;
			ret[i] %= BasicInteger::maxvalue;
		}
		std::vector<int> res(ret.begin(), ret.end());
		return res;
	}

	// ------ Fast Fourier Transform ------ //
	inline static void DiscreteFourierTransform(std::vector<std::complex<double> > &f, bool rev = false) {
		int n = f.size(); // n <= 8192
		const double pi = acos(-1.0);
		for (int i = 0, j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k > (i ^= k); k >>= 1);
			if (i > j) swap(f[i], f[j]);
		}
		for (int b = 2; b <= n; b <<= 1) {
			std::complex<double> wr = std::polar(1.0, (rev ? -2.0 : 2.0) * pi / b);
			for (int i = 0; i < n; i += b) {
				std::complex<double> w(1.0, 0.0);
				for (int j = 0; j < b >> 1; j++) {
					std::complex<double> f0 = f[i + j], f1 = w * f[i + j + (b >> 1)];
					f[i + j] = f0 + f1;
					f[i + j + (b >> 1)] = f0 - f1;
					w *= wr;
				}
			}
		}
		if (rev) {
			double mul = 1.0 / n;
			for (int i = 0; i < n; i++) f[i] *= mul;
		}
	}
	inline static std::vector<int> FastFourierTransform(std::vector<int> b1, std::vector<int> b2) {
		int n = b1.size() * 2; // b1 and b2 is the same size!
		std::vector<std::complex<double> > f0(n), f1(n);
		for (int i = 0; i < n >> 1; i++) {
			f0[i] = b1[i];
			f1[i] = b2[i];
		}
		DiscreteFourierTransform(f0);
		DiscreteFourierTransform(f1);
		for (int i = 0; i < n; i++) f0[i] *= f1[i];
		DiscreteFourierTransform(f0, true);
		std::vector<long long> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = (long long)(f0[i].real() + 0.5);
		}
		for (int i = 0; i < n - 1; i++) {
			res[i + 1] += res[i] / BasicInteger::maxvalue;
			res[i] %= BasicInteger::maxvalue;
		}
		std::vector<int> ret(res.begin(), res.end());
		return ret;
	}

	// ------ Number Theoretic Transform ------ //
	inline static int modpow(int a, int b, int m) {
		int ret = 1;
		for (int i = 30; i >= 0; i--) {
			ret = 1LL * ret * ret % m;
			if (b & (1 << i)) ret = 1LL * ret * a % m;
		}
		return ret;
	}
	inline static void extgcd(int a, int b, int &x, int &y) {
		if (b) extgcd(b, a % b, y, x), y -= (a / b) * x;
		else x = 1, y = 0;
	}
	inline static unsigned long long modmul(unsigned long long a, unsigned long long b, unsigned long long m) {
		unsigned long long res = 0; a %= m, b %= m;
		while (a) {
			if (a & 1) res += b; a >>= 1;
			if (res >= m) res -= m; b <<= 1;
			if (b >= m) b -= m;
		}
		return res;
	}
	inline static void NumberTheoreticTransform(std::vector<int> &f, int mod, int root, bool rev = false) {
		int n = f.size();
		for (int i = 0, j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k > (i ^= k); k >>= 1);
			if (i < j) std::swap(f[i], f[j]);
		}
		for (int b = 1; b < n; b <<= 1) {
			int wr = modpow(root, (mod - 1) / (b << 1), mod);
			if (rev) wr = modpow(wr, mod - 2, mod);
			for (int i = 0; i < n; i += (b << 1)) {
				int w = 1;
				for (int j = i; j < i + b; j++) {
					int f0 = f[j], f1 = 1LL * w * f[j + b] % mod;
					f[j] = f0 + f1; if (f[j] >= mod) f[j] -= mod;
					f[j + b] = f0 - f1; if (f[j + b] < 0) f[j + b] += mod;
					w = 1LL * w * wr % mod;
				}
			}
		}
		if (rev) {
			int mul = modpow(n, mod - 2, mod);
			for (int i = 0; i < n; i++) {
				f[i] = 1LL * f[i] * mul % mod;
			}
		}
	}
	inline static std::vector<int> NumberTheoreticModularConvolution(std::vector<int> f0, std::vector<int> f1, int mod, int root) {
		int n = f0.size() * 2; // f0 and f1 is the same size!
		f0.resize(n);
		f1.resize(n);
		NumberTheoreticTransform(f0, mod, root);
		NumberTheoreticTransform(f1, mod, root);
		for (int i = 0; i < n; i++) f0[i] = 1LL * f0[i] * f1[i] % mod;
		NumberTheoreticTransform(f0, mod, root, true);
		return f0;
	}
	inline static std::vector<int> NumberTheoreticConvolution(std::vector<int> b1, std::vector<int> b2) {
		int n = b1.size() * 2; // b1 and b2 is the same size!
		int mod1 = 469762049, r1 = 3;
		int mod2 = 754974721, r2 = 11;
		std::vector<int> f0 = NumberTheoreticModularConvolution(b1, b2, mod1, r1);
		std::vector<int> f1 = NumberTheoreticModularConvolution(b1, b2, mod2, r2);
		int t1, t2;
		extgcd(mod1, mod2, t1, t2);
		if (t1 < 0) t1 += mod2;
		if (t2 < 0) t2 += mod1;
		long long w0 = 1LL * mod1 * mod2;
		long long w1 = 1LL * mod2 * t2;
		long long w2 = 1LL * mod1 * t1;
		std::vector<long long> res(n);
		for (int i = 0; i < n; i++) {
			long long x1 = modmul(f0[i], w1, w0);
			long long x2 = modmul(f1[i], w2, w0);
			res[i] = (x1 + x2) % w0;
		}
		for (int i = 0; i < n - 1; i++) {
			res[i + 1] += res[i] / BasicInteger::maxvalue;
			res[i] %= BasicInteger::maxvalue;
		}
		std::vector<int> ret(res.begin(), res.end());
		return ret;
	}

	// ------ In / Out Operator ------ //
	friend std::istream& operator >> (std::istream& is, BasicInteger& b) {
		std::string res;
		is >> res;
		b = BasicInteger(res);
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, const BasicInteger& b) {
		os << b.to_string();
		return os;
	}
};

#endif

#include <iostream>
#include <algorithm>
using namespace std;

BasicInteger power(int a, int b) {
	BasicInteger p = 1, q = a;
	for (int i = 0; i < 22; i++) {
		if ((1 << i) > b) break;
		if ((b / (1 << i)) % 2 == 1) { p = p * q; }
		if ((2 << i) <= b) q = q * q;
	}
	return p;
}

long double logs(BasicInteger Y) {
	int firsts = 0;
	for (int i = Y.size() - 1; i >= 0; i--) {
		if (Y.v[i] >= 1) { firsts = i; break; }
	}

	int BASE = firsts - 4; if (BASE < 0) BASE = 0;
	long double e = 0, r = 1;
	for (int i = BASE; i <= firsts; i++) {
		e += 1.0L * r * Y.v[i]; r *= 10000;
	}
	return log10(e) + 1.0L * Y.maxdigit * BASE;
}

string ToString(BasicInteger V) {
	string S = ""; bool flag = false;
	for (int i = V.size() - 1; i >= 0; i--) {
		if (V.v[i] >= 1) flag = true;
		string SS = to_string(V.v[i]);
		while (SS.size() < V.maxdigit) SS = "0" + SS;
		S += SS;
	}

	int firsts = 0;
	for (int i = 0; i < S.size(); i++) { if (S[i] != '0') { firsts = i; break; } }
	return S.substr(firsts, S.size() - firsts);
}

BasicInteger V; long double R, I2, I3; int maxn = 0, d[2000000];

int main() {
	cin >> V; R = logs(V);

	string TT = ToString(V);
	if (TT == "1") { cout << "1" << endl; return 0; }
	if (TT == "2") { cout << "2" << endl; return 0; }
	if (TT == "3") { cout << "3" << endl; return 0; }
	if (TT == "4") { cout << "4" << endl; return 0; }
	if (TT == "5") { cout << "5" << endl; return 0; }

	I2 = log10(2.0L);
	I3 = log10(3.0L);
	for (int i = 2; i <= 10000000; i++) {
		long double rem = 1.0L * I3 * (long double)((int)((i + 2) / 3));
		if (i % 3 == 1 || i % 3 == 2) rem += (I2 - I3);
		if (i % 3 == 1) rem += (I2 - I3);
		
		if (fabs(rem - R) < 1e-6) {
			int d3 = (i + 2) / 3, d2 = 0;
			if (i % 3 == 1 || i % 3 == 2) { d3--; d2++; }
			if (i % 3 == 1) { d3--; d2++; }

			BasicInteger Y = power(3, d3);
			string YY = ToString(Y);
			for (int j = 0; j < YY.size(); j++) d[YY.size() - 1 - j] = (YY[j] - '0');
			for (int j = 0; j < d2; j++) {
				for (int k = 0; k < 2000000; k++) d[k] *= 2;
			}
			for (int k = 0; k < 1800000; k++) {
				while (d[k] >= 10) { d[k] -= 10; d[k + 1]++; }
			}

			string Y2 = ""; bool flag1 = false;
			for (int k = 1800000; k >= 0; k--) {
				if (d[k] >= 1) flag1 = true;
				if (flag1 == true) Y2 += ('0' + d[k]);
			}

			string Y3 = ToString(V);
			if (Y3 <= Y2) cout << i << endl;
			else cout << i + 1 << endl;
			return 0;
		}
		else {
			if (rem < R) maxn = i;
			else break;
		}
	}
	cout << maxn + 1 << endl;
	return 0;
}