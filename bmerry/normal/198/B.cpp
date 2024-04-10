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

struct pqitem
{
    int h;
    int w;
    int prio;

    pqitem() {}
    pqitem(int h, int w, int prio) : h(h), w(w), prio(prio) {}

    bool operator<(const pqitem &b) const
    {
        return prio > b.prio;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int dh[3] = {-1, 1, 0};
    int dw[3] = {0, 0, 1};

    string walls[2];
    int N, K;
    cin >> N >> K >> walls[0] >> walls[1];
    dh[2] = K;

    vector<int> prio[2];
    prio[0].resize(N, INT_MAX);
    prio[1].resize(N, INT_MAX);
    prio[0][0] = 0;
    priority_queue<pqitem> q;
    q.push(pqitem(0, 0, 0));
    while (!q.empty())
    {
        pqitem cur = q.top();
        q.pop();
        if (prio[cur.w][cur.h] != cur.prio)
            continue;
        for (int i = 0; i < 3; i++)
        {
            int h2 = cur.h + dh[i];
            int w2 = cur.w ^ dw[i];
            int p2 = cur.prio + 1;
            if (h2 >= N)
            {
                cout << "YES\n";
                return 0;
            }
            if (h2 >= p2 && walls[w2][h2] == '-' && p2 < prio[w2][h2])
            {
                prio[w2][h2] = p2;
                q.push(pqitem(h2, w2, p2));
            }
        }
    }
    cout << "NO\n";
    return 0;
}