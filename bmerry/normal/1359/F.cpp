#pragma GCC optimize("O3")
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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi x(N), y(N), dx(N), dy(N), s(N);
    vector<double> scale(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s[i];
        scale[i] = s[i] / hypot(dx[i], dy[i]);
    }

    double ans = HUGE_VAL;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            int det = dx[j] * dy[i] - dx[i] * dy[j];
            int xd = x[j] - x[i];
            int yd = y[j] - y[i];
            if (det != 0)
            {
                int a = -dy[j] * xd + dx[j] * yd;
                int b = -dy[i] * xd + dx[i] * yd;
                double alpha = a / (det * scale[i]);
                double beta = b / (det * scale[j]);
                if (alpha >= 0 && beta >= 0)
                {
                    double t = max(alpha, beta);
                    ans = min(ans, t);
                }
            }
            else if (xd * dy[i] - yd * dx[i] == 0)
            {
                double dist = sqrt(double(xd * xd + yd * yd));
                bool fi = xd * dx[i] + yd * dy[i] > 0;
                bool fj = xd * dx[j] + yd * dy[j] < 0;
                double speed, t;
                if (fi && fj)
                    speed = s[i] + s[j];
                else if (fi)
                    speed = s[i];
                else if (fj)
                    speed = s[j];
                else
                    goto skip;
                t = dist / speed;
                ans = min(ans, t);
skip:;
            }
        }
    if (ans == HUGE_VAL)
        cout << "No show :(\n";
    else
        cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}