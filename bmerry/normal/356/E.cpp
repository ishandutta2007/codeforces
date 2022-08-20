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
#include <tuple>

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

typedef pair<int, char> change;

static char get(
    const vector<vector<char> > &gray,
    const vector<vector<map<change, char> > > &changes,
    int level, int pos, change ch)
{
    int side = (1 << level) - 1;
    int left = pos - side;
    int right = pos + side;
    if (ch.first < left || ch.first > right)
        return gray[level][pos];
    else
    {
        auto p = changes[level][pos].find(ch);
        if (p == changes[level][pos].end())
            return 0;
        else
            return p->second;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    string str;
    int L;
    cin >> str;
    L = str.size();
    int N = 0;
    while ((1 << (N + 1)) - 1 <= L)
        N++;

    vector<ll> value(N);
    for (int i = 0; i < N; i++)
    {
        ll len = (1 << (i + 1)) - 1;
        value[i] = len * len;
    }

    vector<vector<char> > gray(N, vector<char>(L, '\0'));
    vector<vector<map<change, char> > > changes(N, vector<map<change, char> >(L));
    for (int i = 0; i < L; i++)
    {
        gray[0][i] = str[i];
        for (int j = 0; j < 26; j++)
            if ('a' + j != str[i])
                changes[0][i].insert(make_pair(change(i, 'a' + j), 'a' + j));
    }

    ll score = L;
    vector<ll> lose(L);
    vector<vector<ll> > gain(26, vector<ll>(L));
    for (int i = 1; i < N; i++)
    {
        const int side = (1 << i) - 1;
        const int step = 1 << (i - 1);
        for (int j = side; j < L - side; j++)
        {
            char left = gray[i - 1][j - step];
            char right = gray[i - 1][j + step];
            char mid = gray[i - 1][j];
            gray[i][j] = (left && mid && right
                && left == right && left != mid) ? str[j] : 0;
            for (int jump = -step; jump <= step; jump += step)
            {
                for (auto cx : changes[i - 1][j + jump])
                {
                    const change c = cx.first;
                    char l2 = get(gray, changes, i - 1, j - step, c);
                    char m2 = get(gray, changes, i - 1, j, c);
                    char r2 = get(gray, changes, i - 1, j + step, c);
                    if (l2 && m2 && r2 && l2 == r2 && l2 != m2)
                        changes[i][j].insert(make_pair(c, m2));
                }
            }
            if (gray[i][j])
            {
                score += value[i];
                for (int k = j - side; k <= j + side; k++)
                    lose[k] += value[i];
            }
            for (auto cx : changes[i][j])
                gain[cx.first.second - 'a'][cx.first.first] += value[i];
        }
    }

    ll ans = score;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < L; j++)
        {
            ll cur = score - lose[j] + gain[i][j];
            ans = max(ans, cur);
        }

    cout << ans << '\n';

    return 0;
}