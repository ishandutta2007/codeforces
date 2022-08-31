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
#include <bitset>

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

typedef bitset<70001> bs;

static vector<bs> make_possible(const vector<pii> &A, int L, int R)
{
    vector<bs> ans;
    ans.reserve(R - L);
    bs cur;
    cur.set(0);

    if (L == 0)
        ans.push_back(cur);

    for (int i = 0; i + 1 < R; i++)
    {
        cur = cur | (cur << A[i].first);
        if (i + 1 >= L)
            ans.push_back(cur);
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, S;
    cin >> N >> S;
    vector<pii> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(RA(A));

    auto possible = make_possible(A, N - 1, N);

    if (S < A.back().first || !possible[0][S - A.back().first])
        cout << "-1\n";
    else
    {
        vector<int> used;
        used.push_back(N - 1);
        int cur = S - A.back().first;

        const int passes = 3;
        for (int pass = passes - 1; pass >= 0; pass--)
        {
            int L = pass * (N - 1) / passes;
            int R = (pass + 1) * (N - 1) / passes;
            auto sub = make_possible(A, L, R);
            for (int i = R - 1; i >= L && cur > 0; i--)
            {
                if (!sub[i - L][cur])
                {
                    used.push_back(i);
                    cur -= A[i].first;
                }
            }
        }
        assert(cur == 0);
        reverse(RA(used));

        vi direct(N);
        vector<vi> contain(N);
        vi perm(N);
        for (int i = 0; i < N; i++)
        {
            direct[i] = A[i].first;
            perm[A[i].second] = i;
        }

        int last = 0;
        for (auto u : used)
        {
            for (int i = last + 1; i <= u; i++)
            {
                direct[i] -= A[i - 1].first;
                contain[i].push_back(A[i - 1].second);
            }
            last = u + 1;
        }

        for (int i : perm)
        {
            cout << direct[i] << ' ' << contain[i].size();
            for (int j : contain[i])
                cout << ' ' << j + 1;
            cout << '\n';
        }
    }

    return 0;
}