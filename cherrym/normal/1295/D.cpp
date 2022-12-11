#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 1e5 + 5;

ll a, m;

void work()
{
	read(a); read(m);
	ll g = std::__gcd(a, m), ans = 1; m /= g;
	int S = sqrt(m);
	for (int i = 2; i <= S; i++)
	{
		if (m % i) continue;
		ll tmp = 1;
		while (m % i == 0) m /= i, tmp *= i;
		ans *= tmp / i * (i - 1);
	}
	if (m > 1) ans *= m - 1;
	printf("%lld\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}