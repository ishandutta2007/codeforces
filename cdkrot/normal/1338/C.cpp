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
using std::queue;

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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here

    std::function<tuple<int64_t, int64_t, int64_t>(int64_t)> trip_with = [&](int64_t x) {
        if (x == 0)
            return make_tuple<int64_t, int64_t, int64_t>(0, 0, 0);
        if (x <= 3)
            return make_tuple<int64_t, int64_t, int64_t>(1, 2, 3);

        int64_t A = 4;
        while (not (A <= x and x < 4 * A))
            A *= 4;

        auto B = 2 * A;
        auto C = 3 * A;

        tuple<int64_t, int64_t, int64_t> rs;
        auto rot = [&]() {
            swap(get<2>(rs), get<1>(rs));
            swap(get<0>(rs), get<2>(rs));
        };

        if (x < B) {
            rs = trip_with(x - A);
            while (get<0>(rs) != x - A)
                rot();
        } else if (x < C) {
            rs = trip_with(x - B);
            while (get<1>(rs) != x - B)
                rot();
        } else {
            rs = trip_with(x - C);// rot(), rot();
            while (get<2>(rs) != x - C)
                rot();
        }
                
        auto res = rs;
        get<0>(res) += A;
        get<1>(res) += B;
        get<2>(res) += C;
        
        return res;        
    };
    
    std::function<tuple<int64_t, int64_t, int64_t>(int64_t)> get_trip = [&](int64_t no) {
        if (no == 0)
            return make_tuple<int64_t, int64_t, int64_t>(1, 2, 3);

        --no;
        int64_t A = 4;
        while (no >= A) {
            no -= A;
            A *= 4;
        }
        
        auto rs = trip_with(A + no);
        
        return rs;
    };

    // for (int i = 0; i <= 40; ++i) {
    //     auto rs = get_trip(i);
    //     cout << get<0>(rs) << " " << get<1>(rs) << " " << get<2>(rs) << "\n";
    // }

    for (int tc = input<int>(); tc != 0; --tc) {
        int64_t n = input<int64_t>() - 1;

        auto trip = get_trip(n / 3);
        if (n % 3 == 0)
            cout << get<0>(trip) << "\n";
        else if (n % 3 == 1)
            cout << get<1>(trip) << "\n";
        else if (n % 3 == 2)
            cout << get<2>(trip) << "\n";
    }
    

    return 0;
}