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
    vi cnts(N);
    int g = 0;
    int odd = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> cnts[i];
        g = gcd(cnts[i], g);
        if (cnts[i] & 1)
            odd++;
    }
    if (odd > 1)
    {
        cout << "0\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < cnts[i]; j++)
                cout << char('a' + i);
    }
    else
    {
        cout << g << '\n';
        for (int i = 0; i < N; i++)
            cnts[i] /= g;
        string forw, back;
        if (g & 1)
        {
            char mid = '\0';
            string half;
            for (int i = 0; i < N; i++)
            {
                for (int j = 1; j < cnts[i]; j += 2)
                    half += char('a' + i);
                if (cnts[i] & 1)
                    mid = 'a' + i;
            }
            string ref = half;
            reverse(RA(ref));
            if (mid)
                half += mid;
            forw = back = half + ref;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < cnts[i]; j++)
                    forw += char('a' + i);
            }
            back = forw;
            reverse(RA(back));
        }
        for (int i = 0; i < g; i++)
            cout << ((i & 1) ? forw : back);
    }
    cout << '\n';
    return 0;
}