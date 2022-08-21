#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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

static void done(const vector<vi> &edges, int u, int v, int h, int t)
{
    set<int> ue(edges[u].begin(), edges[u].end());
    ue.erase(v);
    set<int> ve, common;
    for (int i = 0; i < SZ(edges[v]); i++)
    {
        int y = edges[v][i];
        if (y == u)
            continue;
        if (ue.count(y))
        {
            ue.erase(y);
            common.insert(y);
        }
        else
            ve.insert(y);
    }

    cout << "YES\n" << u + 1 << ' ' << v + 1 << '\n';
    for (int i = 0; i < h; i++)
    {
        int x;
        if (ue.empty())
        {
            x = *common.begin();
            common.erase(common.begin());
        }
        else
        {
            x = *ue.begin();
            ue.erase(ue.begin());
        }
        cout << x + 1 << (i == h - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < t; i++)
    {
        int x;
        if (ve.empty())
        {
            x = *common.begin();
            common.erase(common.begin());
        }
        else
        {
            x = *ve.begin();
            ve.erase(ve.begin());
        }
        cout << x + 1 << (i == t - 1 ? '\n' : ' ');
    }
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, M, h, t;
    cin >> N >> M >> h >> t;
    vector<vector<int> > edges(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vi seen(N, -1);
    for (int u = 0; u < N; u++)
    {
        int du = SZ(edges[u]) - 1;
        if (du >= h)
        {
            if (du < h + t)
            {
                for (int i = 0; i < SZ(edges[u]); i++)
                    seen[edges[u][i]] = u;
                seen[u] = u;
            }
            for (int i = 0; i < SZ(edges[u]); i++)
            {
                int v = edges[u][i];
                int dv = SZ(edges[v]) - 1;
                if (dv >= t)
                {
                    if (du >= h + t || dv >= h + t)
                    {
                        done(edges, u, v, h, t);
                    }
                    else
                    {
                        int total = du;
                        for (int j = 0; j < SZ(edges[v]); j++)
                        {
                            int y = edges[v][j];
                            if (seen[y] != u)
                                total++;
                        }
                        if (total >= h + t)
                            done(edges, u, v, h, t);
                    }
                }
            }
        }
    }

    cout << "NO\n";

    return 0;
}