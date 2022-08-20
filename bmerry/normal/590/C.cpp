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

static const int dr[4] = {0, 0, -1, 1};
static const int dc[4] = {-1, 1, 0, 0};

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
    int R, C;
    cin >> R >> C;
    int V = 3;
    vector<string> grid(R);
    vector<vi> label(R, vi(C, -1));
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < C; j++)
        {
            switch (grid[i][j])
            {
            case '.':
                label[i][j] = V++;
                break;
            case '#':
                break;
            default:
                label[i][j] = grid[i][j] - '1';
                break;
            }
        }
    }
    vector<vi> edges(V);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (label[i][j] >= 0)
                for (int d = 0; d < 4; d++)
                {
                    int r = i + dr[d];
                    int c = j + dc[d];
                    if (r >= 0 && r < R && c >= 0 && c < C && label[r][c] >= 0)
                        edges[label[i][j]].push_back(label[r][c]);
                }
        }

    vector<int> dists[3];
    for (int i = 0; i < 3; i++)
    {
        queue<int> q;
        dists[i].resize(V, INT_MAX / 4);
        dists[i][i] = 0;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int y : edges[cur])
            {
                if (dists[i][y] == INT_MAX / 4)
                {
                    dists[i][y] = dists[i][cur] + 1;
                    q.push(y);
                }
            }
        }
    }
    int ans = INT_MAX / 8;
    for (int i = 0; i < V; i++)
    {
        int sum = dists[0][i] + dists[1][i] + dists[2][i] - 2;
        ans = min(ans, sum);
    }
    if (ans == INT_MAX / 8)
        ans = -1;
    cout << ans << '\n';
    return 0;
}