// Dmitry _kun_ Sayutin (2019)

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
using std::swap;

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

struct rmq_t {
    vector<int> tmax;

    void recalc(int v, int nl, int nr) {
        tmax[v] = max(tmax[2 * v + 1],
                      tmax[2 * v + 2]);
    }

    void build(int v, int nl, int nr, vector<int>& arr) {
        if (nl == nr - 1)
            tmax[v] = arr[nl];
        else {
            int mi = nl + (nr - nl) / 2;
            build(2 * v + 1, nl, mi, arr);
            build(2 * v + 2, mi, nr, arr);

            recalc(v, nl, nr);
        }
    }
    
    int get_max(int v, int nl, int nr, int l, int r) {
        if (r <= nl or nr <= l)
            return TYPEMIN(int);
        
        if (l <= nl and nr <= r) {
            return tmax[v];
        }

        int mi = nl + (nr - nl) / 2;
        return max(get_max(2 * v + 1, nl, mi, l, r),
                   get_max(2 * v + 2, mi, nr, l, r));
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, w;
    cin >> n >> w;

    vector<int64_t> ans(w + 1);
    vector<int64_t> direct(w);
    
    for (int it = 0; it != n; ++it) {
        int l = input<int>();
        vector<int> arr(l);
        input_seq(ALL(arr));

        rmq_t rmq;
        rmq.tmax.resize(4 * l);
        rmq.build(0, 0, l, arr);
        
        if (2 * l >= w) {
            for (int i = 0; i != w; ++i) {
                int right = i;
                int left = l - w + i;
                
                int ans = rmq.get_max(0, 0, l, left, right + 1);

                if (left < 0 or right >= l)
                    ans = max(ans, 0);

                direct[i] += ans;
            }
        } else {
            int mx = *std::max_element(ALL(arr));
            mx = max(mx, 0);
            
            ans[l] += mx;
            ans[w - l] -= mx;

            for (int i = 0; i != l; ++i) {
                int right = i;
                int left = l - w + i;
                
                int ans = rmq.get_max(0, 0, l, left, right + 1);

                if (left < 0 or right >= l)
                    ans = max(ans, 0);

                direct[i] += ans;
            }

            for (int i = w - l; i != w; ++i) {
                int right = i;
                int left = l - w + i;
                
                int ans = rmq.get_max(0, 0, l, left, right + 1);

                if (left < 0 or right >= l)
                    ans = max(ans, 0);

                direct[i] += ans;
            }
        }
    }
    
    for (int i = 0; i != w; ++i) {
        if (i)
            ans[i] += ans[i - 1];
        cout << direct[i] + ans[i] << " ";
    }
    cout << "\n";

    return 0;
}