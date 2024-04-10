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

typedef priority_queue<int, vector<int>, greater<int> > rpq;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K;
    int N[3], T[3], A[3];
    cin >> K >> N[0] >> N[1] >> N[2] >> T[0] >> T[1] >> T[2];

    A[0] = 0;
    A[1] = T[0];
    A[2] = T[0] + T[1];

    rpq avail[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N[i]; j++)
            avail[i].push(0);

    int last = 0;
    for (int i = 0; i < K; i++)
    {
        int start = 0;
        for (int j = 0; j < 3; j++)
        {
            int t = avail[j].top();
            avail[j].pop();
            start = max(start, t - A[j]);
        }
        for (int j = 0; j < 3; j++)
            avail[j].push(start + A[j] + T[j]);
        last = start + A[2] + T[2];
    }

    cout << last << '\n';
    return 0;
}