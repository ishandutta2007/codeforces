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

static int N, M;
static vector<string> grid;
static vector<vi> nleft, nright;

static void fix_row(int r)
{
    int last = -1;
    for (int i = 0; i < M; i++)
    {
        if (grid[r][i] == 'X')
            last = i;
        nleft[r][i] = last;
    }

    last = M;
    for (int i = M - 1; i >= 0; i--)
    {
        if (grid[r][i] == 'X')
            last = i;
        nright[r][i] = last;
    }
}

static int best_col(int c)
{
    int best = 0;
    int r0 = 0;
    int r1 = r0;
    deque<pii> left, right;
    while (r0 < N)
    {
        if (r1 <= r0)
        {
            left.push_back(pii(r1, nleft[r1][c]));
            right.push_back(pii(r1, nright[r1][c]));
            r1++;
        }
        while (right[0].second - left[0].second - 1 > r1 - r0)
        {
            best = max(best, r1 - r0);
            while (!left.empty() && nleft[r1][c] > left.back().second)
                left.pop_back();
            left.push_back(pii(r1, nleft[r1][c]));
            while (!right.empty() && nright[r1][c] < right.back().second)
                right.pop_back();
            right.push_back(pii(r1, nright[r1][c]));
            r1++;
        }
        best = max(best, right[0].second - left[0].second - 1);
        r0++;
        while (!left.empty() && left[0].first < r0)
            left.pop_front();
        while (!right.empty() && right[0].first < r0)
            right.pop_front();
    }
    return best;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K;
    cin >> N >> M >> K;
    grid.clear();
    grid.resize(N);
    nleft.resize(N + 1, vi(M, -1));
    nright.resize(N + 1, vi(M, M));
    for (int i = 0; i < M; i++)
    {
        nleft[N][i] = M;
        nright[N][i] = -1;
    }

    for (int i = 0; i < N; i++)
        cin >> grid[i];

    vector<pii> park;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        grid[x][y] = 'X';
        park.push_back(pii(x, y));
    }

    int cur = 0;
    for (int i = 0; i < N; i++)
        fix_row(i);
    for (int i = 0; i < M; i++)
        cur = max(cur, best_col(i));
    vi ans(K);
    ans[K - 1] = cur;
    for (int i = K - 1; i > 0; i--)
    {
        int r, c;
        tie(r, c) = park[i];
        grid[r][c] = '.';
        fix_row(r);
        cur = max(cur, best_col(c));
        ans[i - 1] = cur;
    }
    for (int v : ans)
        cout << v << '\n';

    return 0;
}