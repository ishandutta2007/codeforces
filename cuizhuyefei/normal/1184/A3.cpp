#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

const int maxk = 1 << 18 | 1;
int n,m,i, k, p, omega[maxk], romega[maxk], c[maxk], a[maxk], b[maxk];
int power(int a, int x, int p)
{
	int ans = 1;
	for (; x; x >>= 1, a = 1LL * a * a % p)
		if (x & 1) ans = 1LL * ans * a % p;
	return ans;
}
std::vector<int> pr;
void factor()
{
	int x = p - 1;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
		{
			pr.push_back(i);
			while (x % i == 0) x /= i;
		}
	if (x > 1) pr.push_back(x);
}
bool check(int g)
{
	for (int t : pr)
		if (power(g, (p - 1) / t, p) == 1)
			return false;
	return true;
}

int choose2(int x)
{
	return 1LL * x * (x - 1) / 2 % k;
}

namespace FFT
{
	const double PI = acos(-1);
	struct Complex
	{
		double r, i;
		Complex(double a = 0, double b = 0): r(a), i(b) {}
		Complex conj() { return Complex(r, -i); }
	} w[maxk];
	Complex operator+(const Complex &a, const Complex &b) { return Complex(a.r + b.r, a.i + b.i); }
	Complex operator-(const Complex &a, const Complex &b) { return Complex(a.r - b.r, a.i - b.i); }
	Complex operator*(const Complex &a, const Complex &b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }
	Complex operator/(const Complex &a, double b) { return Complex(a.r / b, a.i / b); }

	void init(int n)
	{
		Complex pr(cos(2 * PI / n), sin(2 * PI / n));
		for (int i = 0; i < n / 2; ++i)
			w[n / 2 + i] = (i & 31) ? w[n / 2 + i - 1] * pr : Complex(cos(2 * PI * i / n), sin(2 * PI * i / n));
		for (int i = n / 2 - 1; i >= 1; --i)
			w[i] = w[i << 1];
	}
	void dft(Complex *a, int n)
	{
		for (int i = 0, j = 0; i < n; ++i)
		{
			if (i > j) std::swap(a[i], a[j]);
			for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		}
		for (int d = 1; d < n; d <<= 1)
			for (int i = 0; i < n; i += d << 1)
				for (int j = 0; j < d; ++j)
				{
					Complex tmp = a[i + d + j] * w[d + j];
					a[i + d + j] = a[i + j] - tmp;
					a[i + j] = a[i + j] + tmp;
				}
	}

	void mul(int *A, const int *B, int n)
	{
		static Complex a[maxk], b[maxk], dfta[maxk], dftb[maxk];
		for (int i = 0; i < n; ++i)
		{
			a[i] = Complex(A[i] & 32767, A[i] >> 15);
			b[i] = Complex(B[i] & 32767, B[i] >> 15);
		}
		init(n);
		dft(a, n), dft(b, n);
		for (int i = 0; i < n; ++i)
		{
			int j = (n - i) & (n - 1);
			dfta[i] = (a[i].conj() + a[j]) * Complex(0.5, 0) * b[j];
			dftb[i] = (a[i].conj() - a[j]) * Complex(0, 0.5) * b[j];
		}
		dft(dfta, n), dft(dftb, n);
		for (int i = 0; i < n; ++i)
		{
			int64 ret0 = dfta[i].r / n + 0.5, ret1 = (dfta[i].i + dftb[i].r) / n + 0.5, ret2 = dftb[i].i / n + 0.5;
			A[i] = (ret0 + (ret1 % p << 15) + (ret2 % p << 30)) % p;
		}
	}
}

char c1[maxk],c2[maxk];

inline void ck(int p,int r){
	int x=0,y=0,i=n-1;
	for(;i>=0;--i)x=(1ll*x*r+c1[i])%p,y=(1ll*y*r+c2[i])%p;
	assert(x==y);
}
inline void work(){
	k=p-1;
	int g;
	factor();
	for (g = 2; !check(g); ++g);
	omega[0] = 1;
	omega[1] = power(g, (p - 1) / k, p);
	for (int j = 2; j <= k; ++j)
		omega[j] = 1LL * omega[j - 1] * omega[1] % p;
	memset(a,0,sizeof a);memset(c,0,sizeof c);
	for (int j = 0; j <= k; ++j)
		c[j] = (c1[j]-c2[j]+p*100)%p;
	/*
	for(int t=0;t<k;++t){
		int s=0,j;
		for(j=n-1;j>=0;--j)s=(1ll*s*omega[t]+c[j])%p;
		printf("%d ",s);
		if(s<0){
			++s,--s;
		}
	}
	puts("");
	*/
	romega[0] = 1;
	for (int i = 1; i <= k; ++i)
		romega[i] = omega[k - i];
	for (int i = 0; i <= 2 * k - 2; ++i)
		a[i] = omega[choose2(i)];
	int len = 1;
	while (len < 2 * k) len <<= 1;
	for(int j=0;j<=k;++j)c[j]=1ll*romega[choose2(j)]*c[j]%p;
	std::reverse(c, c + k + 1);
	FFT::mul(a, c, len);
	for (int t = 0; t < k; ++t)
	{
		int ret = 1LL * a[k + t] * romega[choose2(t)] % p;
		
		if(ret==0 && 2<=omega[t] && omega[t]<=p-2){
			//ck(p,omega[t]);
			printf("%d %d\n",p,omega[t]);
			exit(0);
		}
		
		//printf("%d ",ret);
	}
	/*
	puts("");
	puts("");
	if(p>20)exit(0);
	*/
}

inline bool isp(int x){
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}

int main()
{
	scanf("%d%d%s%s",&n,&m,c1,c2);
	m=max(n+2,max(m,5));
	for(p=m;;++p)if(isp(p))work();
	return 0;
}