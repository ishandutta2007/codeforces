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

struct Answer
{
    int value;

    explicit Answer(int value) : value(value) {}
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    mt19937 engine;
    for (int cas = 0; cas < T; cas++)
    {
        int h, N;
#ifdef SIM
        h = 7;
        N = (1 << h) - 1;
        vector<int> perm(N);
        for (int i = 0; i < N; i++)
            perm[i] = i;
        shuffle(perm.begin(), perm.end(), engine);
        vector<vector<int>> redge(N);
        for (int i = 1; i < N; i++)
        {
            int a = perm[i];
            int b = perm[(i - 1) / 2];
            redge[a].push_back(b);
            redge[b].push_back(a);
        }
        for (int i = 0; i < N; i++)
            sort(RA(redge[i]));
#else
        cin >> h;
        N = (1 << h) - 1;
#endif
        int queries = 0;
        vector<vector<int>> edge(N);
        vector<int> chain;
        auto query = [&] (int x) {
            if (edge[x].empty())
            {
                queries++;
                int k;
#ifdef SIM
                k = SZ(redge[x]);
                edge[x] = redge[x];
#else
                cout << "? " << x + 1 << endl;
                cin >> k;
                for (int i = 0; i < k; i++)
                {
                    int v;
                    cin >> v;
                    edge[x].push_back(v - 1);
                }
#endif
                if (k == 2)
                    throw Answer(x);
            }
        };

        auto step = [&] (int x, int prev) {
            int idx = 0;
            if (edge[x][idx] == prev)
                idx++;
            return edge[x][idx];
        };

        try
        {
            chain.push_back(0);
            query(0);
            for (int pass = 0; pass < 2; pass++)
            {
                while (edge[chain.back()].size() == 3)
                {
                    int prev = SZ(chain) >= 2 ? chain[SZ(chain) - 2] : -1;
                    chain.push_back(step(chain.back(), prev));
                    query(chain.back());
                }
                reverse(RA(chain));
            }
            int lvl = SZ(chain) / 2;
            int top = chain[lvl];
            int up = -1;
            for (int e : edge[top])
                if (!count(RA(chain), e))
                    up = e;
            while (lvl < 3 && lvl < h - 2)
            {
                query(up);
                int cur = up;
                int prev = top;
                int trial = step(up, top);
                for (int i = 0; i <= lvl; i++)
                {
                    int nxt = step(cur, prev);
                    query(nxt);
                    prev = cur;
                    cur = nxt;
                }
                if (SZ(edge[cur]) == 1)
                    trial = accumulate(RA(edge[up]), 0) - top - trial;
                top = up;
                up = trial;
                lvl++;
            }
            vector<int> cand{up};
            vector<bool> done(N);
            done[top] = true;
            for (int i = 0; i < h - 2 - lvl; i++)
            {
                vector<int> cand2;
                for (int v : cand)
                {
                    query(v);
                    done[v] = true;
                    for (int e : edge[v])
                        if (!done[e])
                            cand2.push_back(e);
                }
                cand = move(cand2);
            }
            for (int i = 0; i < SZ(cand) - 1; i++)
                query(cand[i]);
            throw Answer(cand.back());
        }
        catch (Answer &ans)
        {
            cout << "! " << ans.value + 1 << endl;
            assert(queries <= 16);
#ifdef SIM
            assert(ans.value == perm[0]);
#endif
        }
    }

    return 0;
}