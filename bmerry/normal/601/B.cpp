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
    int N, Q;
    cin >> N >> Q;
    int prev;
    cin >> prev;
    vi h(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        int x;
        cin >> x;
        h[i] = abs(x - prev);
        prev = x;
    }
    N--;

    vector<pii> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;
        queries[i].second--;
    }

    vector<int> after(N);
    stack<pii> st;
    st.emplace(N, INT_MAX);
    for (int i = N - 1; i >= 0; i--)
    {
        while (h[i] > st.top().second)
            st.pop();
        after[i] = st.top().first;
        st.emplace(i, h[i]);
    }

    vector<ll> ans(Q);
    st = stack<pii>();
    st.emplace(-1, INT_MAX);
    for (int i = 0; i < N; i++)
    {
        while (h[i] >= st.top().second)
            st.pop();
        int before = st.top().first;
        for (int j = 0; j < Q; j++)
        {
            ll L = i - max(before, queries[j].first - 1);
            ll R = min(after[i], queries[j].second) - i;
            if (L > 0 && R > 0)
                ans[j] += L * R * h[i];
        }
        st.emplace(i, h[i]);
    }
    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}