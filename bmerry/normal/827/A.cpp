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

struct entry
{
    int x;
    int it;

    bool operator<(const entry &other) const { return x < other.x; }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<string> t(N);
    vector<entry> entries;
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> t[i] >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            x--;
            entries.push_back(entry{x, i});
        }
    }
    sort(RA(entries));
    int ne = 0;
    stack<entry> st;
    string ans;
    for (int i = 0; ; i++)
    {
        while (ne < SZ(entries) && entries[ne].x == i)
            st.push(entries[ne++]);
        if (st.empty())
        {
            if (ne == SZ(entries))
                break;
            ans += 'a';
        }
        else
        {
            auto cur = st.top();
            int end = cur.x + SZ(t[cur.it]);
            if (end <= i)
            {
                st.pop();
                i--;
                continue;
            }
            ans += t[cur.it][i - cur.x];
        }
    }
    cout << ans << '\n';

    return 0;
}