// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

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

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define pb push_back
#define eb emplace_back

#ifndef LOCAL
int do_request(vector<int64_t>& a) {
    cout << SZ(a);
    for (int64_t elem: a)
        cout << " " << elem;
    cout << std::endl;
    
    int res;
    cin >> res;
    if (res < 0)
        exit(0);
    return res;
}

#else
int64_t val;

int do_request(vector<int64_t>& a) {
    assert(SZ(a) <= val and SZ(a) <= 10 * 1000);

    for (auto elem: a)
        if (elem == val)
            exit(0);

    int i = 0;
    while (i != SZ(a) and a[i] < val)
        ++i;

    return i;
}

#endif

int request(vector<int64_t> val) {
    return do_request(val);
}

int request(int64_t val) {
    vector<int64_t> m = {val};
    return request(m);
}


struct tree {
    vector<int64_t> separators;
    vector<tree*> sub;
    int64_t L;
    int64_t R;
    bool lazy;
};

int64_t f(int left) {
    if (left == 0)
        return 0;
    return (10 * 1000) + (10 * 1000 + 1) * f(left - 1);
}

int64_t build_lazy(int left, int64_t L);

tree* build(int left, int64_t L) {
    if (left == 0) {
        tree* null = new tree();
        null->lazy = false;
        null->L = L;
        null->R = L - 1;

        return null;
    }
    
    tree* res = new tree();
    int64_t ask_cnt = min(L, int64_t(10 * 1000));

    res->separators.resize(ask_cnt);
    res->sub.resize(ask_cnt + 1);
    res->L = L;
    res->R = -1;
    res->lazy = false;
    
    if (ask_cnt < int64_t(10 * 1000)) {
        int64_t cur_val = L;
        res->separators.resize(ask_cnt);
        
        for (int i = 0; i != ask_cnt; ++i) {
            res->sub[i] = build(left - 1, cur_val);
            res->separators[i] = res->sub[i]->R + 1;
            cur_val = res->sub[i]->R + 2;
        }

        res->sub[ask_cnt] = build(left - 1, cur_val);
        res->R = res->sub[ask_cnt]->R;
        assert(res->R != -1);
        return res;
    } else {
        res->lazy = 1;

        res->separators.resize(ask_cnt);
        int64_t ch = f(left - 1);
        int64_t cur_val = L;
        for (int i = 0; i != ask_cnt; ++i) {
            res->sub[i] = NULL;
            cur_val += ch;
            res->separators[i] = cur_val;
            cur_val += 1;
        }

        cur_val += ch - 1;
        res->R = cur_val;
        assert(res->R != -1);
        return res;
    }
}

int64_t build_lazy(int left, int64_t L) {
    if (left == 0) {
        return L - 1;
    }
    
    int64_t ask_cnt = min(L, int64_t(10 * 1000));

    if (ask_cnt < int64_t(10 * 1000)) {
        int64_t cur_val = L;
        
        for (int i = 0; i != ask_cnt; ++i)
            cur_val = build_lazy(left - 1, cur_val) + 2;

        return build_lazy(left - 1, cur_val);
    } else {
        int64_t ch = f(left - 1);
        return L + ask_cnt * (ch + 1) + (ch - 1);
    }
}

void fuck_and_run(int left, int64_t L) {
    if (left == 0) {
        assert(false);
    }
    
    int64_t ask_cnt = min(L, int64_t(10 * 1000));

    vector<int64_t> separators(ask_cnt);
    
    if (ask_cnt < int64_t(10 * 1000)) {
        int64_t cur_val = L;
        
        for (int i = 0; i != ask_cnt; ++i) {
            cur_val = build_lazy(left - 1, cur_val);
            separators[i] = cur_val + 1;
            cur_val = cur_val + 2;
        }

        int r = request(separators);
        if (r == 0)
            return fuck_and_run(left - 1, L);
        else
            return fuck_and_run(left - 1, separators[r - 1] + 1);
    } else {
        int64_t ch = f(left - 1);
        int64_t cur_val = L;
        for (int i = 0; i != ask_cnt; ++i) {
            cur_val += ch;
            separators[i] = cur_val;
            cur_val += 1;
        }

        cur_val += ch - 1;

        int r = request(separators);
        return fuck_and_run(left - 1, L + (ch + 1) * int64_t(r));
    }
}

int main(int argc, char** argv) {
#ifdef LOCAL
    val = atoll(argv[1]);
#endif
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    cerr << build_lazy(5, 1) << std::endl;
    fuck_and_run(5, 1);
    
    return 0;
}