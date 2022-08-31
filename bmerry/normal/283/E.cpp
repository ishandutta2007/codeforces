#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SZ(x) (int((x).size()))
#define RA(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

struct node
{
    bool flip;
    int on;

    node() : flip(false), on(0) {}
};

static int do_flip(vector<vector<node> > &nodes, int level, int p, int a, int b, int l, int r)
{
    node &n = nodes[level][p];
    int size = b - a;

    l = max(l, a);
    r = min(r, b);
    if (r <= a || l >= b)
        return n.on;
    else if (l == a && r == b)
    {
        n.flip = !n.flip;
        n.on = size - n.on;
    }
    else
    {
        int m = (a + b) / 2;
        n.on = do_flip(nodes, level + 1, 2 * p, a, m, l, r)
             + do_flip(nodes, level + 1, 2 * p + 1, m, b, l, r);
        if (n.flip)
            n.on = size - n.on;
    }
    return n.on;
}

static void do_flip(vector<vector<node> > &nodes, int l, int r)
{
    do_flip(nodes, 0, 0, 0, nodes.back().size(), l, r);
}

static int count(const vector<vector<node> > &nodes, int level, int p, int a, int b, int l, int r)
{
    const node &n = nodes[level][p];

    l = max(l, a);
    r = min(r, b);
    if (r <= a || l >= b)
        return 0;
    else if (l == a && r == b)
        return n.on;
    else
    {
        int m = (a + b) / 2;
        int on = count(nodes, level + 1, 2 * p, a, m, l, r)
            +    count(nodes, level + 1, 2 * p + 1, m, b, l, r);
        if (n.flip)
            on = (r - l) - on;
        return on;
    }
}

static int count(const vector<vector<node> > &nodes, int l, int r)
{
    return count(nodes, 0, 0, 0, nodes.back().size(), l, r);
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> skills(N);
    for (int i = 0; i < N; i++)
        cin >> skills[i];
    sort(RA(skills));

    vector<vector<pii> > flips(N + 1);
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        int p = lower_bound(RA(skills), a) - skills.begin();
        int q = upper_bound(RA(skills), b) - skills.begin();
        if (p < q)
        {
            flips[p].push_back(pii(p, q));
            flips[q].push_back(pii(p, q));
        }
    }

    vector<vector<node> > nodes;
    nodes.push_back(vector<node>(1));
    while (SZ(nodes.back()) < N)
    {
        nodes.push_back(vector<node>(nodes.back().size() * 2));
    }

    ll angles = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < SZ(flips[i]); j++)
            do_flip(nodes, flips[i][j].first, flips[i][j].second);
        ll wins = count(nodes, 0, i) + (N - 1 - i) - count(nodes, i + 1, N);
        ll losses = N - 1 - wins;
        angles += wins * losses;
    }

    angles -= (ll) N * (N - 1) * (N - 2) / 6;
    angles /= 2;
    cout << angles << '\n';
}