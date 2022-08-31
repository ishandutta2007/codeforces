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
    int M;
    string S;
    cin >> M >> S;
    int L = SZ(S);
    for (int pass = 0; pass < 26; pass++)
    {
        vector<int> freq(26);
        vector<int> pos;
        char cut = 'a' + pass;
        for (int j = 0; j < L; j++)
        {
            char c = S[j];
            if (c <= cut)
            {
                freq[c - 'a']++;
                pos.push_back(j);
            }
        }
        int last = -1;
        for (int i = 0; i < SZ(pos); i++)
        {
            if (pos[i] - last > M)
                goto bad;
            bool use = true;
            if (S[pos[i]] == cut)
            {
                int next = (i + 1 < SZ(pos)) ? pos[i + 1] : L;
                if (next - last <= M)
                    use = false;
            }
            if (use)
                last = pos[i];
            else
                freq[pass]--;
        }
        if (L - last > M)
            goto bad;

        for (int j = 0; j <= pass; j++)
            cout << string(freq[j], 'a' + j);
        cout << '\n';
        return 0;
bad:;
    }

    return 0;
}