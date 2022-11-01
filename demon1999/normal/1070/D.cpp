#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

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
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int64_t n = input<int>();
    int64_t k = input<int>();

    int64_t ans = 0;

    int rem = 0;

    for (int i = 0; i != n; ++i) {
        int64_t elem = input<int64_t>();

        if (rem == 0)
            rem += elem;
        else {
            int64_t now = (rem + k - 1) / k;
            elem = max((int64_t)0, elem - (now * k - rem));
            rem = elem;

            ans += now;
        }
    }

    ans += (rem + k - 1) / k;

    cout << ans << "\n";
    return 0;
}