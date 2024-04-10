// WRONG ANSWER

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
    ll T;
    cin >> N >> T;
    string road;
    cin >> road;
    vector<int> houses, shops;
    for (int i = 0; i < N; i++)
        if (road[i] == 'H')
            houses.push_back(i);
        else if (road[i] == 'S')
            shops.push_back(i);

    if (houses.back() >= T)
    {
        cout << "-1\n";
        return 0;
    }

    int low = max(-1, SZ(houses) - SZ(shops) - 1);
    int high = houses.size();
    int H = SZ(houses);
    int S = SZ(shops);
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        int k = mid;
        ll t = 0;
        int ns = 0;
        int pos = -1;
        int end = houses.back();
        if (mid < H)
            end = max(end, shops[H - mid - 1]);
        ll tt = LLONG_MAX;
        for (int i = 0; i < SZ(houses); i++)
        {
            t += houses[i] - pos;
            pos = houses[i];
            tt = min(tt, t + 2 * (end - pos));
            while (ns < S && shops[ns] < pos)
            {
                k++;
                ns++;
            }
            k--;
            if (k < 0)
            {
                int h = i + 1;
                int d = k;
                while (d < 0)
                {
                    while (h < H && houses[h] < shops[ns])
                    {
                        d--;
                        h++;
                    }
                    d++;
                    ns++;
                    k++;
                }
                t += 2 * (shops[ns - 1] - pos);
            }
        }
        tt = min(tt, t);
        if (tt <= T)
            high = mid;
        else
            low = mid;
    }
    cout << high << '\n';

    return 0;
}