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

static vi parent;

static int find(int x)
{
    if (parent[x] < 0)
        return x;
    else
        return parent[x] = find(parent[x]);
}

static void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;

    if (-parent[a] > -parent[b])
        swap(a, b);
    parent[b] += parent[a];
    parent[a] = b;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, M;
    cin >> N >> M;
    parent.resize(N, -1);
    vector<pii> nodes(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nodes[i].first;
        nodes[i].second = i;
    }
    sort(RA(nodes), greater<pii>());

    vector<vi> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    double sum = 0.0;
    vector<bool> done(N, false);
    for (int i = 0; i < N; i++)
    {
        double a = nodes[i].first;
        int x = nodes[i].second;
        for (int y : edges[x])
        {
            if (!done[y])
                continue;
            int p = find(y);
            int q = find(x);
            if (p != q)
            {
                sum += a * parent[p] * parent[q];
                merge(p, q);
            }
        }
        done[x] = true;
    }

    cout << fixed << sum * 2.0 / N / (N - 1) << '\n';

    return 0;
}