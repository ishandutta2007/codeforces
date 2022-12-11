#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::string A, B; std::cin >> A >> B;
		
		bool flag = true;
		for(int i = 1; i < m; ++i) if(A[i + (n - m)] != B[i]) flag = false;
		if(!flag) { std::cout << "NO" << "\n"; continue; }
		
		flag = false;
		for(int i = 0; i <= n - m; ++i) flag |= (A[i] == B[0]);
		std::cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}