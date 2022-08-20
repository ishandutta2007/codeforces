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

static int query(const vector<vi> &right, int r1, int c1, int r2, int c2)
{
    return right[r2][c2] + right[r1][c1] - right[r1][c2] - right[r2][c1];
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vector<vi> right(R + 1, vi(C + 1, 0));
    vector<vi> down(R + 1, vi(C + 1, 0));
    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C - 1; j++)
        {
            if (grid[i][j] == '.' && grid[i][j + 1] == '.')
                right[i + 1][j + 1]++;
        }
    for (int i = 0; i < R - 1; i++)
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == '.' && grid[i + 1][j] == '.')
                down[i + 1][j + 1]++;
        }
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            right[i][j] += right[i - 1][j] + right[i][j - 1] - right[i - 1][j - 1];
            down[i][j] += down[i - 1][j] + down[i][j - 1] - down[i - 1][j - 1];
        }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        int ans = query(right, r1, c1, r2, c2 - 1) + query(down, r1, c1, r2 - 1, c2);
        cout << ans << '\n';
    }

    return 0;
}