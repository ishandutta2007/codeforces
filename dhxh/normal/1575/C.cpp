#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;

namespace fft
{
	struct num
	{
		double x,y;
		num() {x=y=0;}
		num(double x,double y):x(x),y(y){}
	};
	inline num operator+(num a,num b) {return num(a.x+b.x,a.y+b.y);}
	inline num operator-(num a,num b) {return num(a.x-b.x,a.y-b.y);}
	inline num operator*(num a,num b) {return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	inline num conj(num a) {return num(a.x,-a.y);}

	int base=1;
	vector<num> roots={{0,0},{1,0}};
	vector<int> rev={0,1};
	const double PI=acosl(-1.0);

	void ensure_base(int nbase)
	{
		if(nbase<=base) return;
		rev.resize(1<<nbase);
		for(int i=0;i<(1<<nbase);i++)
			rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
		roots.resize(1<<nbase);
		while(base<nbase)
		{
			double angle=2*PI/(1<<(base+1));
			for(int i=1<<(base-1);i<(1<<base);i++)
			{
				roots[i<<1]=roots[i];
				double angle_i=angle*(2*i+1-(1<<base));
				roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
			}
			base++;
		}
	}

	void fft(vector<num> &a,int n=-1)
	{
		if(n==-1) n=a.size();
		assert((n&(n-1))==0);
		int zeros=__builtin_ctz(n);
		ensure_base(zeros);
		int shift=base-zeros;
		for(int i=0;i<n;i++)
			if(i<(rev[i]>>shift))
				swap(a[i],a[rev[i]>>shift]);
		for(int k=1;k<n;k<<=1)
		{
			for(int i=0;i<n;i+=2*k)
			{
				for(int j=0;j<k;j++)
				{
					num z=a[i+j+k]*roots[j+k];
					a[i+j+k]=a[i+j]-z;
					a[i+j]=a[i+j]+z;
				}
			}
		}
	}

	vector<num> fa,fb;

	vector<long long> multiply_mod(vector<long long> &a,vector<long long> &b,int m,int eq=0)
	{
		int need=a.size()+b.size()-1;
		int nbase=0;
		while((1<<nbase)<need) nbase++;
		ensure_base(nbase);
		int sz=1<<nbase;
		if(sz>(int)fa.size()) fa.resize(sz);
		for(int i=0;i<(int)a.size();i++)
		{
			int x=(a[i]%m+m)%m;
			fa[i]=num(x&((1<<15)-1),x>>15);
		}
		fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
		fft(fa,sz);
		if(sz>(int)fb.size()) fb.resize(sz);
		if(eq) copy(fa.begin(),fa.begin()+sz,fb.begin());
		else
		{
			for(int i=0;i<(int)b.size();i++)
			{
				int x=(b[i]%m+m)%m;
				fb[i]=num(x&((1<<15)-1),x>>15);
			}
			fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
			fft(fb,sz);
		}
		double ratio=0.25/sz;
		num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
		for(int i=0;i<=(sz>>1);i++)
		{
			int j=(sz-i)&(sz-1);
			num a1=(fa[i]+conj(fa[j]));
			num a2=(fa[i]-conj(fa[j]))*r2;
			num b1=(fb[i]+conj(fb[j]))*r3;
			num b2=(fb[i]-conj(fb[j]))*r4;
			if(i!=j)
			{
				num c1=(fa[j]+conj(fa[i]));
				num c2=(fa[j]-conj(fa[i]))*r2;
				num d1=(fb[j]+conj(fb[i]))*r3;
				num d2=(fb[j]-conj(fb[i]))*r4;
				fa[i]=c1*d1+c2*d2*r5;
				fb[i]=c1*d2+c2*d1;
			}
			fa[j]=a1*b1+a2*b2*r5;
			fb[j]=a1*b2+a2*b1;
		}
		fft(fa,sz);fft(fb,sz);
		vector<long long> res(need);
		for(int i=0;i<need;i++)
		{
			long long aa=fa[i].x+0.5;
			long long bb=fb[i].x+0.5;
			long long cc=fa[i].y+0.5;
			res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
		}
		return res;
	}
};

int n, m, k;
vector <long long> A, B, C;

long long ans = 0;

int a[maxn];
int sum = 0;

int pre[maxn];
int suf[maxn];

void solve(){
	if(m < 2) return;
	int i, j;

	C.resize(k);
	C[0] = 1;
	int p = 0;
	for(i=1;i<=m-2;i++){
		p = (p + sum) % k;
		C[p]++;
	}
	A = fft::multiply_mod(A, C, mod);
	for(i=k;i<A.size();i++){
		A[i % k] = (A[i % k] + A[i]) % mod;
	}
	A.resize(k);
	A = fft::multiply_mod(A, B, mod);
	for(i=k;i<A.size();i++){
		A[i % k] = (A[i % k] + A[i]) % mod;
	}
	A.resize(k);
	ans = (ans + 1ll * A[0] * m) % mod;
	if(sum * m % k == 0){
		ans = (ans - m + 1 + mod) % mod;
	}
}

int main(){
	int i, j;

	scanf("%d%d%d", &n, &m, &k);

	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		sum = (sum + a[i]) % k;
	}

	int s = 0;
	pre[0] = 1;
	for(i=1;i<=n;i++){
		s = (s + a[i]) % k;
		ans = (ans + pre[s]) % mod;
		pre[s]++;
	}
	ans = ans * m % mod;

	s = 0;
	suf[0] = 1;
	for(i=n;i>0;i--){
		s = (s + a[i]) % k;
		suf[s]++;
	}

	A.resize(k), B.resize(k);
	for(i=0;i<k;i++){
		A[i] = pre[i], B[i] = suf[i];
	}
	A[0]--, B[0]--;

	suf[s]--;
	suf[0]--;

	int sa = 0;
	for(i=1;i<=n-2;i++){
		s = (s - a[i] % k + k) % k;
		suf[s]--;
		sa = (sa + a[i]) % k;
		ans = (ans + 1ll * suf[(k - (sa + 1ll * (m - 1) * sum) % k) % k] * m) % mod;
	}

	solve();

	printf("%lld\n", ans);

	return 0;
}