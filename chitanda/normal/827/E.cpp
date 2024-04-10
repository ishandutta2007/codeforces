#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const double pi = acos(-1.0);
//also typedef complex<double> Comp;
struct Comp{
  double x, y;
  Comp(): x(0), y(0) {}
  Comp(double _x, double _y): x(_x), y(_y) {}
  Comp operator + (const Comp &rhs) const {
    return Comp(x + rhs.x, y + rhs.y);
  }
  Comp operator - (const Comp &rhs) const {
    return Comp(x - rhs.x, y - rhs.y);
  }
  Comp operator * (const Comp &rhs) const {
    return Comp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
  }
  Comp &operator += (const Comp &rhs) {
    x += rhs.x; y += rhs.y;
    return *this;
  }
  Comp &operator -= (const Comp &rhs) {
    x -= rhs.x; y -= rhs.y;
    return *this;
  }
  Comp conj() const {
    return Comp(x, -y);
  }
};
const int MAXN = 1048576;
Comp X[MAXN], Y[MAXN], Z[MAXN];
int bitrev[MAXN];
int a[MAXN], b[MAXN], aa[MAXN], aaa[MAXN], bb[MAXN], bbb[MAXN], c1[MAXN], c2[MAXN], c3[MAXN];
char s[MAXN];
int T, n;
bool ban[MAXN];

void FFT(Comp A[], int n, int o){
	for(int i = 0; i < n; i++) if(bitrev[i] < i) swap(A[bitrev[i]], A[i]);
	for(int s = 0; 1 << s <= n; s++){
		int m = 1 << s;
		double ang = 2 * pi / m * o;
		Comp od = Comp(cos(ang), sin(ang));
		for(int k = 0; k < n; k += m){
			Comp w = Comp(1.0, 0);
			for(int j = 0; j < m / 2; j++){
				Comp t = w * A[k + j + m / 2];
				A[k + j + m / 2] = A[k + j] - t;
				A[k + j] = A[k + j] + t;
				w = w * od;
			}
		}
	}
}

void conv(int x[], int n, int y[], int m, int z[]){
  int l = 0;
  while ((1 << l) < n + m - 1) ++l;
  int s = 1 << l;
  for (int i = 0; i < s; ++i)
    bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (l - 1));
  for (int i = 0; i < s; ++i){
		X[i] = Comp(i < n ? x[i] : 0, 0);
		Y[i] = Comp(i < m ? y[i] : 0, 0);
  }
  FFT(X, s, 1); FFT(Y, s, 1);
	for(int i = 0; i < s; ++i) Z[i] = X[i] * Y[i];
  FFT(Z, s, -1);
  for (int i = 0; i < s; ++i)
		z[i] = int(Z[i].x / s + 0.5);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", s);
		for(int i = 0; i < n; ++i){
			a[i] = s[i] == 'V' ? 2 : s[i] == 'K' ? 3 : 0;
			aa[i] = s[i] == 'V' ? 4 : s[i] == 'K' ? 9 : 0;
			aaa[i] = s[i] == 'V' ? 8 : s[i] == 'K' ? 27 : 0;
			b[i] = s[n - 1 - i] == 'V' ? 2 : s[n - 1 - i] == 'K' ? 3 : 0;
			bb[i] = s[n - 1 - i] == 'V' ? 4 : s[n - 1 - i] == 'K' ? 9 : 0;
			bbb[i] = s[n - 1 - i] == 'V' ? 8 : s[n - 1 - i] == 'K' ? 27 : 0;
		}
		conv(aaa, n, b, n, c1);
		conv(a, n, bbb, n, c2);
		conv(aa, n, bb, n, c3);
		vector<int> ans;
		for(int i = 0; i < n; ++i){
			int x = c1[i] + c2[i] - 2 * c3[i];
			ban[n - i - 1] = x > 0;
		}
		for(int i = 1; i < n; ++i){
			for(int j = i; j < n; j += i)
				ban[i] |= ban[j];
			if(!ban[i]) ans.pb(i);
		}
		ans.pb(n);

		printf("%d\n", ans.size());
		for(auto v : ans)
			printf("%d ", v);
		printf("\n");
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}