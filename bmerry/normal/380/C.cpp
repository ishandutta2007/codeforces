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

    string line;
    cin >> line;
    int L = line.size() + 1;
    vector<vector<int> > lmin(20, vector<int>(L));
    lmin[0][0] = 0;
    for (int i = 0; i < L - 1; i++)
        lmin[0][i + 1] = lmin[0][i] + (line[i] == '(' ? 1 : -1);

    for (int lvl = 1; lvl < 20; lvl++)
    {
        int hstep = 1 << (lvl - 1);
        if (hstep > L)
            break;
        for (int i = 0; i + hstep < L; i++)
            lmin[lvl][i] = min(lmin[lvl - 1][i], lmin[lvl - 1][i + hstep]);
        for (int i = L - hstep; i < L; i++)
            lmin[lvl][i] = lmin[lvl - 1][i];
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r++;
        int g = r - l;
        int lvl = 0;
        while (1 << (lvl + 1) <= g)
            lvl++;
        int lo = min(lmin[lvl][l], lmin[lvl][r - (1 << lvl)]);
        int ans = g - 1 - (lmin[0][l] - lo) - (lmin[0][r - 1] - lo);
        cout << ans << '\n';
    }

    return 0;
}