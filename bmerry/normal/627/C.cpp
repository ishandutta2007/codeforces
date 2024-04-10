#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<ll, ll> pii;

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
    int M;
    ll D, vol;
    cin >> D >> vol >> M;
    vector<pii> stations(M + 2);
    for (int i = 0; i < M; i++)
        cin >> stations[i].first >> stations[i].second;
    stations[M] = pii(D, 0);
    stations[M + 1] = pii(0, 1);
    M += 2;
    sort(RA(stations));
    vector<int> nextc(M);
    stack<int> cheap;
    cheap.push(M - 1);
    for (int i = M - 2; i >= 0; i--)
    {
        while (stations[i].second <= stations[cheap.top()].second)
            cheap.pop();
        nextc[i] = cheap.top();
        cheap.push(i);
    }

    ll tank = vol;
    int pos = 0;
    ll cost = 0;
    while (pos < M - 1)
    {
        int n = nextc[pos];
        ll d = stations[n].first - stations[pos].first;
        if (d <= vol)
        {
            if (tank < d)
            {
                cost += (d - tank) * stations[pos].second;
                tank = d;
            }
            pos = n;
            tank -= d;
        }
        else
        {
            cost += (vol - tank) * stations[pos].second;
            tank = vol;
            d = stations[pos + 1].first - stations[pos].first;
            if (d > vol)
            {
                cout << "-1\n";
                return 0;
            }
            tank -= d;
            pos++;
        }
    }
    cout << cost << '\n';

    return 0;
}