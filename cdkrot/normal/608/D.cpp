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
#include <cmath>
#include <utility>
#include <stdint.h>
#include <assert.h>
#include <array>
#include <set>
#include <map>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;
using std::set;
using std::map;
using std::array;

using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::abs;

template <typename T>
inline T input() {
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


int main() {
    std::iostream::sync_with_stdio(false);
    
    vector<uint32_t> field(input<uint32_t>());
    std::generate(field.begin(), field.end(), input<uint32_t>);
    
    vector<vector<uint32_t>> dp(field.size() + 1, vector<uint32_t>(field.size() + 1));
    for (uint32_t len = 0; len != field.size() + 1; ++len)
        for (uint32_t beg = 0; beg + len != field.size() + 1; ++beg)
            if (len == 0)
                dp[len][beg] = 0;
            else if (len == 1) /* no other way */
                dp[len][beg] = 1;
            else if (len == 2)
                dp[len][beg] = 1 + (field[beg] != field[beg + 1]);
            else {
                dp[len][beg] = 1 + dp[len - 1][beg + 1];
                for (uint32_t pos = beg + 1; pos != beg + len; ++pos)
                    if (field[pos] == field[beg]) {
                        uint32_t new_val = (pos == beg + 1 ? 1 : dp[pos - beg - 1][beg + 1]);
                        new_val += dp[len - (pos - beg + 1)][pos + 1];
                        dp[len][beg] = min(dp[len][beg], new_val);
                    }
            }
    
    cout << dp[field.size()][0] << '\n';
    
    return 0;
}