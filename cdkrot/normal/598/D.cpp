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

vector<vector<uint32_t>> used;
vector<string> field;
vector<uint32_t> ans;

void dfs(uint32_t i, uint32_t j)
{
	auto process = [](uint32_t k, uint32_t m)
	{
		if (field[k][m] == '*')
			++ans.back();
		else if (used[k][m] == UINT32_MAX)
			used[k][m] = ans.size() - 1, dfs(k, m);
	};
	
	process(i - 1, j);
	process(i + 1, j);
	process(i, j - 1);
	process(i, j + 1);
}

int main()
{
	std::iostream::sync_with_stdio(false);
	
	uint32_t n, m, k;
	cin >> n >> m >> k;
	
	while (cin.peek() == '\n')
		cin.get();
	
	used.resize(n, vector<uint32_t>(m, UINT32_MAX));
	field.resize(n);
	
	for (uint32_t i = 0; i != n; ++i)
		std::getline(cin, field[i]);
	
	for (uint32_t i = 1; i != n - 1; ++i)
		for (uint32_t j = 1; j != m - 1; ++j)
		{
			if (used[i][j] == UINT32_MAX and field[i][j] == '.')
			{
				used[i][j] = ans.size();
				ans.push_back(0);
				dfs(i, j);
			}
		}
	
	for (; k != 0; --k)
	{
		uint32_t x, y;
		cin >> x >> y;
		cout << ans[used[x - 1][y - 1]] << endl;
	}
	
	return 0;
}