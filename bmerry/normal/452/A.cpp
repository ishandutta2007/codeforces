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


static bool match(const string &a, const string &b)
{
    if (SZ(a) != SZ(b))
        return false;
    for (int i = 0; i < SZ(a); i++)
        if (a[i] != b[i] && b[i] != '.')
            return false;
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    constexpr int N = 8;
    const string names[N] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int L;
    string known;
    cin >> L >> known;
    for (const string &s : names)
    {
        if (match(s, known))
        {
            cout << s << '\n';
            break;
        }
    }

    return 0;
}