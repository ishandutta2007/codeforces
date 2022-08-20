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
    int N;
    cin >> N;
    vector<vector<int> > contact(N, vi(N, 0));
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
            contact[i][j] = line[j] == '1';
    }
    vi deg(N);
    for (int i = 0; i < N; i++)
        cin >> deg[i];

    vector<bool> invite(N);
    bool more = true;
    while (more)
    {
        more = false;
        for (int i = 0; i < N; i++)
            if (!invite[i] && deg[i] == 0)
            {
                more = true;
                invite[i] = true;
                for (int j = 0; j < N; j++)
                    deg[j] -= contact[i][j];
            }
    }

    cout << count(invite.begin(), invite.end(), true) << '\n';
    bool first = true;
    for (int i = 0; i < N; i++)
        if (invite[i])
        {
            if (!first)
                cout << ' ';
            first = false;
            cout << i + 1;
        }
    cout << '\n';

    return 0;
}