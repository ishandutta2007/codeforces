#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

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
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

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
    vector<int> r(N);
    for (int i = 0; i < N; i++)
        cin >> r[i];
    int R = *min_element(RA(r));
    while (R > 0)
    {
        int td = 0;
        int md = 0;
        for (int v : r)
        {
            td += v - R;
            md = max(md, v - R);
        }
        if (2 * md <= td)
            break;
        R--;
    }

    vector<vi> games;
    if (R > 0)
    {
        while (true)
        {
            vector<pii> gaps;
            int sum = 0;
            for (int i = 0; i < N; i++)
            {
                gaps.emplace_back(r[i] - R, i);
                sum += r[i] - R;
            }
            if (sum == 0)
                break;
            sort(RA(gaps), greater<pii>());
            int use = (sum == 3) ? 3 : 2;
            vi game;
            for (int i = 0; i < use; i++)
            {
                game.push_back(gaps[i].second);
                r[gaps[i].second]--;
            }
            games.push_back(move(game));
        }
    }
    else
    {
        for (int i = 0; i < *max_element(RA(r)); i++)
            for (int j = 1; j < N; j++)
                games.push_back(vi{0, j});
    }

    cout << R << '\n' << SZ(games) << '\n';
    for (const auto &game : games)
    {
        string line(N, '0');
        for (int v : game)
            line[v] = '1';
        cout << line << '\n';
    }

    return 0;
}