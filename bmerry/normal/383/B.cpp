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
    int N, M;
    cin >> N >> M;
    vector<pii> volc(M);
    for (int i = 0; i < M; i++)
    {
        cin >> volc[i].first;
        cin >> volc[i].second;
    }
    sort(RA(volc));
    volc.emplace_back(N + 1, N + 1);
    M++;

    int p = 0;
    vector<pii> reach{{1, 2}};
    int y = 0;
    while (p < M)
    {
        if (volc[p].first > y + 1)
        {
            if (!reach.empty())
            {
                reach.resize(1);
                reach[0].second = N + 1;
            }
        }
        y = volc[p].first;
        if (y > N)
            break;

        int start = 1;
        int q = p;
        int r = 0;
        vector<pii> next;
        while (volc[q].first == y)
        {
            int end = volc[q].second;
            if (end > start)
            {
                while (r < SZ(reach) && reach[r].second <= start)
                    r++;
                if (r < SZ(reach) && reach[r].first < end)
                    next.emplace_back(max(reach[r].first, start), end);
            }
            q++;
            start = end + 1;
        }
        int end = N + 1;
        if (end > start)
        {
            while (r < SZ(reach) && reach[r].second <= start)
                r++;
            if (r < SZ(reach) && reach[r].first < end)
                next.emplace_back(max(reach[r].first, start), end);
        }
        p = q;
        reach = move(next);
    }

    if (reach.empty() || reach.back().second <= N)
        cout << "-1\n";
    else
        cout << 2 * N - 2 << '\n';

    return 0;
}