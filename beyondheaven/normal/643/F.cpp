#include <bits/stdc++.h>
int main()
{
	uint32_t n, p, q, ans = 0; std::cin >> n >> p >> q;
	p = std::min(p, n - 1);
	
	using Poly = std::vector<uint32_t>;
	auto mul = [&](const Poly &A, const Poly &B)
	{
		Poly C(p + 1);
		for(uint32_t i = 0; i <= p; ++i)
		for(uint32_t j = 0; i + j <= p; ++j)
		C[i + j] += A[i] * B[j];
		return C;
	};
	
	Poly A = {1}, B = {1, 1};
	A.resize(p + 1); B.resize(p + 1);
	for(; n; n >>= 1, B = mul(B, B)) if(n & 1) A = mul(A, B);
	
	for(uint32_t i = 1; i <= q; ++i)
	{
		uint32_t pw = 1, s = 0;
		for(uint32_t j = 0; j <= p; ++j, pw *= i) s += A[j] * pw;
		ans ^= s * i;
	}
	
	std::cout << ans << "\n";
	return 0;
}