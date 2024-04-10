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
    int child[2] = {-1, -1};
    int fail = -2;
    int end_of = -1;
};

static bool augment(const vector<vector<bool> > &edges, vector<int> &back, vector<bool> &done, int x)
{
    if (x == -1)
        return true;
    if (done[x])
        return false;
    done[x] = true;
    for (int y = 0; y < SZ(edges[x]); y++)
        if (edges[x][y])
        {
            int old = back[y];
            back[y] = x;
            if (augment(edges, back, done, old))
                return true;
            back[y] = old;
        }
    return false;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<string> words;
    words.resize(N);
    int maxL = 0;
    vector<node> nodes(1);
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
        maxL = max(maxL, SZ(words[i]));
        int cur = 0;
        for (int j = 0; j < SZ(words[i]); j++)
        {
            int &sub = nodes[cur].child[words[i][j] - 'a'];
            int next = sub;
            if (sub == -1)
            {
                sub = SZ(nodes);
                next = sub;
                nodes.push_back(node());
            }
            cur = next;
        }
        nodes[cur].end_of = i;
    }
    nodes[0].fail = -1;
    vector<int> level{0};
    vector<int> suffix(N, -1);
    while (!level.empty())
    {
        vector<int> nlevel;
        for (int idx : level)
        {
            for (int s = 0; s < 2; s++)
            {
                int child = nodes[idx].child[s];
                if (child != -1)
                {
                    int f = nodes[idx].fail;
                    while (f != -1 && nodes[f].child[s] == -1)
                        f = nodes[f].fail;
                    if (f == -1)
                        f = 0;
                    else
                        f = nodes[f].child[s];
                    nodes[child].fail = f;
                    nlevel.push_back(child);
                    if (nodes[child].end_of == -1)
                        nodes[child].end_of = nodes[f].end_of;
                    else
                        suffix[nodes[child].end_of] = nodes[f].end_of;
                }
            }
        }
        level = move(nlevel);
    }

    vector<vector<bool> > edges(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
    {
        int cur = 0;
        for (char ch : words[i])
        {
            int e = nodes[cur].end_of;
            while (e != -1 && !edges[i][e])
            {
                edges[i][e] = true;
                e = suffix[e];
            }
            cur = nodes[cur].child[ch - 'a'];
        }
        int e = suffix[i];
        while (e != -1 && !edges[i][e])
        {
            edges[i][e] = true;
            e = suffix[e];
        }
    }

    int flow = 0;
    vi back(N, -1);
    vector<bool> matched(N);
    for (int i = 0; i < N; i++)
    {
        vector<bool> done(N);
        if (augment(edges, back, done, i))
        {
            flow++;
            matched[i] = true;
        }
    }

    vector<bool> lreach(N), rreach(N);
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (!matched[i])
        {
            lreach[i] = true;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < N; i++)
            if (edges[cur][i] && !rreach[i] && back[i] != cur)
            {
                rreach[i] = true;
                lreach[back[i]] = true;
                q.push(back[i]);
            }
    }
    vector<int> anti;
    for (int i = 0; i < N; i++)
    {
        if (lreach[i] && !rreach[i])
            anti.push_back(i);
    }

    int ans = N - flow;
    cout << ans << '\n';
    for (int i = 0; i < SZ(anti) - 1; i++)
        cout << anti[i] + 1 << ' ';
    cout << anti.back() + 1 << '\n';

    return 0;
}