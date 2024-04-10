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

struct node
{
    int idx = -1;
    int end;
    int parent = -1;
    int next_child = 0;
};

struct entry
{
    ll mask = 0;
    ll force = 0;
};

static void push_down(vector<entry> &entries, int idx)
{
    if (idx * 2 < SZ(entries) && entries[idx].force)
    {
        entries[2 * idx] = entries[idx];
        entries[2 * idx + 1] = entries[idx];
        entries[idx].force = 0;
    }
}

static void set_color(vector<entry> &entries, int idx, int A, int B, int L, int R, ll force)
{
    L = max(L, A);
    R = min(R, B);
    if (L >= R)
        return;
    else if (L == A && R == B)
        entries[idx].mask = entries[idx].force = force;
    else
    {
        push_down(entries, idx);
        int M = (A + B) / 2;
        set_color(entries, 2 * idx, A, M, L, R, force);
        set_color(entries, 2 * idx + 1, M, B, L, R, force);
        entries[idx].mask = entries[2 * idx].mask | entries[2 * idx + 1].mask;
    }
}

static ll get_colors(vector<entry> &entries, int idx, int A, int B, int L, int R)
{
    L = max(L, A);
    R = min(R, B);
    if (L >= R)
        return 0LL;
    else if (L == A && R == B)
        return entries[idx].mask;
    else if (entries[idx].force)
        return entries[idx].force;
    else
    {
        int M = (A + B) / 2;
        return get_colors(entries, 2 * idx, A, M, L, R)
            |  get_colors(entries, 2 * idx + 1, M, B, L, R);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vi> edges(N);
    vector<int> icolors(N);
    for (int i = 0; i < N; i++)
        cin >> icolors[i];
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int pool = 0;
    vector<node> nodes(N);
    stack<int> st;
    st.push(0);
    while (!st.empty())
    {
        int cur = st.top();
        node &n = nodes[cur];
        if (n.idx == -1)
            n.idx = pool++;
        if (n.next_child == SZ(edges[cur]))
        {
            n.end = pool;
            st.pop();
        }
        else
        {
            int child = edges[cur][n.next_child++];
            if (child != n.parent)
            {
                nodes[child].parent = cur;
                st.push(child);
            }
        }
    }

    int bias = 1;
    while (bias < N)
        bias <<= 1;
    vector<entry> entries(2 * bias);
    for (int i = 0; i < N; i++)
        set_color(entries, 1, 0, N, nodes[i].idx, nodes[i].idx + 1, 1LL << icolors[i]);
    for (int i = 0; i < M; i++)
    {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1)
        {
            int c;
            cin >> c;
            set_color(entries, 1, 0, N, nodes[v].idx, nodes[v].end, 1LL << c);
        }
        else
        {
            ll p = get_colors(entries, 1, 0, N, nodes[v].idx, nodes[v].end);
            cout << __builtin_popcountll(p) << '\n';
        }
    }
    return 0;
}