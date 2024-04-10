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

struct item
{
    int c;
    int h;
    int t;

    bool operator<(const item &b) const
    {
        return t < b.t;
    }
};

constexpr int MAXB = 4002;

static void add(vi &dp, const item &it)
{
    for (int i = SZ(dp) - 1; i >= it.c; i--)
        dp[i] = max(dp[i], dp[i - it.c] + it.h);
}

static inline int get_time(const vi &times, int idx)
{
    return idx >= SZ(times) ? INT_MAX : times[idx];
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, P;
    cin >> N >> P;
    vector<item> items(N);
    vector<int> times{0};
    for (int i = 0; i < N; i++)
    {
        cin >> items[i].c >> items[i].h >> items[i].t;
        times.push_back(items[i].t);
        times.push_back(items[i].t + P);
    }
    sort(RA(items));
    sort(RA(times));
    times.resize(unique(RA(times)) - times.begin());

    int scale = 1;
    int shift = 0;
    while (scale <= SZ(times) + 1)
    {
        scale <<= 1;
        shift++;
    }

    vector<vi> dp(1, vi(MAXB, 0));
    while (shift > 0)
    {
        shift--;
        vector<vi> dp2;
        dp2.reserve(2 * SZ(dp));
        int pa = 0;
        int pd = 0;
        for (int i = 0; i < SZ(dp); i++)
        {
            dp2.push_back(dp[i]);
            while (pd < N && items[pd].t + P < get_time(times, (2 * i + 1) << shift))
                pd++;
            while (pd < N && items[pd].t + P < get_time(times, (2 * i + 2) << shift))
            {
                if (items[pd].t <= get_time(times, (2 * i) << shift))
                    add(dp2.back(), items[pd]);
                pd++;
            }

            dp2.push_back(move(dp[i]));
            while (pa < N && items[pa].t <= get_time(times, (2 * i) << shift))
                pa++;
            while (pa < N && items[pa].t <= get_time(times, (2 * i + 1) << shift))
            {
                if (items[pa].t + P >= get_time(times, (2 * i + 2) << shift))
                    add(dp2.back(), items[pa]);
                pa++;
            }
        }
        dp = move(dp2);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        a = upper_bound(RA(times), a) - times.begin() - 1;
        cout << dp[a][b] << '\n';
    }

    return 0;
}