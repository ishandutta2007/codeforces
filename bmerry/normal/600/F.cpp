// DOES NOT WORK

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

struct edge
{
    int trg = -1;
    int id = -1;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N[2], M;
    cin >> N[0] >> N[1] >> M;
    vi deg[2];
    deg[0].resize(N[0]);
    deg[1].resize(N[1]);
    vector<pii> elist(M);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        elist[i] = pii(x, y);
        deg[0][x]++;
        deg[1][y]++;
    }
    int maxd = max(*max_element(RA(deg[0])), *max_element(RA(deg[1])));

    array<vector<vector<edge>>, 2> edges;
    edges[0].resize(N[0], vector<edge>(maxd));
    edges[1].resize(N[1], vector<edge>(maxd));

    for (int i = 0; i < M; i++)
    {
        auto [x, y] = elist[i];
        int c = 0;
        while (c < maxd && (edges[0][x][c].trg >= 0 || edges[1][y][c].trg >= 0))
            c++;
        if (c < maxd)
        {
            edges[0][x][c] = edge{y, i};
            edges[1][y][c] = edge{x, i};
            continue;
        }
        int c1 = 0, c2 = 0;
        while (c1 < maxd && edges[0][x][c1].trg >= 0)
            c1++;
        while (c2 < maxd && edges[1][y][c2].trg >= 0)
            c2++;
        int side = 1;
        int cur = y;
        vi path;
        while (edges[side][cur][c1].trg != -1)
        {
            cur = edges[side][cur][c1].trg;
            side = !side;
            swap(c1, c2);
            path.push_back(cur);
        }
        while (!path.empty())
        {
            int cur = path.back();
            path.pop_back();
            swap(edges[side][cur][c1], edges[side][cur][c2]);
            swap(c1, c2);
            side = !side;
        }
        swap(edges[1][y][c1], edges[1][y][c2]);
        edges[0][x][c1] = edge{y, i};
        edges[1][y][c1] = edge{x, i};
    }

    vi ans(M);
    for (int i = 0; i < N[0]; i++)
        for (int j = 0; j < maxd; j++)
            if (edges[0][i][j].trg >= 0)
                ans[edges[0][i][j].id] = j + 1;
    cout << maxd << '\n';
    for (int i = 0; i < M; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}