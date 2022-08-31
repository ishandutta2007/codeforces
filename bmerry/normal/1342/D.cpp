//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

struct arr
{
    int size;
    int idx;

    bool operator<(const arr &other) const { return size > other.size; }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    vector<arr> m(N);
    for (int i = 0; i < N; i++)
    {
        cin >> m[i].size;
        m[i].idx = i;
    }
    sort(RA(m));

    vi c(K + 1);
    for (int i = 1; i <= K; i++)
        cin >> c[i];

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vi> cases(1);
    pq.emplace(0, 0);
    for (const arr &a : m)
    {
        pii nxt = pq.top();
        if (nxt.first >= c[a.size])
        {
            pq.emplace(0, SZ(cases));
            cases.emplace_back();
            nxt = pq.top();
        }
        pq.pop();
        cases[nxt.second].push_back(a.size);
        nxt.first++;
        pq.push(nxt);
    }
    cout << SZ(cases) << '\n';
    for (const auto &cas : cases)
    {
        cout << SZ(cas);
        for (int id : cas)
            cout << ' ' << id;
        cout << '\n';
    }

    return 0;
}