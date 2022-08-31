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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<vector<double> > dist(N);
    double m = 0.0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        dist[i].resize(a + 1);
        dist[i][0] = 1.0;
        if (a == 0)
            m++;
    }

    int Q;
    cin >> Q;
    cout << fixed;
    cout.precision(12);
    for (int i = 0; i < Q; i++)
    {
        int u, v, k;
        cin >> u >> v >> k;
        u--;
        v--;
        int P = dist[u].size() - 1;
        vector<double> d2(P - k + 1);
        double choices = 1.0;
        for (int j = 1; j <= k; j++)
            choices *= (P - j + 1.0) / j;
        choices = 1.0 / choices;

        for (int j = 0; j <= k; j++)
            for (int l = k - j; l <= P - j; l++)
            {
                double s = choices;
                for (int x = 0; x < j; x++)
                    s *= (P - l - x) / (x + 1.0);
                for (int x = 0; x < k - j; x++)
                    s *= (l - x) / (x + 1.0);
                d2[l + j - k] += dist[u][l] * s;
            }
        m += d2.back() - dist[u].back();
        dist[u].swap(d2);

        P = dist[v].size() - 1;
        vector<double> d3(P + k + 1);
        for (int j = 0; j <= P; j++)
            d3[j + k] = dist[v][j];
        dist[v].swap(d3);
        cout << m << '\n';
    }

    return 0;
}