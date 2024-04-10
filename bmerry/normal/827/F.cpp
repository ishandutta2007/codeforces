// TIME LIMIT EXCEEDED

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
typedef vector<int> vi;
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

struct passage
{
    int a, b;
    int l, r, s;
};

enum event_type
{
    ARRIVE, OPEN, CLOSE, CHECK
};

struct event
{
    event_type type;
    int pos;
    int time;

    bool operator<(const event &other) const
    {
        if (time != other.time)
            return time > other.time;
        else
            return type > other.type;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    if (N == 1)
    {
        cout << "0\n";
        return 0;
    }
    M *= 4;
    N *= 2;
    vector<passage> pass(M);
    vector<vi> links(N);
    vector<int> out_deg(N);
    for (int i = 0; i < M; i += 4)
    {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        a--; a *= 2;
        b--; b *= 2;
        pass[i].a = a;
        pass[i].b = b + 1;
        pass[i + 1].a = b;
        pass[i + 1].b = a + 1;
        pass[i + 2].a = a + 1;
        pass[i + 2].b = b;
        pass[i + 3].a = b + 1;
        pass[i + 3].b = a;
        for (int j = i; j < i + 2; j++)
        {
            pass[j].l = (l + 1) & ~1;
            pass[j].r = r & ~1;
            pass[j].s = (r + 1) & ~1;
        }
        for (int j = i + 2; j < i + 4; j++)
        {
            pass[j].l = l | 1;
            pass[j].r = (r - 1) | 1;
            pass[j].s = r | 1;
        }
    }

    priority_queue<event> events;
    for (int i = 0; i < M; i++)
    {
        events.push(event{OPEN, i, pass[i].l});
        events.push(event{CLOSE, i, pass[i].r});
    }
    events.push(event{ARRIVE, 0, 0});
    events.push(event{CHECK, 0, 0});
    vector<int> reach(N);
    int ans = INT_MAX;
    while (!events.empty())
    {
        event cur = events.top();
        events.pop();
        int t = cur.time;
        if (cur.type == ARRIVE)
        {
            if (!reach[cur.pos])
            {
                reach[cur.pos] = true;
                if (cur.pos == N - 1 || cur.pos == N - 2)
                    ans = min(ans, t);
                int i = 0;
                while (i < SZ(links[cur.pos]))
                {
                    int &s = links[cur.pos][i];
                    assert(pass[s].l < t);
                    if (pass[s].s <= t)
                    {
                        s = links[cur.pos].back();
                        links[cur.pos].pop_back();
                    }
                    else
                    {
                        if (!reach[pass[s].b])
                            events.push(event{ARRIVE, pass[s].b, t + 1});
                        i++;
                    }
                }
                //events.push(event{CHECK, cur.pos, t});
            }
        }
        else if (cur.type == OPEN)
        {
            int v = pass[cur.pos].a;
            if (reach[v] && !reach[pass[cur.pos].b] && pass[cur.pos].s > t)
                events.push(event{ARRIVE, pass[cur.pos].b, t + 1});
            out_deg[v]++;
            links[v].push_back(cur.pos);
        }
        else if (cur.type == CLOSE)
        {
            int v = pass[cur.pos].a;
            if (0 == --out_deg[v])
                reach[v] = false;
        }
        else if (cur.type == CHECK)
        {
            if (out_deg[cur.pos] == 0)
                reach[cur.pos] = false;
        }
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';

    return 0;
}