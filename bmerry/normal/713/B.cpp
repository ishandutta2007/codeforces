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

static int query(int x0, int y0, int x1, int y1, bool swapped)
{
    cout << "? ";
    if (swapped)
        cout << y0 + 1 << ' ' << x0 + 1 << ' ' << y1 << ' ' << x1 << endl;
    else
        cout << x0 + 1 << ' ' << y0 + 1 << ' ' << x1 << ' ' << y1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

static int query(array<int, 4> rect, bool swapped)
{
    return query(rect[0], rect[1], rect[2], rect[3], swapped);
}

static array<int, 4> find_rectangle(int x0, int y0, int x1, int y1, bool swapped)
{
    array<int, 4> cur{{x0, y0, x1, y1}};
    for (int i = 0; i < 4; i++)
    {
        int lo = cur[i];
        int hi = cur[i ^ 2];
        while (abs(hi - lo) > 1)
        {
            int mid = (lo + hi) / 2;
            cur[i] = mid;
            if (query(cur, swapped) == 1)
                lo = mid;
            else
                hi = mid;
        }
        cur[i] = lo;
    }
    return cur;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    bool swapped = false;
    int cut = -1;
    for (int pass = 0; pass < 2; pass++)
    {
        int lo = 0;
        int hi = N;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            int q = query(0, 0, N, mid, swapped);
            if (q == 0)
                lo = mid;
            else
                hi = mid;
        }
        if (query(0, 0, N, hi, swapped) == 1
            && query(0, hi, N, N, swapped) == 1)
        {
            cut = hi;
            break;
        }
        swapped = !swapped;
    }

    array<int, 4> rects[2];
    rects[0] = find_rectangle(0, 0, N, cut, swapped);
    rects[1] = find_rectangle(0, cut, N, N, swapped);
    cout << '!';
    for (int i = 0; i < 2; i++)
    {
        if (swapped)
        {
            swap(rects[i][0], rects[i][1]);
            swap(rects[i][2], rects[i][3]);
        }
        cout << ' ' << rects[i][0] + 1 << ' ' << rects[i][1] + 1
             << ' ' << rects[i][2] << ' ' << rects[i][3];
    }
    cout << endl;

    return 0;
}