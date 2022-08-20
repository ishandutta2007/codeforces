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
    int N, M;
    cin >> N >> M;
    vector<vector<bool> > railway(N, vector<bool>(N));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        railway[a][b] = railway[b][a] = true;
    }

    int dist[N][N][2];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j][0] = dist[i][j][1] = INT_MAX;
    dist[0][0][0] = 0;
    queue<int> q;
    q.push(0);
    q.push(0);
    q.push(0);
    while (!q.empty())
    {
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        int phase = q.front(); q.pop();
        if (a == N - 1 && b == N - 1 && phase == 0)
        {
            cout << dist[a][b][phase] / 2 << '\n';
            return 0;
        }
        if (phase == 0)
        {
            for (int i = 0; i < N; i++)
            {
                bool go = (i != a && railway[a][i]) || (i == N - 1 && a == N - 1);
                if (go && dist[i][b][1] == INT_MAX)
                {
                    dist[i][b][1] = dist[a][b][0] + 1;
                    q.push(i); q.push(b); q.push(1);
                }
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                bool go = (i != b && !railway[b][i]) || (i == N - 1 && b == N - 1);
                if (go && dist[a][i][0] == INT_MAX && (i == N - 1 || i != a))
                {
                    dist[a][i][0] = dist[a][b][1] + 1;
                    q.push(a); q.push(i); q.push(0);
                }
            }
        }
    }
    cout << "-1\n";

    return 0;
}