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
}

/*** TEMPLATE CODE ENDS HERE */

static void no()
{
    cout << "-1\n";
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    vi a(N);
    int out = 0;
    set<int> miss;
    for (int i = 0; i < N; i++)
        miss.insert(i);
    for (int i = 0; i < K; i++)
    {
        cin >> a[i];
        a[i]--;
        miss.erase(a[i]);
    }
    stack<int> s;
    for (int i = 0; i < K; i++)
    {
        while (!s.empty() && s.top() < a[i])
        {
            if (s.top() != out)
                no();
            s.pop();
            out++;
        }
        s.push(a[i]);
    }

    for (int i = K; i < N; i++)
    {
        while (!s.empty() && s.top() == out)
        {
            s.pop();
            out++;
        }
        int limit = s.empty() ? INT_MAX / 2 : s.top();
        auto it = prev(miss.lower_bound(limit));
        s.push(*it);
        a[i] = *it;
        miss.erase(it);
    }

    for (int i = 0; i < N; i++)
        cout << a[i] + 1 << ' ';
    cout << '\n';

    return 0;
}