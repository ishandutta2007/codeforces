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

static bool cando(int a, int b, int c)
{
    if (b > 0 && c > 0)
        return true;
    if (a == 0)
        return false;
    if (b == 0 && c == 0)
        return true;
    return b + c >= 2;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    string cards;
    cin >> N >> cards;
    int cnt[3] = {0, 0, 0};
    char labels[3] = {'B', 'G', 'R'};
    for (int i = 0; i < N; i++)
        cnt[find(labels, labels + 3, cards[i]) - labels]++;

    for (int i = 0; i < 3; i++)
    {
        if (cando(cnt[0], cnt[1], cnt[2]))
            cout << labels[0];
        rotate(cnt, cnt + 1, cnt + 3);
        rotate(labels, labels + 1, labels + 3);
    }
    cout << '\n';

    return 0;
}