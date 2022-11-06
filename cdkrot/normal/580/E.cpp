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

template <uint64_t p, uint64_t mod>
class HashSegtree
{
	public:
		HashSegtree(const std::string& str)
		{
			while (n_rounded < str.size())
				n_rounded = 2 * n_rounded;
			
			data.resize(2 * n_rounded - 1);
			pows.resize(2 * n_rounded - 1);
			overlay.resize(2 * n_rounded - 1);
			std::fill(overlay.begin(), overlay.end(), '\0');
			
			for (uint32_t i = 0; i != pows.size(); ++i)
				pows[i] = (i == 0 ? 1 : (p * pows[i - 1]) % mod);
			
			init(0, 0, n_rounded, str);
		}
		
		int64_t getHash(uint32_t l, uint32_t r) // [l, r).
		{
			return getHashDo(0, 0, n_rounded, l, r).first;
		}
		
		void setChr(uint32_t l, uint32_t r, char c) // [l, r).
		{
			setChrDo(0, 0, n_rounded, l, r, c);
		}
	
	private:
		void init(uint32_t p_node, uint32_t l, uint32_t r, const std::string& str)
		{
			if (l == r - 1)
				data[p_node] = (l < str.size() ? str[l] - '0' + 1 : 0);
			else
			{
				uint32_t len = (r - l) / 2;
				
				init(2 * p_node + 1, l, l + len, str);
				init(2 * p_node + 2, l + len, l + len + len, str);
				
				data[p_node] = ((data[2 * p_node + 1] * pows[len]) % mod + data[2 * p_node + 2]) % mod;
			}
		}
		
		pair<int64_t, uint32_t> getHashDo(uint32_t p_node, uint32_t node_l, uint32_t node_r, uint32_t l, uint32_t r)
		{
			if (node_r <= l or r <= node_l)
				return make_pair(0, 0);
			
			push(p_node, node_r - node_l);
			
			if (l <= node_l and node_r <= r)
				return make_pair(data[p_node], node_r - node_l);
			
			uint32_t mid = node_l + (node_r - node_l) / 2;
			auto res_left  = getHashDo(2 * p_node + 1, node_l, mid, l, r);
			auto res_right = getHashDo(2 * p_node + 2, mid, node_r, l, r);
			
			int64_t hash = ((res_left.first * pows[res_right.second]) % mod + res_right.first) % mod;
			
			return make_pair(hash, res_left.second + res_right.second);
		}
		
		void setChrDo(uint32_t p_node, uint32_t node_l, uint32_t node_r, uint32_t l, uint32_t r, char c)
		{
			if (node_r <= l or r <= node_l)
				return;
			
			if (l <= node_l and node_r <= r)
			{
				overlay[p_node] = c;
				return;
			}
			
			push(p_node, node_r - node_l);
			
			uint32_t mid = node_l + (node_r - node_l) / 2;
			setChrDo(2 * p_node + 1, node_l, mid, l, r, c);
			setChrDo(2 * p_node + 2, mid, node_r, l, r, c);
			uint32_t len = (node_r - node_l);
			data[p_node] = ((get(2 * p_node + 1, len / 2) * pows[len / 2]) % mod + get(2 * p_node + 2, len / 2)) % mod;
		}
		
		void push(uint32_t p_node, uint32_t node_sz)
		{
			if (overlay[p_node] != '\0')
			{
				if (2 * p_node + 2 < overlay.size())
					overlay[2 * p_node + 2] = overlay[2 * p_node + 1] = overlay[p_node];
				data[p_node] = get(p_node, node_sz);
				overlay[p_node] = '\0';
			}
		}
		
		int64_t get(uint32_t p_node, uint32_t len)
		{
			if (overlay[p_node] == 0)
				return data[p_node];
			else
			{
				int64_t hash = overlay[p_node] - '0' + 1;
				uint32_t calced_len = 1;
				while (calced_len < len)
				{
					hash = (hash * (pows[calced_len] + 1)) % mod;
					calced_len *= 2;
				}
				return hash;
			}
		}
		
		uint32_t n_rounded = 1;
		vector<uint64_t> data;
		vector<char>     overlay;
		vector<uint64_t> pows;
};

int main()
{
	input<uint32_t>();
	uint32_t Q = input<uint32_t>() + input<uint32_t>();
	
	string str = input<string>();
	HashSegtree<31, 1000 * 1000 * 1000 + 9> hash_tree(str);
	
	for (uint32_t i = 0; i != Q; ++i)
	{
		char type = input<char>();
		uint32_t l = input<uint32_t>() - 1;
		uint32_t r = input<uint32_t>() - 1;
		
		if (type == '1')
			hash_tree.setChr(l, r + 1, input<char>());
		else
		{
			vector<string> ans = {"NO", "YES"};
			uint32_t d = input<uint32_t>();
			auto h1 = hash_tree.getHash(l + d, r + 1);
			auto h2 = hash_tree.getHash(l, r + 1 - d);
			cout << ans[h1 == h2] << endl;
		}
	}
	
	return 0;
}