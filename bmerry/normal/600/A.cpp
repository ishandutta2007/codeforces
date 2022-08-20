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

static void fix(string &s)
{
    if (s.empty())
        s = "-";
    else
    {
        s = '"' + s;
        s[SZ(s) - 1] = '"';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string s;
    cin >> s;
    s += ";";
    string cur;
    bool is_num = false;
    string a, b;
    for (char c : s)
    {
        if (c == ',' || c == ';')
        {
            if (is_num)
                a += cur + ',';
            else
                b += cur + ',';
            cur = "";
            is_num = false;
        }
        else
        {
            cur += c;
            if (SZ(cur) > 1 && cur[0] == '0')
                is_num = false;
            if (c < '0' || c > '9')
                is_num = false;
            else if (SZ(cur) == 1)
                is_num = true;
        }
    }
    fix(a);
    fix(b);
    cout << a << '\n' << b << '\n';
    return 0;
}