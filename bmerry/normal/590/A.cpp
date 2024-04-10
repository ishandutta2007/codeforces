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
    vector<uint8_t> seq(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    int ans = 0;
    int start = -1;
    for (int i = 1; i < N; i++)
    {
        if (i < N - 1 && seq[i] != seq[i - 1] && seq[i] != seq[i + 1])
        {
            if (start == -1)
                start = i;
        }
        else if (start != -1)
        {
            int len = i - start;
            ans = max(ans, (len + 1) / 2);
            for (int j = 0; j < len / 2; j++)
                seq[start + j] = seq[start - 1];
            for (int j = len / 2; j < len; j++)
                seq[start + j] = seq[i];
            start = -1;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < N - 1; i++)
        cout << seq[i] << ' ';
    cout << seq[N - 1] << '\n';

    return 0;
}