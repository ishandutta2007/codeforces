#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const double eps = 1e-9;
using matrix = std::array<std::array<double, 3>, 3>;

matrix operator * (const matrix &a, const matrix &b)
{
	matrix c;
	for(int i = 0; i < 3; ++i)
	for(int j = 0; j < 3; ++j)
	c[i][j] = std::max({a[i][0] + b[0][j], a[i][1] + b[1][j], a[i][2] + b[2][j]});
	return c;
}

int n, q, X, Y;

#define Mid ((L + R) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

matrix t[MaxN * 4];
void update(int p, const matrix &v, int k = 1, int L = 1, int R = n)
{
	if(L == R) return t[k] = v, void();
	if(p <= Mid) update(p, v, ls, L, Mid);
	else update(p, v, rs, Mid + 1, R);
	t[k] = t[rs] * t[ls];
}

matrix query(int l, int r, int k = 1, int L = 1, int R = n)
{
	if(l <= L && R <= r) return t[k];
	if(l <= Mid && Mid < r) return query(l, r, rs, Mid + 1, R) * query(l, r, ls, L, Mid);
	return (l <= Mid ? query(l, r, ls, L, Mid) : query(l, r, rs, Mid + 1, R));
}

int main()
{
	std::cin >> n >> q >> X >> Y;
	if(X > Y) std::swap(X, Y);
	
	double val[3] = {0, 1. / (X + Y), 1. / Y};
	auto construct = [&](int b)
	{
		matrix t;
		for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
		if(X * val[i] + Y * val[j] <= 1 + eps &&
			Y * val[i] + X * val[j] <= 1 + eps) t[i][j] = val[j] * b;
		else t[i][j] = -1e18;
		return t;
	};
	
	for(int i = 1, b; i <= n; ++i) std::cin >> b, update(i, construct(b));
	
	for(int i = 1, opt, k, v, l, r; i <= q; ++i)
	{
		std::cin >> opt;
		if(opt == 1) std::cin >> k >> v, update(k, construct(v));
		else
		{
			std::cin >> l >> r;
			matrix t = query(l, r);
			std::cout << std::fixed << std::setprecision(10) <<
				std::max({t[0][0], t[0][1], t[0][2]}) << "\n";
		}
	} 
	return 0;
}