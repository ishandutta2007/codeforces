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
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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
    int size;
    int pr, pc;
    int offset;
};

static void find(vector<vector<node> > &nodes, int &r, int &c, int &offset)
{
    int offset0 = offset;
    int r0 = r, c0 = c;
    while (nodes[r][c].pr != -1)
    {
        node &n = nodes[r][c];
        r = n.pr;
        c = n.pc;
        offset += n.offset;
    }

    int poffset = offset0;
    while (nodes[r0][c0].pr != -1)
    {
        node &n = nodes[r0][c0];
        r0 = n.pr;
        c0 = n.pc;
        int oldoffset = n.offset;
        n.pr = r;
        n.pc = c;
        n.offset = offset - poffset;
        poffset += oldoffset;
    }
}

static void merge(vector<vector<node> > &nodes, int r0, int c0, int r1, int c1, int offset)
{
    int offset0 = 0, offset1 = 0;
    find(nodes, r0, c0, offset0);
    find(nodes, r1, c1, offset1);
    if (r0 == r1 && c0 == c1)
        return;
    offset = offset + offset0 - offset1;
    if (nodes[r1][c1].size > nodes[r0][c0].size)
    {
        swap(r0, r1);
        swap(c0, c1);
        offset = -offset;
    }
    nodes[r0][c0].size += nodes[r1][c1].size;
    nodes[r1][c1].offset = offset;
    nodes[r1][c1].pr = r0;
    nodes[r1][c1].pc = c0;
}

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    redirect(argc, argv);
    int R, C, N;
    cin >> R >> C >> N;

    if (C == 1)
    {
        cout << "0\n";
        return 0;
    }

    vector<vector<node> > nodes(R, vector<node>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
        {
            node &n = nodes[r][c];
            n.size = 0;
            n.pr = -1;
            n.pc = -1;
            n.offset = 0;
        }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        map<pii, int> matches;
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
            {
                int ar = r + dr;
                int ac = c + dc;
                if (ar >= 0 && ar < R)
                {
                    if (ac >= C)
                        ac -= C;
                    if (ac < 0)
                        ac += C;

                    if (nodes[ar][ac].size > 0)
                    {
                        int offset = -dc;
                        find(nodes, ar, ac, offset);
                        pii key(ar, ac);
                        if (matches.count(key)
                            && matches[key] != offset)
                            goto bad;
                        matches[key] = offset;
                        if (C == 2 && dc != 0)
                            goto bad;
                    }
                }
            }

        nodes[r][c].size = 1;
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
            {
                int ar = r + dr;
                int ac = c + dc;
                if (ar >= 0 && ar < R)
                {
                    if (ac >= C)
                        ac -= C;
                    if (ac < 0)
                        ac += C;
                    if (nodes[ar][ac].size > 0)
                        merge(nodes, ar, ac, r, c, -dc);
                }
            }
        ans++;
        continue;

bad:;
        // cerr << "Failed " << i << " (" << r << ", " << c << ")\n";
    }
    cout << ans << '\n';

    return 0;
}