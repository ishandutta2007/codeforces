#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int N = 2e5+5;
int p[N];

namespace FFT {
	struct base {
		ld re,im;
		base(ld r=0, ld i=0):re(r),im(i){}
		inline base operator*(const base& b) const {
			return base(re*b.re-im*b.im,re*b.im+b.re*im);
		}
		inline base operator-(const base& b) const {
			return base(re-b.re,im-b.im);
		}
		inline base operator+(const base& b) {
			return base(re+b.re,im+b.im);
		}
		inline void operator+=(const base& b) {
			re += b.re, im += b.im;
		}
		inline void operator*=(const base& b) {
			ld r = re;
			re = re*b.re-im*b.im;
			im = r*b.im+b.re*im;
		}
		inline void operator/=(int b) {
			re /= b;
			im /= b;
		}
		inline base operator/(int b) const {
			return base(re/b,im/b);
		}

		inline base conj() const {
			return base(re,-im);
		}
	};

	vector<int> rev;
	vector<base> wlen_pw;
	void fft(base a[], int n, bool invert) {
		static int last_n = 0;
		static const ld two_pi = acosl(0)*4;
		if(n != last_n) {
			if(n > last_n) rev.resize(n), wlen_pw.resize(n);
			last_n = n;
			int log_n = 31-__builtin_clz(n);
			for(int i = 0; i < n; ++i) {
				rev[i] = 0;
				for(int j = 0; j < log_n; ++j)
					if(i & (1<<j))
						rev[i] |= 1<<(log_n-1-j);
			}
		}
		for(int i = 0; i < n; ++i)
			if(i < rev[i])
				swap(a[i], a[rev[i]]);
		for(int len=2; len<=n; len<<=1) {
			ld ang = two_pi/len * (invert?-1:+1);
			int len2 = len>>1;
			base wlen(cos(ang), sin(ang));
			wlen_pw[0] = base(1);
			for(int i = 1; i < len2; ++i)
				wlen_pw[i] = wlen_pw[i-1] * wlen;
			for(int i = 0; i < n; i += len) {
				base t, *pu = a+i, *pv = a+i+len2, 
					*pu_end = a+i+len2, *pw = &wlen_pw[0];
				for(; pu!=pu_end; ++pu, ++pv, ++pw)
					t = *pv * *pw, *pv = *pu - t, *pu += t;
			}
		}
		if(invert)
			for(int i=0; i<n; ++i)
				a[i] /= n;
	}

	vector<ll> multiply (const vector<int> &a, const vector<int> &b) {
		vector<ll> res;
		vector<base> P(max(a.size(),b.size())),Q;
		for(size_t i = 0; i < a.size(); ++i)
			P[i].re = a[i];
		for(size_t i = 0; i < b.size(); ++i)
			P[i].im = b[i];
		size_t n = 2;
		while ((n>>1) < P.size()) n <<= 1;
		P.resize(n), Q.resize(n);
		fft(&P[0], n, false);
		for(size_t i = 0; i != n; ++i) {
			base tmp = P[i?n-i:0].conj();
			Q[i] = (P[i]+tmp)*(P[i]-tmp)*base(0,-0.25);
		}
		fft(&Q[0], n, true);
		res.resize(n);
		for(size_t i = 0; i != n; ++i)
			res[i] = llrint(Q[i].re);
		return res;
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> p(n+1, 0);
	vector<int> d(n+1, 0);
	++d[0];
	ll stretch = 0;
	ll n0 = 0;
	for(int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		p[i] = p[i-1] + (a < x);
		if(p[i] == p[i-1]) {
			++stretch;
		} else {
			n0 += 1LL* stretch * (stretch+1)/2;
			stretch = 0;
		}
		++d[p[i]];
	}
	n0 += 1LL* stretch * (stretch+1)/2;
	vector<int> r = d;
	reverse(r.begin(), r.end());

	vector<ll> V = FFT::multiply(r, d);
	V[n] = n0;
	V.resize(2*n+1, 0);
	for(int i = n; i <= 2*n; ++i) {
		cout << V[i] << " ";
	}
	cout << "\n";
}