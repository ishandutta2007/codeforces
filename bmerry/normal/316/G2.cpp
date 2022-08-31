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
#include <tr1/unordered_set>

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
    vector<ull> valid;
    vector<ull> invalid;
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
    }

    ll total = 0;
    ull sub = 1;
    for (int len = 1; len <= SZ(s); len++, sub *= 37)
    {
        for (int i = 0; i < N; i++)
        {
            rules[i].valid.clear();
            rules[i].invalid.clear();

            int L = SZ(rules[i].p);
            vector<ull> hashes;
            hashes.reserve(L);

            ull h = 0;
            const string &p = rules[i].p;

            for (int a = 0; a < min(L, len - 1); a++)
                h = h * 37 + p[a] - 'a';
            for (int a = len - 1; a < L; a++)
            {
                h = h * 37 + p[a] - 'a';
                hashes.push_back(h);
                h -= sub * (p[a - len + 1] - 'a');
            }
            sort(RA(hashes));
            int a = 0;
            while (a < SZ(hashes))
            {
                int b = a + 1;
                ull h = hashes[a];
                while (b < SZ(hashes) && hashes[b] == h)
                    b++;
                if (b - a >= rules[i].l && b - a <= rules[i].r)
                    rules[i].valid.push_back(h);
                else
                    rules[i].invalid.push_back(h);
                a = b;
            }
        }

        unordered_set<ull> ans;
        ull h = 0;
        for (int a = 0; a < len - 1; a++)
            h = h * 37 + s[a] - 'a';
        for (int a = len - 1; a < SZ(s); a++)
        {
            h = h * 37 + s[a] - 'a';
            bool good = true;
            for (int i = 0; i < N && good; i++)
            {
                if (!binary_search(RA(rules[i].valid), h))
                {
                    if (binary_search(RA(rules[i].invalid), h))
                        good = false;
                    else
                        good = rules[i].l == 0;
                }
            }
            if (good)
                ans.insert(h);
            h -= sub * (s[a - len + 1] - 'a');
        }
        total += SZ(ans);
    }
    cout << total << '\n';

    return 0;
}