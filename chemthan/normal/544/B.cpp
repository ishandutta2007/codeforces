#include <iostream>

int n, k;

void main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::cin>>n;
	std::cin>>k;
	int max = (n * n + 1) / 2;
	if (k <= max)
	{
		std::cout<<"YES\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((i - j) % 2 == 0 && k > 0)
				{
					std::cout<<"L";
					k--;
				}
				else
					std::cout<<"S";
			}
			if (i < n - 1)
				std::cout<<"\n";
		}
	}
	else
		std::cout<<"NO";
}