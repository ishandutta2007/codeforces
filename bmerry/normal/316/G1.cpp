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
#include <tr1/unordered_map>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;
using namespace std::tr1;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;
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

struct rule
{
    string p;
    int l, r;
    unordered_map<ull, ll> freq;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string s;
    int N;
    cin >> s >> N;
    vector<rule> rules(N);
    for (int i = 0; i < N; i++)
    {
        cin >> rules[i].p >> rules[i].l >> rules[i].r;
        unordered_map<ull, ll> &freq = rules[i].freq;
        for (int a = 0; a < SZ(rules[i].p); a++)
        {
            ull h = 97;
            for (int b = a; b < SZ(rules[i].p); b++)
            {
                h = h * 37 + rules[i].p[b] - 'a';
                freq[h]++;
            }
        }
    }

    set<ull> ans;
    for (int a = 0; a < SZ(s); a++)
    {
        ull h = 97;
        for (int b = a; b < SZ(s); b++)
        {
            h = h * 37 + s[b] - 'a';
            bool good = true;
            for (int i = 0; i < N && good; i++)
            {
                unordered_map<ull, ll>::const_iterator pos = rules[i].freq.find(h);
                if (pos == rules[i].freq.end())
                    good = rules[i].l == 0;
                else
                    good = pos->second >= rules[i].l && pos->second <= rules[i].r;
            }
            if (good)
                ans.insert(h);
        }
    }
    cout << SZ(ans) << '\n';

    return 0;
}