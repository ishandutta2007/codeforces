#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdint.h>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::max;


template <typename T>
inline T input()
{
	T ans;
	cin >> ans;
	return ans;
}


int main()
{
	uint32_t n = input<uint32_t>();
	vector<vector<uint32_t>> data(n, vector<uint32_t>(n, 1)); // too easy, even for hand array expansion.
	for (uint32_t i = 1; i < n; i++)
		for (uint32_t j = 1; j < n; j++)
			data[i][j] = data[i - 1][j] + data[i][j - 1];
	cout << data[n - 1][n - 1] << endl;
	return 0;
}