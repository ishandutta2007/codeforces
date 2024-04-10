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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vi> data(N, vi(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> data[i][j];
    for (int c1 = 0; c1 < M; c1++)
        for (int c2 = c1; c2 < M; c2++)
        {
            for (int i = 0; i < N; i++)
                swap(data[i][c1], data[i][c2]);

            bool good = true;
            for (int i = 0; i < N; i++)
            {
                int mm = 0;
                for (int j = 0; j < M; j++)
                    if (data[i][j] != j + 1)
                        mm++;
                if (mm > 2)
                    good = false;
            }
            if (good)
            {
                cout << "YES\n";
                return 0;
            }

            for (int i = 0; i < N; i++)
                swap(data[i][c1], data[i][c2]);
        }

    cout << "NO\n";
    return 0;
}