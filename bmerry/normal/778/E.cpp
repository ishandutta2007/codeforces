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

static int add(int b, int a)
{
    if (b == -1)
    {
        if (a == 0)
            return -1;
        else
            return a;
    }
    else
        return b + a;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string A;
    int N;
    cin >> A >> N;
    reverse(RA(A));
    int L = SZ(A);
    vector<string> B(N);
    vector<int> c(10);
    int ML = L;
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
        reverse(RA(B[i]));
        while (SZ(B[i]) < L)
            B[i] += '0';
        ML = max(ML, SZ(B[i]));
    }
    for (int i = 0; i < 10; i++)
        cin >> c[i];

    vector<int> dp(N + 1, -1);
    vector<int> order(N), rank(N);
    for (int i = 0; i < N; i++)
        order[i] = i;
    dp[0] = 0;
    for (int pos = 0; pos <= ML + 1; pos++)
    {
        vector<int> dp2(N + 1, -1);
        int lo, hi;
        if (pos >= L)
            lo = hi = 0;
        else if (A[pos] == '?')
        {
            lo = (pos == L - 1) ? 1 : 0;
            hi = 9;
        }
        else
            lo = hi = A[pos] - '0';
        vector<int> col(N);
        for (int i = 0; i < N; i++)
        {
            if (pos >= SZ(B[i]))
                col[i] = -1;
            else
                col[i] = B[i][pos] - '0';
        }
        for (int d = lo; d <= hi; d++)
        {
            int colsum = 0;
            int outc = 0;
            for (int i = 0; i < N; i++)
            {
                int s = add(col[i], d);
                if (s != -1)
                {
                    colsum += c[s % 10];
                    outc += s / 10;
                }
            }
            for (int carry = 0; carry <= N; carry++)
            {
                if (dp[carry] >= 0)
                    dp2[outc] = max(dp2[outc], dp[carry] + colsum);
                if (carry < N)
                {
                    int idx = order[carry];
                    int s = add(col[idx], d);
                    if (s != -1)
                    {
                        colsum -= c[s % 10];
                        outc -= s / 10;
                    }
                    s = add(col[idx], d + 1);
                    colsum += c[s % 10];
                    outc += s / 10;
                }
            }
        }
        stable_sort(RA(order), [&col](int x, int y)
        {
            return max(0, col[x]) > max(0, col[y]);
        });
        dp = move(dp2);
    }
    cout << dp[0] << '\n';

    return 0;
}