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

    int n = input<int>();

    vector<int> a, suma, b, sumb, c, sumc;

    int d = 0, sumd = 0;
    
    for (int i = 0; i != n; ++i) {
        string s = input<string>();
        int val = input<int>();

        if (s == "00")
            a.push_back(val);
        else if (s == "01")
            b.push_back(val);
        else if (s == "10")
            c.push_back(val);
        else
            sumd += val, d += 1;
    }

    sort(RALL(a)); sort(RALL(b)); sort(RALL(c));

    suma.resize(SZ(a) + 1);
    sumb.resize(SZ(b) + 1);
    sumc.resize(SZ(c) + 1);

    for (int i = 0; i != SZ(a); ++i)
        suma[i + 1] = suma[i] + a[i];

    for (int i = 0; i != SZ(b); ++i)
        sumb[i + 1] = sumb[i] + b[i];

    for (int i = 0; i != SZ(c); ++i)
        sumc[i + 1] = sumc[i] + c[i];

    int ans = 0;
    auto kukarek = [&](int na, int nb, int nc) {
        ans = max(ans, sumd + suma[na] + sumb[nb] + sumc[nc]);
    };
    
    for (int num_a = 0; num_a <= SZ(a); ++num_a) {
        int delta = d - num_a;
        if (delta < 0)
            break;

        if (1) {
            int num_b = SZ(b);
            int num_c = min(SZ(c), num_b + delta);

            if (abs(num_b - num_c) <= delta) {
                kukarek(num_a, num_b, num_c);
            }
        }

        if (1) {
            int num_c = SZ(c);
            int num_b = min(SZ(b), num_c + delta);
            
            if (abs(num_b - num_c) <= delta) {
                kukarek(num_a, num_b, num_c);                
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}