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
    ll N, A, cf, cm, M;
    cin >> N >> A >> cf >> cm >> M;
    vector<pair<ll, int>> s(N);
    vector<ll> ss(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(RA(s));
    for (int i = 0; i < N; i++)
        ss[i + 1] = ss[i] + s[i].first;
    ll best = -1;
    ll best_i = -1;
    ll best_low = -1;
    for (int i = 0; i <= N; i++)
    {
        ll need = A * i - (ss[N] - ss[N - i]);
        if (need > M)
            break;
        ll low;
        if (i == N)
        {
            low = A;
        }
        else
        {
            ll rem = M - need;
            ll L = 0;
            ll R = N - i;
            while (R - L > 1)
            {
                ll mid = (L + R) / 2;
                need = s[mid].first * mid - ss[mid];
                if (need > rem)
                    R = mid;
                else
                    L = mid;
            }
            need = s[L].first * L - ss[L];
            rem -= need;
            low = s[L].first + rem / (L + 1);
            low = min(low, A);
        }
        ll score = i * cf + low * cm;
        if (score > best)
        {
            best = score;
            best_i = i;
            best_low = low;
        }
    }

    cout << best << '\n';
    vector<ll> out(N);
    for (int i = 0; i < N; i++)
    {
        ll a;
        if (i < N - best_i)
            a = max(best_low, s[i].first);
        else
            a = A;
        out[s[i].second] = a;
    }
    for (int i = 0; i < N - 1; i++)
        cout << out[i] << ' ';
    cout << out[N - 1] << '\n';
    return 0;
}