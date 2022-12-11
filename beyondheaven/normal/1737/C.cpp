#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	auto is_white = [&](int x, int y) { return x % 2 == y % 2; };
	int T; std::cin >> T;
	while(T--)
	{
		int n, r[4], c[4];
		std::cin >> n;
		for(int i = 0; i < 3; ++i) std::cin >> r[i] >> c[i];
		
		bool col = (is_white(r[0], c[0]) ^ is_white(r[1], c[1]) ^ is_white(r[2], c[2]));
		
		int vr = 0, vc = 0;
		for(int i = 0; i < 3; ++i) if(is_white(r[i], c[i]) == col) vr = r[i], vc = c[i];
		
		int qr, qc; std::cin >> qr >> qc;
		if((vr == 1 || vr == n) && (vc == 1 || vc == n))
		{
			std::cout << ((qr == vr || qc == vc) ? "YES" : "NO") << "\n";
			continue;
		}
		
		if(is_white(qr, qc) == col) std::cout << (qr % 2 == vr % 2 ? "YES" : "NO") << "\n";
		else std::cout << "YES" << "\n";
	}
	return 0;
}