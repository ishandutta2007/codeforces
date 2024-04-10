#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
std::string str; 
inline bool chk(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("938A.in", "r", stdin); 
#endif
	std::ios::sync_with_stdio(false); 
	std::cin.tie(0); 
	std::cout.tie(0);
	int n; 
	std::cin >> n >> str; 
	for (int t = 0; t < 100; t++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (chk(str[i]) && chk(str[i + 1]))
			{
				str = str.substr(0, i + 1) + str.substr(i + 2); 
				n--; 
				break; 
			}
		}
	}
	std::cout << str << std::endl;
	return 0; 
}