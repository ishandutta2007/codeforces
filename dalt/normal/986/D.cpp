#if (defined CF986D) || (defined ONLINE_JUDGE)

#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<complex>
#include<stdio.h>

#define INF 100000000
#define SWAP(a, b, type) {type _tmp = a; a = b; b = _tmp;}
#define PI 3.14159265358979323846
#define ll long long
#define ld long double

//Math functions
namespace mathematic {

	int intRound(double x) {
		return int(x + 0.5);
	}
	int intRound(float x) {
		return int(x + 0.5);
	}

	int numberOfLeadingZero(unsigned int i)
	{
		// HD, Figure 5-6
		if (i == 0)
			return 32;
		int n = 1;
		if (i >> 16 == 0) { n += 16; i <<= 16; }
		if (i >> 24 == 0) { n += 8; i <<= 8; }
		if (i >> 28 == 0) { n += 4; i <<= 4; }
		if (i >> 30 == 0) { n += 2; i <<= 2; }
		n -= i >> 31;
		return n;
	}

	template<class T> inline T &min(T&a, T&b) {
		return a <= b ? a : b;
	}

	template<class T> inline const T & min(const T & a, const T & b) {
		return a <= b ? a : b;
	}

	template<class T> inline T &max(T&a, T&b) {
		return a >= b ? a : b;
	}

	template<class T> inline const T &max(const T &a, const T &b) {
		return a >= b ? a : b;
	}
}

//AutoArray
namespace container {

	template<class T> class AutoArray {
	public:
		AutoArray(int cap) : m_data(new T[cap]) {
			m_length = m_capacity = cap;
		}
		void ensureCapacity(int newCap) {
			if (m_capacity < newCap)
			{
				int proper = 1 << 32 - mathematic::numberOfLeadingZero(newCap - 1);
				T *tmp = new T[proper];
				memcpy(tmp, m_data, m_length * sizeof(T));

				//delete[] m_data;

				m_data = tmp;
				m_capacity = proper;
			}
		}
		inline void setLength(int newLength) {
			ensureCapacity(newLength);
			m_length = newLength;
		}
		void expand(int newLength, T def)
		{
			ensureCapacity(newLength);
			while (m_length < newLength)
			{
				m_data[m_length++] = def;
			}

			m_length = newLength;
		}

		inline void push_back(const T& val) {
			ensureCapacity(m_length + 1);
			m_data[m_length++] = val;
		}

		inline T pop_back() {
			return m_data[--m_length];
		}

		inline T& operator[](int i) {
			return m_data[i];
		}

		inline int length() const { return m_length; }
		inline AutoArray<T> &operator=(const AutoArray<T> &other) {
			setLength(other.length);
			memcpy(m_data, other->m_data, sizeof(T) * m_length);
		}
		inline T *data() {
			return m_data;
		}
		inline const T *data() const {
			return m_data;
		}
		void swap(AutoArray<T> &b) {
			T *a1 = m_data;
			int a2 = m_length;
			int a3 = m_capacity;

			m_data = b.m_data;
			m_length = b.m_length;
			m_capacity = b.m_capacity;

			b.m_data = a1;
			b.m_length = a2;
			b.m_capacity = a3;
		}
	private:
		T * m_data;
		int m_length;
		int m_capacity;
	};
}

//StringBuilder
namespace string {
	using container::AutoArray;

	class StringBuilder {
	public:
		inline StringBuilder(int size) :m_data(size) {
			m_data.setLength(0);
		}
		inline StringBuilder &ensureCapacity(int size) {
			m_data.ensureCapacity(size);
			return *this;
		}
		inline StringBuilder &append(char c) {
			m_data.push_back(c);
			return *this;
		}
		inline StringBuilder &append(int i) {
			if (i < 0)
			{
				m_data.push_back('-');
				append0(-(ll)i);
			}
			else {
				append0(i);
			}
			return *this;
		}
		inline StringBuilder &append(char *data, int len)
		{
			int curLength = m_data.length();
			m_data.setLength(curLength + len);
			memcpy(m_data.data(), data, sizeof(char)*len);
		}
		inline int length() {
			return m_data.length();
		}
		inline char*data() {
			return m_data.data();
		}
		inline StringBuilder &setLength(int l) {
			m_data.setLength(l);
			return *this;
		}

	private:
		inline void append0(unsigned int i) {
			if (i >= 10)
			{
				append0(i / 10);
			}
			m_data.push_back(i % 10 + '0');
		}
		AutoArray<char> m_data;
	};
}

//IOUtil
namespace io {
	using string::StringBuilder;

	class IOUtil {
	public:
		IOUtil() : w_buf(8096) {
#ifndef ONLINE_JUDGE
			freopen("E:\\DATABASE\\TESTCASE\\codeforces\\CF986D.in", "r", stdin);
			freopen("E:\\DATABASE\\TESTCASE\\codeforces\\CF986D.out", "w", stdout);
#endif

			r_next = 0;
			r_cur = 0;
			r_total = 0;
		}

		bool hasMore() {
			skipBlank();
			return r_next != -1;
		}

		int read() {
			while (r_cur >= r_total) {
				r_total = fread(r_buf, sizeof(char), 8096, stdin);
				r_cur = 0;

				if (r_total <= 0)
				{
					return -1;
				}
			}
			return r_buf[r_cur++];
		}

		void skipBlank() {
			while (r_next <= 32 && r_next != -1)
			{
				r_next = read();
			}
		}

		int readInt() {
			skipBlank();

			bool sign = true;
			if (r_next == '-' || r_next == '+')
			{
				sign = r_next == '+';
				r_next = read();
			}

			int val = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				val = val * 10 + r_next - '0';
				r_next = read();
			}

			return sign ? val : -val;
		}


		int readString(char *buf, int limit)
		{
			int originalLimit = limit;

			skipBlank();
			while (limit > 0 && r_next > 32)
			{
				*(buf++) = r_next;
				limit--;
				r_next = read();
			}
			return originalLimit - limit;
		}

		void write(const char *buf, int cnt) {
			w_buf.ensureCapacity(w_buf.length() + cnt);
			for (const char *end = buf + cnt; buf < end; buf++)
			{
				w_buf.append(*buf);
			}
		}

		void write(int c) {
			w_buf.append(c);
		}

		void write(char c) {
			w_buf.append(c);
		}

		void flush() {
			fwrite(w_buf.data(), sizeof(char), w_buf.length(), stdout);
			fflush(stdout);
			w_buf.setLength(0);
		}

		inline StringBuilder &getOutputBuffer() {
			return w_buf;
		}
	private:
		char r_buf[8096];
		char r_next;
		int r_cur;
		int r_total;

		StringBuilder w_buf;
	} IO;

};

//FFT
namespace fft {
	using std::complex;
	using std::queue;
	using container::AutoArray;

	queue<AutoArray<complex<double>>*> g_pool;

	AutoArray<complex<double>>* getResource() {
		if (g_pool.size() == 0)
		{
			return new AutoArray<complex<double>>(0);
		}
		AutoArray<complex<double>> *front = g_pool.front();
		g_pool.pop();
		return front;
	}
	void releaseResource(AutoArray<complex<double>>*res) {
		g_pool.push(res);
	}

	complex<double> g_fft_w_cache[32];
	int g_fft_rev[2000000];
	int g_fft_rev_log = -1;

	void FFT_INIT() {
		for (int i = 0; i < 32; i++)
		{
			double angle = 2 * PI / (1L << i);
			g_fft_w_cache[i] = complex<double>(cos(angle), sin(angle));
		}
	}

	void FFT_BIT_REV_PROCESS(int log)
	{
		if (g_fft_rev_log == log)
		{
			return;
		}

		g_fft_rev_log = log;
		int n = 1 << log;
		int log1 = log - 1;
		for (int i = 1; i < n; i++)
		{
			g_fft_rev[i] = (g_fft_rev[i >> 1] >> 1) | ((1 & i) << log1);
		}
	}



	void FFT_DFT(complex<double> *p, int log) {
		int n = 1 << log;
		FFT_BIT_REV_PROCESS(log);
		for (int i = 0; i < n; i++) {
			if (i >= g_fft_rev[i]) {
				continue;
			}
			SWAP(p[i], p[g_fft_rev[i]], complex<double>);
		}

		for (int d = 0; d < log; d++) {
			int h = 1 << d;
			int h2 = h + h;
			const complex<double>& w1 = g_fft_w_cache[d + 1];
			for (int i = 0; i < n; i += h2) {
				complex<double> w = 1;
				for (int j = 0; j < h; j++) {
					int a = i + j;
					int b = a + h;
					complex<double> t = w * p[b];
					complex<double> e = p[a];
					p[b] = e - t;
					p[a] = e + t;
					w = w * w1;
				}
			}
		}
	}

	void FFT_MUL(complex<double> *a, complex<double> *b, complex<double> *c, int log) {
		int n = 1 << log;
		for (int i = 0; i < n; i++)
		{
			c[i] = a[i] * b[i];
		}
	}

	void FFT_IDFT(complex<double> *p, int log) {
		int n = 1 << log;
		FFT_DFT(p, log);

		double dn = n;
		p[0] /= dn;
		p[n / 2] /= dn;
		//Loop until n - i < i -> 2i > n -> i > n/2
		for (int i = 1, until = n / 2; i < until; i++) {
			int j = n - i;
			p[i] /= dn;
			p[j] /= dn;
			SWAP(p[i], p[j], complex<double>);
		}
	}

	void EASY_FFT(complex<double> *a, complex<double> *b, int log)
	{
		FFT_DFT(a, log);
		FFT_DFT(b, log);
		FFT_MUL(a, b, a, log);
		FFT_IDFT(a, log);
	}
}

//MutableBigInt
namespace number {
	using container::AutoArray;
	using namespace mathematic;
	using std::queue;

	const int CHAR_LEN = 3;
	const int RADIX = intRound(pow(10, CHAR_LEN));
	const int FFT_THRESHOLD = 64;

	queue<AutoArray<int>*> g_pool;
	AutoArray<int>* getResource() {
		if (g_pool.size() == 0)
		{
			return new AutoArray<int>(0);
		}
		AutoArray<int> *front = g_pool.front();
		g_pool.pop();
		return front;
	}
	void releaseResource(AutoArray<int>*res) {
		g_pool.push(res);
	}

	class MutableBigInt {
	public:
		MutableBigInt() : m_digits(1) {
			build();
		}
		MutableBigInt(int v) : m_digits(1) {
			build(v);
		}
		MutableBigInt(char *data, int len) : m_digits(0) {
			build(data, len);
		}
		void build(char *data, int len) {
			char *end = data + len;


			if (data[0] == '-' || data[0] == '+')
			{
				m_sign = data[0] == '-' ? -1 : 1;
				data++;
			}
			else
			{
				m_sign = 1;
			}

			for (; data != end && *data == '0'; data++);

			if (data == end)
			{
				m_sign = 0;
				m_digits.setLength(1);
				m_digits[0] = 0;
				return;
			}

			int digitNum = (end - data + CHAR_LEN - 1) / CHAR_LEN;
			m_digits.setLength(digitNum);

			m_digits[digitNum - 1] = 0;
			for (char *until = end - (digitNum - 1) * CHAR_LEN; data < until; data++)
			{
				m_digits[digitNum - 1] = m_digits[digitNum - 1] * 10 + *data - '0';
			}

			for (int i = digitNum - 2; i >= 0; i--)
			{
				int val = 0;
				for (char *until = data + CHAR_LEN; data < until; data++) {
					val = val * 10 + *data - '0';
				}
				m_digits[i] = val;
			}

			shrink();
		}
		void build(AutoArray<int> &digits, int s) {
			m_sign = s;
			m_digits.swap(digits);

			shrink();
		}
		void build() {
			m_digits.setLength(1);
			m_sign = 0;
			m_digits[0] = 0;
		}
		void build(int x) {
			if (x < 0)
			{
				build((unsigned int)-(ll)x);
				m_sign = -1;
			}
			else {
				build((unsigned int)x);
			}
		}
		void build(unsigned int x)
		{
			if (x == 0)
			{
				build();
				return;
			}
			m_sign = 1;
			m_digits.setLength(0);
			while (x > 0)
			{
				m_digits.push_back(x % RADIX);
				x /= RADIX;
			}

		}
		inline bool operator <(const MutableBigInt&a) const {
			return compare(*this, a) < 0;
		}
		inline bool operator >(const MutableBigInt&a) const {
			return compare(*this, a) > 0;
		}
		inline bool operator <=(const MutableBigInt&a) const {
			return compare(*this, a) <= 0;
		}
		inline bool operator >=(const MutableBigInt&a) const {
			return compare(*this, a) >= 0;
		}
		inline bool operator ==(const MutableBigInt&a) const {
			return compare(*this, a) == 0;
		}
		static int compare(const MutableBigInt&a, const MutableBigInt&b) {
			if (&a == &b)
			{
				return 0;
			}
			if (a.m_sign != b.m_sign)
			{
				return a.m_sign - b.m_sign;
			}
			int aLen = a.length();
			int bLen = b.length();

			if (aLen != bLen)
			{
				return a.m_sign * (aLen - bLen);
			}

			const int*aData = a.m_digits.data();
			const int*bData = b.m_digits.data();

			for (int i = aLen - 1; i >= 0; i--)
			{
				if (aData[i] != bData[i])
				{
					return a.m_sign * (aData[i] - bData[i]);
				}
			}

			return 0;
		}
		inline int operator[](int i)
		{
			return m_digits[i];
		}
		inline MutableBigInt &operator*=(const MutableBigInt& other) {
			mulEqual(*this, other);
			return *this;
		}
		static void mulEqual(MutableBigInt& a, const MutableBigInt& b)
		{
			if (a.length() < FFT_THRESHOLD || b.length() < FFT_THRESHOLD)
			{
				straightForwardMulEqual(a, b);
			}
			else
			{
				if (&a != &b)
				{
					fftDifferMulEqual(a, b);
				}
				else
				{
					a.fftSelfMulEqual();
				}
			}
		}
		void fftSelfMulEqual() {
			int* aData = m_digits.data();
			int aLen = m_digits.length();
			int cLen = aLen + aLen;
			int log = 32 - numberOfLeadingZero(cLen - 2);
			int proper = 1 << log;

			AutoArray<std::complex<double>> *aArray = fft::getResource();
			aArray->setLength(cLen);

			std::complex<double> *aArrayData = aArray->data();
			for (int i = 0; i < aLen; i++)
			{
				aArrayData[i] = aData[i];
			}
			memset(aArrayData + aLen, 0, sizeof(std::complex<double>) * (cLen - aLen));

			fft::FFT_DFT(aArrayData, log);
			fft::FFT_MUL(aArrayData, aArrayData, aArrayData, log);
			fft::FFT_IDFT(aArrayData, log);

			m_digits.setLength(cLen);
			aData = m_digits.data();
			ll remain = 0;
			for (int i = 0, until = cLen - 1; i < until; i++)
			{
				remain += (ll)(aArrayData[i].real() + 0.5);
				aData[i] = remain % RADIX;
				remain /= RADIX;
			}
			aData[cLen - 1] = remain;

			m_sign = m_sign * m_sign;
			shrink();

			fft::releaseResource(aArray);
		}
		static void fftDifferMulEqual(MutableBigInt& a, const MutableBigInt& b) {
			int* aData = a.m_digits.data();
			const int* bData = b.m_digits.data();

			int aLen = a.length();
			int bLen = b.length();

			int cLen = aLen + bLen;
			int log = 32 - numberOfLeadingZero(cLen - 2);
			int proper = 1 << log;

			AutoArray<std::complex<double>> *aArray = fft::getResource();
			AutoArray<std::complex<double>> *bArray = fft::getResource();

			aArray->setLength(cLen);
			bArray->setLength(cLen);

			std::complex<double> *aArrayData = aArray->data();
			std::complex<double> *bArrayData = bArray->data();

			for (int i = 0; i < aLen; i++)
			{
				aArrayData[i] = aData[i];
			}
			memset(aArrayData + aLen, 0, sizeof(std::complex<double>) * (cLen - aLen));

			for (int i = 0; i < bLen; i++)
			{
				bArrayData[i] = bData[i];
			}
			memset(bArrayData + bLen, 0, sizeof(std::complex<double>) * (cLen - bLen));

			fft::EASY_FFT(aArrayData, bArrayData, log);

			a.m_digits.setLength(cLen);
			aData = a.m_digits.data();
			ll remain = 0;
			for (int i = 0, until = cLen - 1; i < until; i++)
			{
				remain += (ll)(aArrayData[i].real() + 0.5);
				aData[i] = remain % RADIX;
				remain /= RADIX;
			}
			aData[cLen - 1] = remain;

			a.m_sign = a.m_sign * b.m_sign;
			a.shrink();

			fft::releaseResource(aArray);
			fft::releaseResource(bArray);
		}
		static void straightForwardMulEqual(MutableBigInt& a, const MutableBigInt& b)
		{
			int* aData = a.m_digits.data();
			const int* bData = b.m_digits.data();

			int aLen = a.length();
			int bLen = b.length();

			int cLen = aLen + bLen;
			AutoArray<int> *c = getResource();
			c->setLength(cLen);

			int *cData = c->data();

			ll remain = 0;
			for (int i = 0; i < cLen; i++)
			{
				for (int j = max(0, i - bLen + 1), until = min(aLen, i + 1); j < until; j++) {
					int k = i - j;
					remain += aData[j] * bData[k];
				}
				cData[i] = remain % RADIX;
				remain /= RADIX;
			}

			a.build(*c, a.m_sign * b.m_sign);

			releaseResource(c);
		}
		static void pow(const MutableBigInt &x, int n, MutableBigInt &res) {
			res.build(1);

			int bit = 31 - numberOfLeadingZero(n);

			for (; bit >= 0; bit--)
			{
				res *= res;
				if (n & (1 << bit)) {
					res *= x;
				}
			}
		}
		static void pow(const int &x, int n, MutableBigInt &res) {
			res.build(1);

			int bit = 31 - numberOfLeadingZero(n);

			for (; bit >= 0; bit--)
			{
				res *= res;
				if (n & (1 << bit)) {
					res *= x;
				}
			}
		}
		inline int length() const {
			return m_digits.length();
		}
		void toString(string::StringBuilder &appender)
		{
			if (m_sign < 0)
			{
				appender.append('-');
			}
			int basic = RADIX / 10;
			int len = m_digits.length();
			appender.append(m_digits[len - 1]);

			appender.ensureCapacity(appender.length() + len * CHAR_LEN - CHAR_LEN);
			for (int i = len - 2; i >= 0; i--) {
				int radix = basic;
				for (int j = 0; j < CHAR_LEN; j++)
				{
					appender.append(char(m_digits[i] / radix % 10 + '0'));
					radix /= 10;
				}
			}
		}
		MutableBigInt & operator /=(unsigned int d) {
			ll remainder = 0;
			int len = m_digits.length();

			for (int i = len - 1; i >= 0; i--)
			{
				remainder = remainder * RADIX + m_digits[i];
				m_digits[i] = remainder / d;
				remainder %= d;
			}

			shrink();
			return *this;
		}
		MutableBigInt & operator *=(unsigned int d) {
			ll remainder = 0;
			int len = m_digits.length();
			for (int i = 0; i < len; i++)
			{
				remainder += m_digits[i] * (ll)d;
				m_digits[i] = remainder % RADIX;
				remainder /= RADIX;
			}
			while (remainder > 0)
			{
				m_digits.push_back(remainder % RADIX);
				remainder /= RADIX;
			}

			return *this;
		}
	private:
		void shrink() {
			int len = m_digits.length() - 1;
			for (; len > 0 && m_digits[len] == 0; len--);
			len++;
			m_digits.setLength(len);
		}
		AutoArray<int> m_digits;
		int m_sign;
	};
};

using io::IO;
using number::MutableBigInt;
using namespace mathematic;
char buf[1500000];

void solve() {
	int numberCnt = IO.readString(buf, INF);
	MutableBigInt n(buf, numberCnt);

	if (n == 1)
	{
		IO.write(1);
		return;
	}
	
	int guessLength = max(0, (buf[0] >= '4' ? numberCnt : (numberCnt - 1)) - 1);
	int expTime = guessLength * log(10) / log(3);

	MutableBigInt possible;
	MutableBigInt::pow(3, expTime, possible);
	

	int r = INF;
	possible *= 4;
	while (possible < n)
	{
		expTime++;
		possible *= 3;
	}
	r = min(r, expTime * 3 + 4);

	possible /= 2;
	while (possible < n)
	{
		expTime++;
		possible *= 3;
	}
	r = min(r, expTime * 3 + 2);

	possible /= 2;
	while (possible < n)
	{
		expTime++;
		possible *= 3;
	}
	r = min(r, expTime * 3);

	IO.write(r);
	return;
}

int main() {
	fft::FFT_INIT();
	solve();
	IO.flush();
	return 0;
}
#endif