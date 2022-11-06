// Copyright (C) 2017 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>
#include <cstdint>
#include <cinttypes>
#include <string.h>
#include <random>
#include <numeric>
#include <tuple>


using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;


template <size_t buf_sz>
struct in_reader {
    in_reader(FILE* f): f(f) {}

    void set_err() {
        err = true;
#ifdef LOCAL
        assert(false);
#endif
    }

    int peekch() {
        if (term)
            return EOF;
        else if (l == r and r == buf_sz) {
            l = 0;
            r = fread(buf, 1, buf_sz, f);
        }

        if (l != r)
            return buf[l];
        else {
            term = true;
            if (ferror(f))
                set_err();
            return EOF;
        }
    }
    
    int getch() {
        int res = peekch();
        if (res != EOF)
            ++l;
        return res;
    }

    void seek_token() {
        while (peekch() != EOF and std::isspace(peekch()))
            getch();
    }
    
    template <typename T>
    T input_int() {
        seek_token();

        if (peekch() == EOF)
            set_err();
        
        char ch = peekch();
        bool positive = true;
        if (ch == '+')
            getch();
        else if (ch == '-')
            getch(), positive = false;
        else if (not ('0' <= ch and ch <= '9')) {
            set_err();
            return 0;
        }

        int num_read = 0;
        T res = 0;
        while ('0' <= peekch() and peekch() <= '9')
            res = 10 * res + getch() - '0', ++num_read;

        if (num_read == 0)
            set_err();
        if (positive == false and res > 0 and not std::numeric_limits<T>::is_signed)
            set_err();
        if (positive == false)
            res = -res;
        return res;
    }
    
    std::string input_string() {
        seek_token();
        
        std::string res;
        while (peekch() != EOF and not std::isspace(peekch()))
            res += getch();
        return res;
    }

    template <typename T>
    T input_float() {
        seek_token();
        size_t tmp_sz = 0;
        
        if (peekch() == '+' or peekch() == '-')
            tmp[tmp_sz++] = getch();
        while ('0' <= peekch() and peekch() <= '9' and tmp_sz != 60)
            tmp[tmp_sz++] = getch();
        if (peekch() == '.' and tmp_sz != 60) {
            tmp[tmp_sz++] = getch();
            while ('0' <= peekch() and peekch() <= '9' and tmp_sz != 60)
                tmp[tmp_sz++] = getch();
        }

        if (tmp_sz == 60 or tmp_sz == 0) {
            set_err();
            return 0;
        }
        tmp[tmp_sz] = 0;
        if (std::is_same<T, float>::value)
            return strtof(tmp, NULL);
        else if (std::is_same<T, double>::value)
            return strtod(tmp, NULL);
        else if (std::is_same<T, long double>::value)
            return strtold(tmp, NULL);
        else {
            set_err();
            return 0;
        }
    }
    
    void input_string_to(char* out, size_t mx) {
        seek_token();
        mx -= 1;
        
        while (peekch() != EOF and not std::isspace(peekch()) and mx != 0)
            *(out++) = getch(), --mx;
        *out = 0;
    }
    
    char tmp[60];
    char buf[buf_sz];
    FILE* f;
    size_t l = buf_sz;
    size_t r = buf_sz;
    bool term = false;
    bool err  = false;
};

template <size_t buf_sz>
struct out_writer {
    out_writer(FILE* f): f(f) {}
    ~out_writer() {flush();}
    
    void set_err() {
        err = true;
#ifdef LOCAL
        assert(false);
#endif
    }

    void flush() {
        if (pos == 0)
            return;
        
        if (fwrite(buf, 1, pos, f) != pos)
            set_err();
        pos = 0;
    }
    
    void putch(char ch) {
        if (pos == buf_sz)
            flush();
        buf[pos++] = ch;
    }

    template <typename T>
    void write_int(T elem) {
        if (elem < 0) {
            putch('-');
            elem = -elem;
        }

        size_t tmp_sz = 0;
        while (elem != 0)
            tmp[tmp_sz++] = '0' + elem % 10, elem /= 10;
        
        if (tmp_sz == 0)
            putch('0');
        else
            while (tmp_sz != 0)
                putch(tmp[--tmp_sz]);
    }
    
    void write_string(const std::string& str) {
        write_string_raw(str.data());
    }

    template <typename T>
    void write_float(T v) {
        if (std::is_same<T, float>::value)
            snprintf(tmp, 60, "%.7f", v);
        else if (std::is_same<T, double>::value)
            snprintf(tmp, 60, "%.7lf", v);
        else if (std::is_same<T, long double>::value)
            snprintf(tmp, 60, "%.7Lf", v);
        else {
            set_err();
        }
        write_string_raw(tmp);
    }
    
    void write_string_raw(const char* out) {
        while (*out != 0)
            putch(*(out++));
    }
    
    char tmp[60];
    char buf[buf_sz];
    FILE* f;
    size_t pos = 0;
    bool err = false;
};

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

in_reader<4096> in(stdin);
out_writer<4096> out(stdout);

template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type input() {
    return in.input_int<T>();
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type input() {
    return in.input_float<T>();
}

#define INI(TYPE) in.input_int<TYPE>()
#define OUTI(EXPR) out.write_int(EXPR)

#define pb push_back
#define eb emplace_back

// const int MAX_MEM = 1.8e8;
// int mpos = 0;
// char mem[MAX_MEM];
// inline void * operator new ( size_t n ) {
//     mpos += n;
//     return (void *)(mem + mpos - n);
// }
// inline void operator delete ( void * ) noexcept { } // must have!

#define int int64_t

struct tree {
    int64_t get(int l, int r) {
        return get_do(0, 0, cnt, l, r);
    }

    void incr(int l, int r, int64_t c) {
        incr_do(0, 0, cnt, l, r, c);
    }

    int64_t get_do(int no, int nl, int nr, int l, int r) {
        push(no, nl, nr);
        if (l <= nl and nr <= r)
            return vals[no];
        if (r <= nl or nr <= l)
            return 0;
        
        int mi = nl + (nr - nl) / 2;
        return get_do(2 * no + 1, nl, mi, l, r) + get_do(2 * no + 2, mi, nr, l, r);
    }

    void push(int no, int nl, int nr) {
        if (mods[no]) {
            vals[no] += (nr - nl) * mods[no];
            
            if (nl != nr - 1) {
                mods[2 * no + 1] += mods[no];
                mods[2 * no + 2] += mods[no];
            }
        }
        mods[no] = 0;
    }
    
    void incr_do(int no, int nl, int nr, int l, int r, int64_t c) {
        push(no, nl, nr);

        if (l <= nl and nr <= r) {
            mods[no] += c;
            return;
        }
        
        if (r <= nl or nr <= l)
            return;

        int mi = nl + (nr - nl) / 2;
        incr_do(2 * no + 1, nl, mi, l, r, c);
        incr_do(2 * no + 2, mi, nr, l, r, c);
        vals[no] += c * (min(nr, r) - max(l, nl));
    }
    
    vector<int64_t> vals;
    vector<int64_t> mods;
    int cnt = 0;
};

int weights[int(6e5)];
vector<int> graph[int(6e5)];

int path_id[int(6e5)];
int sub_id[int(6e5)];
int par[int(6e5)];
int depth[int(6e5)];

vector<int> dlayer[int(6e5)];

vector<tree> paths;
vector<int> tops;

int build(int v) {
    weights[v] = 1;

    for (int u: graph[v]) {
        depth[u] = depth[v] + 1;
        par[u] = v;
        dlayer[depth[u]].push_back(u);
        weights[v] += build(u);
    }

    if (graph[v].empty()) {
        paths.resize(SZ(paths) + 1);
        paths.back().cnt += 1;
        tops.push_back(v);
        
        path_id[v] = SZ(paths) - 1;
        sub_id[v] = 0;
    } else {
        int heavy = -1;
        for (int u: graph[v])
            if (heavy == -1 or weights[u] > weights[heavy])
                heavy = u;

        paths[path_id[heavy]].cnt += 1;
        tops[path_id[heavy]] = v;
        path_id[v] = path_id[heavy];
        sub_id[v] = sub_id[heavy] + 1;
    }
    
    return weights[v];
}

int64_t ans[int(6e5)];

int32_t main() {
    // code here.
    int n = input<int>();
    int root = -1;
    for (int i = 0; i != n; ++i) {
        int p = input<int>() - 1;
        if (p == -1)
            root = i;
        else
            graph[p].push_back(i);
    }

    par[root] = -1;
    dlayer[0].push_back(root);
    build(root);
    for (int i = 0; i != SZ(paths); ++i) {
        paths[i].vals.resize(paths[i].cnt * 4);
        paths[i].mods.resize(paths[i].cnt * 4);
    }
    
    for (int d = 0; not dlayer[d].empty(); ++d) {
        for (int v: dlayer[d]) {
            int x = par[v];
            while (x != -1) {
                paths[path_id[x]].incr(sub_id[x], paths[path_id[x]].cnt, +1);
                x = par[tops[path_id[x]]];
            }
        }

       for (int v: dlayer[d]) {
           ans[v] = 0;
           int x = par[v];
           while (x != -1) {
               ans[v] += paths[path_id[x]].get(sub_id[x], paths[path_id[x]].cnt);
               x = par[tops[path_id[x]]];
           }
       }
    }

    for (int i = 0; i != n; ++i)
        OUTI(ans[i]), out.putch(' ');
    out.putch('\n');
    
    return 0;
}