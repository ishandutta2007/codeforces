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

static void euler(vector<vector<pii> > &edges, int cur, vector<int> &out)
{
    int last = -1;
    for (int i = 0; i < SZ(edges[cur]); i++)
    {
        pii &e = edges[cur][i];
        if (e.first != -1)
        {
            last = e.first;
            e.first = -1;
            euler(edges, e.second, out);
            out.push_back(last);
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    if (N & 1)
    {
        cout << "-1\n";
    }
    else
    {
        int M = N / 2;
        vector<vector<pii> > edges(M);
        for (int i = 0; i < M; i++)
        {
            if (i != 0)
                edges[i].push_back(pii(2 * i, 2 * i % M));
            edges[i].push_back(pii(2 * i + 1, (2 * i + 1) % M));
        }

        vi order;
        euler(edges, 0, order);
        reverse(RA(order));
        cout << "0";
        for (int i = 0; i < SZ(order); i++)
            cout << ' ' << order[i];
        cout << " 0\n";
    }

    return 0;
}