#include <iostream>
#include <algorithm>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
	size_t n;
	cin >> n;
	
	vector<int> nums(n);
	for (size_t i = 0; i < n; i++)
		cin >> nums[i];
	
	std::sort(nums.begin(), nums.end());
	
	long long ans = 0;
	
	for (size_t i = 0; i < n - 1; i++)
	{
		long long mult = i + 2;
		ans += mult * nums[i];
	}
	
	if (n >= 1)
		ans += n * 1LL * nums[n - 1];
	
	cout << ans << endl;
	
	return 0;
}