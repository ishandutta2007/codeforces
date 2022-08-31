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

struct exhibit
{
    int value;
    int weight;
};

struct event
{
    int idx;
    bool add;
};

static void knap_add(vi &knap, int v, int w)
{
    for (int i = SZ(knap) - 1; i >= w; i--)
        knap[i] = max(knap[i], knap[i - w] + v);
}

static void knap_add(vi &knap, const exhibit &e)
{
    knap_add(knap, e.value, e.weight);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K, Q;
    cin >> N >> K;
    vector<exhibit> ex(N);
    for (int i = 0; i < N; i++)
        cin >> ex[i].value >> ex[i].weight;
    cin >> Q;
    vi qtime;
    vector<event> events;
    vi added(N, -1);
    vi removed(N, INT_MAX);
    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            added.push_back(SZ(events));
            removed.push_back(INT_MAX);
            events.push_back(event{SZ(ex), true});
            ex.emplace_back();
            cin >> ex.back().value >> ex.back().weight;
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            x--;
            removed[x] = SZ(events);
            events.push_back(event{x, false});
        }
        else
            qtime.push_back(SZ(events));
    }

    vector<vi> knaps;
    knaps.push_back(vi(K + 1));
    for (int i = 0; i < N; i++)
        if (removed[i] == INT_MAX)
            knap_add(knaps[0], ex[i]);

    int step = 1;
    int E = SZ(events);
    while (step <= E)
        step <<= 1;
    for (step >>= 1; step >= 1; step >>= 1)
    {
        vector<vi> knaps2;
        for (int start = 0; start <= E; start += 2 * step)
        {
            int mid = min(start + step, E);
            int end = min(mid + step, E);
            vi &back = knaps[start / (2 * step)];
            vi front = back;
            for (int i = mid; i < end; i++)
                if (!events[i].add && added[events[i].idx] < start)
                    knap_add(front, ex[events[i].idx]);
            knaps2.push_back(move(front));
            for (int i = start; i < mid; i++)
                if (events[i].add && removed[events[i].idx] >= end)
                    knap_add(back, ex[events[i].idx]);
            knaps2.push_back(move(back));
        }
        knaps = move(knaps2);
    }
    for (int i = 0; i < E; i++)
        if (!events[i].add)
            knap_add(knaps[i], ex[events[i].idx]);

    constexpr ll P = 10000019;
    constexpr ll MOD = 1000000007;
    for (int time : qtime)
    {
        ll sum = 0;
        ll pp = 1;
        for (int i = 1; i <= K; i++)
        {
            sum = (sum + knaps[time][i] * pp) % MOD;
            pp = pp * P % MOD;
        }
        cout << sum << '\n';
    }

    return 0;
}