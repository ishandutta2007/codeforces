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

static string normalize(string a)
{
    a = "00" + a;
    for (int i = 1; i + 1 < SZ(a); i++)
    {
        int x = i;
        while (x >= 0 && a[x] == '1' && a[x + 1] == '1')
        {
            assert(x > 0 && a[x - 1] == '0');
            a[x - 1] = '1';
            a[x] = '0';
            a[x + 1] = '0';
            x -= 2;
        }
    }
    return a;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    string a, b;
    cin >> a >> b;
    a = normalize(a);
    b = normalize(b);
    int L = max(SZ(a), SZ(b));
    a = string(L - SZ(a), '0') + a;
    b = string(L - SZ(b), '0') + b;
    if (a < b)
        cout << "<\n";
    else if (a > b)
        cout << ">\n";
    else
        cout << "=\n";

    return 0;
}