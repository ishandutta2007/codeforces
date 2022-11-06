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

class hashMgr
{
	public:
		hashMgr(std::string* s): s(s) {calc_hashes(); calc_pows();};
		int64_t get_hash(size_t beg, size_t len) const
		{
			auto res = hashes[beg + len - 1] - pows[len] * (beg == 0 ? 0 : hashes[beg - 1]);
			res %= MOD;
			if (res < 0)
				res += MOD;
			return res;
		}
		
	private:
		void calc_hashes()
		{
			hashes.resize(s->size());
			for (size_t i = 0; i != s->size(); ++i)
				if (i == 0)
					hashes[i] = (*s)[i] - 'a' + 1;
				else
					hashes[i] = (27 * hashes[i - 1] + ((*s)[i] - 'a' + 1)) % MOD;
		}
		
		void calc_pows()
		{
			pows.resize(s->size());
			for (size_t i = 0; i != s->size(); ++i)
				if (i == 0)
					pows[i] = 1;
				else
					pows[i] = (27 * pows[i - 1]) % MOD;
		}
		
		std::string* s;
		vector<int64_t> hashes;
		vector<int64_t> pows;
		const int64_t MOD = 1000 * 1000 * 1000 + 9;
};

bool areEq(const std::string& str1, const std::string& str2, uint32_t beg1, uint32_t beg2, uint32_t len, const hashMgr& m1, const hashMgr& m2)
{
	if (m1.get_hash(beg1, len) == m2.get_hash(beg2, len))
		return true;
	if (len % 2 == 0)
	{
		if (areEq(str1, str2, beg1, beg2, len / 2, m1, m2) and areEq(str1, str2, beg1 + len / 2, beg2 + len / 2, len / 2, m1, m2))
			return true;
		if (areEq(str1, str2, beg1 + len / 2, beg2, len / 2, m1, m2) and areEq(str1, str2, beg1, beg2 + len / 2, len / 2, m1, m2))
			return true;
	}
	
	return false;
}

int main()
{
	std::string str1, str2;
	std::getline(cin, str1);
	std::getline(cin, str2);
	
	hashMgr m1(&str1);
	hashMgr m2(&str2);
	
	cout << (areEq(str1, str2, 0, 0, str1.size(), m1, m2) ? "YES\n" : "NO\n");
	return 0;
}