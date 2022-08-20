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

template<typename Op>
static void combine(vector<array<int, 2>> &out,
                    const vector<array<int, 2>> &left,
                    const vector<array<int, 2>> &right,
                    const Op &op)
{
    int M = SZ(out);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < 2; j++)
            out[i][j] = op(left[i][j], right[i][j]);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    map<string, vector<array<int, 2>>> vars;
    vector<array<int, 2>> peter(M);
    for (int i = 0; i < M; i++)
    {
        peter[i][0] = 0;
        peter[i][1] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        string name, assign, left;
        cin >> name >> assign >> left;
        vector<array<int, 2>> out(M);
        if (left[0] == '0' || left[0] == '1')
        {
            for (int j = 0; j < M; j++)
                out[j][0] = out[j][1] = left[j] - '0';
        }
        else
        {
            string op, right;
            cin >> op >> right;
            const auto &leftv = (left == "?") ? peter : vars[left];
            const auto &rightv = (right == "?") ? peter : vars[right];
            if (op == "XOR")
                combine(out, leftv, rightv, [](int x, int y) { return x ^ y; });
            else if (op == "AND")
                combine(out, leftv, rightv, [](int x, int y) { return x & y; });
            else if (op == "OR")
                combine(out, leftv, rightv, [](int x, int y) { return x | y; });
        }
        vars[name] = out;
    }
    vector<int> lo(M), hi(M);
    for (int i = 0; i < M; i++)
    {
        int sums[2] = {0, 0};
        for (const auto &entry : vars)
        {
            for (int j = 0; j < 2; j++)
                sums[j] += entry.second[i][j];
        }
        if (sums[1] > sums[0])
            hi[i] = 1;
        if (sums[1] < sums[0])
            lo[i] = 1;
    }
    for (int i = 0; i < M; i++)
        cout << lo[i];
    cout << '\n';
    for (int i = 0; i < M; i++)
        cout << hi[i];
    cout << '\n';

    return 0;
}