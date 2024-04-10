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

struct bug
{
    int id;
    int lvl;

    bool operator<(const bug &b) const
    {
        return lvl > b.lvl;
    }
};

struct stud
{
    int id;
    int lvl;
    int cost;

    bool operator<(const stud &b) const
    {
        return lvl > b.lvl;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, M;
    ll S;
    cin >> N >> M >> S;
    vector<stud> studs(N);
    vector<bug> bugs(M);
    for (int i = 0; i < M; i++)
    {
        cin >> bugs[i].lvl;
        bugs[i].id = i;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> studs[i].lvl;
        studs[i].id = i;
    }
    for (int i = 0; i < N; i++)
        cin >> studs[i].cost;

    sort(RA(bugs));
    sort(RA(studs));

    int lo = 0;
    int hi = M + 2;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        int pos = 0;
        priority_queue<int, vector<int>, greater<int> > avail;
        ll tcost = 0;
        for (int i = 0; i < M; i += mid)
        {
            while (pos < N && studs[pos].lvl >= bugs[i].lvl)
            {
                avail.push(studs[pos].cost);
                pos++;
            }
            if (avail.empty())
                goto bad;
            tcost += avail.top();
            avail.pop();
            if (tcost > S)
                goto bad;
        }
        hi = mid;
        continue;

bad:
        lo = mid;
    }

    if (hi > M)
    {
        cout << "NO\n";
        return 0;
    }

    vector<int> who(M);
    {
        int mid = hi;
        priority_queue<pii, vector<pii>, greater<pii> > avail;
        int pos = 0;
        for (int i = 0; i < M; i += mid)
        {
            while (pos < N && studs[pos].lvl >= bugs[i].lvl)
            {
                avail.emplace(studs[pos].cost, studs[pos].id);
                pos++;
            }
            for (int j = i; j < M && j < i + mid; j++)
                who[bugs[j].id] = avail.top().second;
            avail.pop();
        }
    }

    cout << "YES\n";
    for (int i = 0; i < M; i++)
        cout << who[i] + 1 << ' ';
    cout << '\n';

    return 0;
}