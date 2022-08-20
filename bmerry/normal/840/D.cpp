#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

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
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
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

struct state
{
    array<int, 20> cand;
    int C = 0;
    int L, R;
};

static void recurse(int L, int R, int idx, vector<state> &st, vector<int> &out)
{
    int cL = max(L, st[idx].L);
    int cR = min(R, st[idx].R);
    if (cR - cL <= 0)
        return;
    else if ((cR - cL) * 2 >= st[idx].R - st[idx].L)
        out.push_back(idx);
    else
    {
        recurse(L, R, 2 * idx, st, out);
        recurse(L, R, 2 * idx + 1, st, out);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> pos(N + 1);
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    auto cnt = [&](int L, int R, int c) -> int
    {
        auto p = lower_bound(RA(pos[c]), L);
        auto q = lower_bound(RA(pos[c]), R);
        return q - p;
    };

    int ofs = 1;
    while (ofs < N)
        ofs *= 2;
    vector<state> st(2 * ofs);
    for (int i = 0; i < N; i++)
    {
        st[i + ofs].cand[0] = a[i];
        st[i + ofs].C = 1;
        st[i + ofs].L = i;
        st[i + ofs].R = i + 1;
    }
    for (int i = N; i < ofs; i++)
    {
        st[i + ofs].L = i;
        st[i + ofs].R = i + 1;
    }

    vector<int> cand;
    for (int i = ofs - 1; i > 0; i--)
    {
        const state &a = st[2 * i];
        const state &b = st[2 * i + 1];
        state &s = st[i];
        s.L = a.L;
        s.R = b.R;
        s.C = 0;
        cand.clear();
        cand.insert(cand.end(), a.cand.begin(), a.cand.begin() + a.C);
        cand.insert(cand.end(), b.cand.begin(), b.cand.begin() + b.C);
        sort(RA(cand));
        cand.resize(unique(RA(cand)) - cand.begin());
        for (int c : cand)
            if (cnt(s.L, s.R, c) * 20 > s.R - s.L)
                s.cand[s.C++] = c;
    }

    for (int i = 0; i < Q; i++)
    {
        int L, R, K;
        cin >> L >> R >> K;
        L--;
        int idx = 1;
        int step = st[idx].R - st[idx].L;
        while (L / step == R / step)
        {
            step /= 2;
            idx *= 2;
        }
        vector<int> idxs;
        recurse(L, R, 1, st, idxs);
        int ans = INT_MAX;
        for (int idx : idxs)
        {
            const auto &s = st[idx];
            for (int j = 0; j < s.C; j++)
            {
                int c = s.cand[j];
                if (cnt(L, R, c) * K > R - L)
                {
                    ans = min(ans, c);
                }
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        cout << ans << '\n';
    }

    return 0;
}