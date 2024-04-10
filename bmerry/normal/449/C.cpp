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

static vector<int> primes;

static void make_primes(int N)
{
    vector<bool> comp(N + 1);
    for (int i = 2; i <= N; i++)
        if (!comp[i])
        {
            for (int j = i * 2; j <= N; j += i)
                comp[j] = true;
            primes.push_back(i);
        }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    make_primes(N);
    reverse(RA(primes));
    vector<bool> used(N + 1);
    vector<pii> ans;
    for (int p : primes)
    {
        if (2 * p > N)
            continue;

        int have = 0;
        bool save = false;
        for (int i = p; i <= N; i += p)
            if (!used[i])
                have++;
        if ((have & 1) && (p != 2))
            save = true;
        if (save)
        {
            assert(!used[2 * p]);
            used[2 * p] = true;
            have--;
        }

        int last = -1;
        for (int i = p; i <= N; i += p)
            if (!used[i])
            {
                used[i] = true;
                if (last == -1)
                    last = i;
                else
                {
                    ans.emplace_back(last, i);
                    last = -1;
                }
            }

        if (save)
            used[2 * p] = false;
    }

    cout << ans.size() << '\n';
    for (const auto &a : ans)
        cout << a.first << ' ' << a.second << '\n';
    return 0;
}