#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

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

struct query
{
    int p;
    int k;
    int idx;

    bool operator<(const query &other) const
    {
        return k < other.k;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> steps(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int Q;
    cin >> Q;
    vector<query> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].p >> queries[i].k;
        queries[i].p--;
        queries[i].idx = i;
    }
    sort(RA(queries));
    int limit = max(1, int(sqrt(double(N))));
    vector<int> ans(Q);
    int ptr = 0;
    for (int k = 1; k <= limit; k++)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            int nxt = i + a[i] + k;
            steps[i] = (nxt >= N) ? 1 : steps[nxt] + 1;
        }
        while (ptr < Q && queries[ptr].k == k)
        {
            ans[queries[ptr].idx] = steps[queries[ptr].p];
            ptr++;
        }
    }
    while (ptr < Q)
    {
        int cur = queries[ptr].p;
        int k = queries[ptr].k;
        int s = 0;
        while (cur < N)
        {
            s++;
            cur += a[cur] + k;
        }
        ans[queries[ptr].idx] = s;
        ptr++;
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}