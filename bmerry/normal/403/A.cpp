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

    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        set<pii> edges;
        int N, P;
        cin >> N >> P;
        for (int i = 0; i < N; i++)
        {
            edges.insert(pii(i, (i + 1) % N));
            edges.insert(pii(i, (i + 2) % N));
            edges.insert(pii((i + 1) % N, i));
            edges.insert(pii((i + 2) % N, i));
        }
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N && P > 0; j++)
            {
                if (!edges.count(pii(i, j)))
                {
                    edges.insert(pii(i, j));
                    edges.insert(pii(j, i));
                    P--;
                }
            }

        for (const pii &e : edges)
            if (e.first < e.second)
                cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
    return 0;
}