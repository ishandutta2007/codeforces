// WRONG SOLUTION

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
    ios::sync_with_stdio(false);
    redirect(argc, argv);
    int N, T;
    cin >> N;
    vector<int> P(N + 1);
    vector<bool> forced(N + 1);
    for (int i = 0; i < N; i++)
        cin >> P[i];
    P[N] = -1;
    forced[N] = true;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int q;
        cin >> q;
        q--;
        forced[q] = true;
    }

    vector<pii> st;
    st.push_back(pii(-1, -1));
    for (int i = 0; i <= N; i++)
    {
        int p = P[i];
        if (!forced[i])
            st.push_back(pii(i, p));
        else
        {
            vector<pii> todo;
            todo.push_back(pii(i, p));
            while (!todo.empty())
            {
                if (st.empty())
                    goto NO;
                else if (st.back().second == todo.back().second)
                {
                    st.pop_back();
                    todo.pop_back();
                }
                else
                {
                    if (st.back().first < 0)
                        goto NO;
                    forced[st.back().first] = true;
                    todo.push_back(st.back());
                    st.pop_back();
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        if (i) cout << ' ';
        cout << (forced[i] ? -P[i] : P[i]);
    }
    cout << '\n';
    return 0;

NO:
    cout << "NO\n";
    return 0;
}