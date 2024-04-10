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

static int can(const vi &a, const set<int> &have, int x)
{
    for (int v : a)
        if (have.count(v + x))
            return v;
    return -1;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, L, x, y;
    cin >> N >> L >> x >> y;
    vi a(N);
    set<int> have;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        have.insert(a[i]);
    }

    int can_x = can(a, have, x);
    int can_y = can(a, have, y);
    int can_xy = can(a, have, x + y);
    vi ans;
    if (can_x >= 0 || can_y >= 0)
    {
        if (can_x < 0)
            ans.push_back(x);
        if (can_y < 0)
            ans.push_back(y);
    }
    else if (can_xy >= 0)
    {
        ans.push_back(can_xy + x);
    }
    else
    {
        int found = -1;
        for (int v : a)
            if (v >= x || v <= L - y)
                if (have.count(v + (y - x)))
                {
                    if (v >= x)
                        found = v - x;
                    else
                        found = v + y;
                    break;
                }
        if (found >= 0)
            ans.push_back(found);
        else
        {
            ans.push_back(x);
            ans.push_back(y);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < SZ(ans); i++)
    {
        if (i)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}