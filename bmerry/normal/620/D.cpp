#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
}

/*** TEMPLATE CODE ENDS HERE */

struct swapper
{
    ll value;
    int idx[2];

    bool operator<(const swapper &other) const
    {
        return value < other.value;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N[2];
    vector<ll> ab[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> N[i];
        ab[i].resize(N[i]);
        for (int j = 0; j < N[i]; j++)
            cin >> ab[i][j];
    }
    ll goal = accumulate(RA(ab[0]), 0LL) - accumulate(RA(ab[1]), 0LL);

    vector<swapper> sw[2][3];
    for (int i = 0; i < 2; i++)
    {
        sw[i][0].push_back(swapper{0, {-1, -1}});
        for (int j = 0; j < N[i]; j++)
        {
            sw[i][1].push_back(swapper{ab[i][j], {j, -1}});
            for (int k = j + 1; k < N[i]; k++)
                sw[i][2].push_back(swapper{ab[i][j] + ab[i][k], {j, k}});
        }
    }

    ll best = LLONG_MAX;
    swapper best_swaps[2];
    auto trial = [&] (const swapper &a, const swapper &b)
    {
        ll score = llabs(2 * (a.value - b.value) - goal);
        if (score < best)
        {
            best = score;
            best_swaps[0] = a;
            best_swaps[1] = b;
        }
    };

    for (int k = 0; k <= 2; k++)
    {
        sort(RA(sw[0][k]));
        sort(RA(sw[1][k]));
        int pos = 0;
        for (const swapper &a : sw[0][k])
        {
            while (pos < SZ(sw[1][k]) && 2 * (a.value - sw[1][k][pos].value) >= goal)
                pos++;
            if (pos > 0)
                trial(a, sw[1][k][pos - 1]);
            if (pos < SZ(sw[1][k]))
                trial(a, sw[1][k][pos]);
        }
    }

    int k = 0;
    while (k < 2 && best_swaps[0].idx[k] >= 0)
        k++;
    cout << best << '\n' << k << '\n';
    for (int i = 0; i < k; i++)
    {
        cout << best_swaps[0].idx[i] + 1 << ' ' << best_swaps[1].idx[i] + 1 << '\n';
    }

    return 0;
}