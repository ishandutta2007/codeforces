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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int sides[6];
    for (int i = 0; i < 6; i++)
        cin >> sides[i];
    int dx[6], dy[6];
    dx[0] = 2 * sides[0]; dy[0] = 0;
    dx[1] = sides[1]; dy[1] = 2 * sides[1];
    dx[2] = -sides[2]; dy[2] = 2 * sides[2];
    dx[3] = -2 * sides[3]; dy[3] = 0;
    dx[4] = -sides[4]; dy[4] = -2 * sides[4];
    dx[5] = sides[5]; dy[5] = -2 * sides[5];
    int x = 0, y = 0;
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        ans += (x - x2) * (y + y2);
        x = x2;
        y = y2;
    }
    cout << ans / 4 << '\n';
    return 0;
}