#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1<<21;
const int MAX = MAXN;
const double M_PI = acos(-1);

typedef complex<double> Point;

int n, m;
vector<Point> a(MAXN);
bool mark[MAXN];

void fft(vector<Point> &a, bool inv = 0){
	for (int i = 0; i < MAX; i++)
	{
		int j = 0;
		for (int k = 0; k <= 20; k++)
			if ((1 << k) & i)
				j |= 1 << (20 - k);
		if (i < j)
			swap(a[i], a[j]);
	}
	for (int len = 2; len <= MAX; len *= 2)
	{
		complex<double> wn(cos(2.0 * M_PI / len), sin(2.0 * M_PI / len));
		if (inv)
			wn.imag(wn.imag() * -1.0);
		for (int i = 0; i < MAX; i += len)
		{
			complex<double> w(1.0, 0.0);
			for (int j = 0; j < len / 2; j++)
			{
				complex<double> t1 = a[i + j] + w * a[i + j + len / 2];
				complex<double> t2 = a[i + j] - w * a[i + j + len / 2];
				a[i + j] = t1;
				a[i + j + len / 2] = t2;
				w *= wn;
			}
		}
	}
	if (inv)
		for (int i = 0; i < MAX; i++)
			a[i] /= MAX;
}

int ans[MAXN], sz;
int main(){
	scanf("%d %d", &n, &m);
	while (n--){
		int x; scanf("%d", &x);
		mark[x]=1;
		a[x].real(1);
	}

	fft(a);
	for (int i = 0; i < MAXN; i++)	a[i] *= a[i];
	fft(a, 1);

	for (int i = 1; i <= m; i++)
		if (!mark[i] && a[i].real() > 0.5){
			printf("NO\n");
			return 0;
		}

	printf("YES\n");
	for (int i = 1; i <= m; i++)
		if (mark[i] && a[i].real() < 0.5)
			ans[sz++] = i;

	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}