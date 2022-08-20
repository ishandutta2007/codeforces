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

static int different(const vs &a, const vs &b)
{
    int R = a.size();
    int C = a[0].size();
    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            ans += a[i][j] != b[i][j];
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int R, C, K, W;
    cin >> R >> C >> K >> W;

    vector<vector<string> > levels(K);

    vector<vi> dist(K, vi(K, R * C));
    for (int i = 0; i < K; i++)
    {
        levels[i].resize(R);
        for (int j = 0; j < R; j++)
            cin >> levels[i][j];
    }

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            dist[i][j] = min(dist[i][j], different(levels[i], levels[j]) * W);

    vi best(K, INT_MAX);
    vi parent(K, -1);
    vector<bool> done(K, false);
    best[0] = R * C;
    int score = 0;
    vi order;
    for (int i = 0; i < K; i++)
    {
        int x = -1;
        for (int j = 0; j < K; j++)
            if (!done[j] && (x == -1 || best[j] < best[x]))
                x = j;
        score += best[x];
        done[x] = true;
        order.push_back(x);
        for (int y = 0; y < K; y++)
            if (!done[y] && dist[x][y] < best[y])
            {
                best[y] = dist[x][y];
                parent[y] = x;
            }
    }

    cout << score << '\n';
    for (int x : order)
    {
        cout << x + 1 << ' ';
        if (parent[x] == -1 || best[x] == R * C)
            cout << "0\n";
        else
            cout << parent[x] + 1 << '\n';
    }

    return 0;
}