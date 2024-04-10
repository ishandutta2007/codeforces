#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n, sum = 0; std::cin >> n;
		for(int i = 1, x; i <= n; ++i) std::cin >> x, sum += x - 1;
		if(sum % 2 == 0) std::cout << "maomao90" << "\n";
		else std::cout << "errorgorn" << "\n";
	}
	return 0;
}