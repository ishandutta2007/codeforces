// TOO SLOW
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
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

struct impossible {};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K, N;
    cin >> K >> N;
    vector<string> s(K);
    for (int i = 0; i < K; i++)
        cin >> s[i];

    try
    {
        array<int, 26> freq = {{}};
        for (int i = 0; i < N; i++)
            freq[s[0][i] - 'a']++;
        bool eq = *max_element(RA(freq)) > 1;

        vector<vector<int>> diff(K);
        for (int i = 1; i < K; i++)
        {
            array<int, 26> freq2 = {{}};
            for (int j = 0; j < N; j++)
            {
                if (s[i][j] != s[0][j])
                {
                    diff[i].push_back(j);
                    if (SZ(diff[i]) > 4)
                        throw impossible();
                }
                freq2[s[i][j] - 'a']++;
            }
            if (freq2 != freq)
                throw impossible();
        }

        string t = s[0];
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
            {
                swap(t[i], t[j]);
                bool good = true;
                for (int k = 1; k < K; k++)
                {
                    vector<int> D = diff[k];
                    vector<int> un;
                    if (!count(RA(D), i))
                        D.push_back(i);
                    if (!count(RA(D), j))
                        D.push_back(j);
                    int err = 0;
                    for (int d : D)
                        if (s[k][d] != t[d])
                            err++;
                    if ((err == 0 && eq) || err == 2)
                    {
                    }
                    else
                        good = false;
                }
                if (good)
                {
                    cout << t << '\n';
                    return 0;
                }
                swap(t[i], t[j]);
            }
        throw impossible();
    }
    catch (impossible &e)
    {
        cout << "-1\n";
    }

    return 0;
}