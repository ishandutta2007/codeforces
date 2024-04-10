// Copyright (C) 2015 Sayutin Dmitry.
//
// This Program is free  software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
//
// You should have received a copy of the GNU General Public License
// If not, see <http://www.gnu.org/licenses/>.


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
using std::abs;

template <typename T>
inline T input()
{
	T ans;
	cin >> ans;
	return ans;
}

#ifdef __CDKROT_LOCAL
#define debug_print_single(x) {debug_print_seq(x); debug_print_seq_end();}
#define debug_print_seq(x)    {cerr << #x << " = " << x << ", ";}
#define debug_print_seq_end() {endl(cerr);}
#define debug_print_text(s)   {cerr << s << endl;}
#else
#define debug_print_single(x) {}
#define debug_print_seq(x)    {}
#define debug_print_seq_end() {}
#define debug_print_text(s)   {}
#endif


int main()
{
	uint32_t n = input<uint32_t>();
	uint32_t k = input<uint32_t>();
	
	vector<int32_t> arr(n);
	for (uint32_t i = 0; i != n; ++i)
		arr[i] = input<int32_t>();
	
	std::sort(arr.begin(), arr.end());
	
	vector<int32_t> diffs(n - 1);
	for (uint32_t i = 0; i + 1 != n; ++i)
		diffs[i] = arr[i + 1] - arr[i];
	
	
	if (n % k == 0)
	{
		int64_t ans = 0;
		for (uint32_t i = 0; i + 1 != n; ++i)
			if ((i + 1) % (n / k) != 0)
				ans += diffs[i];
		cout << ans << endl;
	}
	else
	{
		int64_t sum = 0;
		for (uint32_t i = 0; i + 1 != n; ++i)
			sum += diffs[i];
		
		diffs.push_back(0); // just for usability in DP.
		
		uint32_t n1 = n % k;
		uint32_t a1 = n / k + 1;
		uint32_t n2 = k - n % k;
		uint32_t a2 = n / k;
		
		// [0..n1][0..n2]
		vector<vector<int64_t>> dp(n1 + 1, vector<int64_t>(n2 + 1));
		
		for (uint32_t i = 0; i != n1 + 1; ++i)
			for (uint32_t j = 0; j != n2 + 1; ++j)
				if (i == 0 and j == 0)
					dp[i][j] = 0;
				else
				{
					dp[i][j] = INT64_MIN;
					if (i != 0)
						dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					if (j != 0)
						dp[i][j] = max(dp[i][j], dp[i][j - 1]);
					
					dp[i][j] += diffs[i * a1 + j * a2 - 1];
				}
		
		cout << sum - dp[n1][n2] << endl;
	}
	
	return 0;
}