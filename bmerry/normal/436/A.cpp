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

struct candy
{
    int h;
    int m;

    bool operator<(const candy &b) const
    {
        return h < b.h;
    }
};

static int solve(vector<candy> C[2], int X)
{
    int ans = 0;
    int p[2] = {0, 0};
    priority_queue<int> q[2];
    for (int i = 0; ; i = !i)
    {
        while (p[i] < SZ(C[i]) && C[i][p[i]].h <= X)
        {
            q[i].push(C[i][p[i]].m);
            p[i]++;
        }
        if (q[i].empty())
            return ans;
        X += q[i].top();
        q[i].pop();
        ans++;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, X;
    cin >> N >> X;
    vector<candy> C[2];
    for (int i = 0; i < N; i++)
    {
        int t, h, m;
        cin >> t >> h >> m;
        C[t].push_back(candy{h, m});
    }
    sort(RA(C[0]));
    sort(RA(C[1]));
    int ans = solve(C, X);
    swap(C[0], C[1]);
    ans = max(ans, solve(C, X));
    cout << ans << '\n';

    return 0;
}