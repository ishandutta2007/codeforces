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
typedef pair<ll, int> pii;

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

#define BIG 314000000LL

struct rule
{
    int owner;
    vector<int> out;
    int term;
    ll D;
    ll minD, maxD;

    rule() : owner(-1), term(0), D(0), minD(0), maxD(-1) {}
};

struct monster
{
    vector<int> rules;
    vector<int> rrules;
    int term;
    ll minD, maxD;

    monster() : term(0), minD(LLONG_MAX / 2), maxD(-1) {}
};

static ll add(ll a, ll b)
{
    return min(a + b, BIG);
}

static int R, M;
static vector<monster> monsters;
static vector<rule> rules;

static bool safe(const rule &r)
{
    return r.term == SZ(r.out);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> R >> M;
    rules.resize(R);
    monsters.resize(M);
    for (int i = 0; i < R; i++)
    {
        int m, l;
        cin >> m >> l;
        m--;
        monster &cm = monsters[m];
        rule &cr = rules[i];
        cr.owner = m;
        cm.rules.push_back(i);
        for (int j = 0; j < l; j++)
        {
            int id;
            cin >> id;
            if (id == -1)
                cr.D++;
            else
            {
                id--;
                cr.out.push_back(id);
                monsters[id].rrules.push_back(i);
            }
        }
        cr.minD = cr.D;
        cr.maxD = cr.D;
    }

    priority_queue<pii> q;
    for (int r = 0; r < R; r++)
    {
        if (rules[r].out.empty())
            q.push(pii(-rules[r].D, -1 - r));
    }

    while (!q.empty())
    {
        if (q.top().second < 0)
        {
            int r = -1 - q.top().second;
            q.pop();
            rule &cr = rules[r];
            monster &cm = monsters[cr.owner];
            cm.term++;
            if (cm.term == 1)
            {
                cm.minD = cr.minD;
                q.push(pii(-cm.minD, cr.owner));
            }
        }
        else
        {
            int m = q.top().second;
            q.pop();
            monster &cm = monsters[m];
            for (int i = 0; i < SZ(cm.rrules); i++)
            {
                int r = cm.rrules[i];
                rule &cr = rules[r];
                cr.term++;
                cr.minD = add(cr.minD, cm.minD);
                if (cr.term == SZ(cr.out))
                    q.push(pii(-cr.minD, -1 - r));
            }
        }
    }

    for (int m = 0; m < M; m++)
        monsters[m].rrules.clear();
    for (int m = 0; m < M; m++)
    {
        monster &cm = monsters[m];
        vector<int> rules2;
        for (int j = 0; j < SZ(cm.rules); j++)
        {
            rule &cr = rules[cm.rules[j]];
            if (safe(cr))
            {
                rules2.push_back(cm.rules[j]);
                for (int k = 0; k < SZ(cr.out); k++)
                    monsters[cr.out[k]].rrules.push_back(cm.rules[j]);
            }
        }
        cm.rules.swap(rules2);
        cm.term = 0;
    }

    for (int r = 0; r < R; r++)
    {
        rule &cr = rules[r];
        cr.term = 0;
        if (rules[r].out.empty())
            q.push(pii(-rules[r].D, -1 - r));
    }

    while (!q.empty())
    {
        if (q.top().second < 0)
        {
            int r = -1 - q.top().second;
            q.pop();
            rule &cr = rules[r];
            monster &cm = monsters[cr.owner];
            cm.term++;
            cm.maxD = max(cm.maxD, cr.maxD);
            if (cm.term == SZ(cm.rules))
                q.push(pii(-cm.maxD, cr.owner));
        }
        else
        {
            int m = q.top().second;
            q.pop();
            monster &cm = monsters[m];
            for (int i = 0; i < SZ(cm.rrules); i++)
            {
                int r = cm.rrules[i];
                rule &cr = rules[r];
                cr.maxD = add(cr.maxD, cm.maxD);
                cr.term++;
                if (cr.term == SZ(cr.out))
                    q.push(pii(-cr.maxD, -1 - r));
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        const monster &cm = monsters[i];
        if (cm.minD == LLONG_MAX / 2)
            cout << "-1 -1\n";
        else
        {
            cout << cm.minD << ' ';
            if (cm.term == SZ(cm.rules))
                cout << cm.maxD;
            else
                cout << "-2";
            cout << '\n';
        }
    }

    return 0;
}