#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
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

struct worker
{
    int l, m, r;
};

struct ival
{
    int add = 0;
    int msub = 0;
    int msubid;
};

static void ival_add1(vector<ival> &iv, int A, int d)
{
    iv[A].add += d;
    while (A > 1)
    {
        A /= 2;
        int l = iv[2 * A].add + iv[2 * A].msub;
        int r = iv[2 * A + 1].add + iv[2 * A + 1].msub;
        if (l > r)
        {
            iv[A].msub = l;
            iv[A].msubid = iv[2 * A].msubid;
        }
        else
        {
            iv[A].msub = r;
            iv[A].msubid = iv[2 * A + 1].msubid;
        }
    }
}

static void ival_add(vector<ival> &iv, int A, int B, int d)
{
    A += iv.size() / 2;
    B += iv.size() / 2;
    while (A < B)
    {
        if (A & 1)
            ival_add1(iv, A++, d);
        if (B & 1)
            ival_add1(iv, --B, d);
        A >>= 1;
        B >>= 1;
    }
}

struct pqitem
{
    int time;
    int id;

    bool operator<(const pqitem &b) const
    {
        return time > b.time;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    vector<worker> workers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> workers[i].l >> workers[i].m >> workers[i].r;
    }

    vector<int> bym(N);
    iota(RA(bym), 0);
    sort(RA(bym), [&] (int a, int b) { return workers[a].m < workers[b].m; });

    int M = 524288;
    vector<ival> iv(2 * M);
    for (int i = M; i < 2 * M; i++)
        iv[i].msubid = i - M;
    for (int i = M - 1; i > 0; i--)
        iv[i].msubid = iv[2 * i].msubid;

    int ans = -1;
    int bestl = -1, bestr = -1;
    priority_queue<pqitem> expire;
    for (int ix = 0; ix < N; ix++)
    {
        int i = bym[ix];
        while (!expire.empty() && expire.top().time < workers[i].m)
        {
            int id = expire.top().id;
            ival_add(iv, workers[id].l, workers[id].m + 1, -1);
            expire.pop();
        }
        expire.push(pqitem{workers[i].r, i});
        ival_add(iv, workers[i].l, workers[i].m + 1, 1);
        if (iv[1].msub > ans)
        {
            ans = iv[1].msub;
            bestl = iv[1].msubid;
            bestr = workers[i].m;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < N; i++)
        if (workers[i].l <= bestl
            && workers[i].m >= bestl
            && workers[i].m <= bestr
            && workers[i].r >= bestr)
            cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}