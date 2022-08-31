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

static int dfs(const vector<vector<int> > &edges, vector<bool> &reach, int cur)
{
    if (reach[cur])
        return 0;
    reach[cur] = true;
    int ans = 1;
    for (int e : edges[cur])
        ans += dfs(edges, reach, e);
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    vector<vector<int> > redges(N);
    vector<vector<int> > fedges(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int b;
            cin >> b;
            if (b > 0)
            {
                fedges[i].push_back(j);
                redges[j].push_back(i);
            }
        }

    vector<bool> reach_forw(N), reach_back(N);
    int forw = dfs(fedges, reach_forw, 0);
    int back = dfs(redges, reach_back, 0);
    bool yes = (forw == N && back == N);
    if (yes)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}