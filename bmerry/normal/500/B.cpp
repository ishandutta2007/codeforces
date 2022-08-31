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

static void dfs(int x, vi &comp, vector<bool> &seen, const vector<string> &A)
{
    if (seen[x])
        return;
    seen[x] = true;
    comp.push_back(x);
    for (int i = 0; i < SZ(A); i++)
        if (A[x][i] == '1')
            dfs(i, comp, seen, A);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> p(N);
    vector<string> A(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<bool> seen(N);
    for (int i = 0; i < N; i++)
        if (!seen[i])
        {
            vi comp;
            dfs(i, comp, seen, A);
            sort(RA(comp));
            vi tgt;
            tgt.reserve(comp.size());
            for (int j = 0; j < SZ(comp); j++)
                tgt.push_back(p[comp[j]]);
            sort(RA(tgt));
            for (int j = 0; j < SZ(comp); j++)
                p[comp[j]] = tgt[j];
        }
    for (int i = 0; i < N; i++)
        cout << p[i] << (i == N - 1 ? '\n' : ' ');

    return 0;
}