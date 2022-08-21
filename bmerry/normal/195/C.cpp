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
    cin >> N >> ws;

    stack<int> es;
    int th = -1;
    string tp;
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        replace(RA(line), '(', ' ');
        replace(RA(line), ')', ' ');
        replace(RA(line), ',', ' ');
        istringstream toks(line);

        string cmd;
        toks >> cmd;
        if (cmd == "try")
        {
            es.push(i);
        }
        else if (cmd == "throw")
        {
            toks >> tp;
            th = i;
        }
        else if (cmd == "catch")
        {
            string t;
            toks >> t;
            if (t == tp && es.top() < th)
            {
                string msg;
                getline(toks, msg);
                msg.erase(0, msg.find('"') + 1);
                msg.erase(msg.find('"'), msg.size());
                cout << msg << '\n';
                return 0;
            }
            es.pop();
        }
    }
    cout << "Unhandled Exception\n";

    return 0;
}