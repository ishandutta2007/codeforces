// WRONG SOLUTION (TOO SLOW)

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

typedef complex<double> cplex;

static vector<cplex> coeff;  // coeff[k] is e^(2pi.i.k/R)

static void initialise_fft(int R)
{
    coeff.resize(R);
    for (int i = 0; i < R; i++)
        coeff[i] = exp(cplex(0, 2 * M_PI * i / R));
}

/* Does in-place FFT of [a, a + R), using tmp as temporary storage */
static void fft(cplex *a, cplex *tmp, int R)
{
    int stride = coeff.size() / R;
    int ind = 0;

    if (R == 1) return; /* Base level of recursion */
    int h = R / 2;
    /* Split into even and odd terms */
    for (int i = 0; i < h; i++)
    {
        tmp[i] = a[2 * i];
        tmp[i + h] = a[2 * i + 1];
    }
    fft(tmp, a, h);        // FFT of the even terms
    fft(tmp + h, a, h);    // FFT of the odd terms

    /* Reassemble */
    for (int i = 0; i < h; i++)
    {
        a[i] = tmp[i] + coeff[ind] * tmp[i + h];
        a[i + h] = tmp[i] - coeff[ind] * tmp[i + h];
        ind += stride;
    }
}

static vector<int> convolve(const vector<int> &a, const vector<int> &b)
{
    int R = 1;
    while (R < SZ(a) + SZ(b))
        R *= 2;
    initialise_fft(R);

    vector<cplex> siga(R), sigb(R), tmp(R);
    copy(RA(a), siga.begin());
    copy(RA(b), sigb.begin());
    fft(&siga[0], &tmp[0], R);
    fft(&sigb[0], &tmp[0], R);
    for (int i = 0; i < R; i++)
        siga[i] = conj(siga[i] * sigb[i]);
    fft(&siga[0], &tmp[0], R);

    vector<int> ans(SZ(a) + SZ(b) - 1);
    for (int i = 0; i < SZ(ans); i++)
        ans[i] = int(round(siga[i].real() / R));
    return ans;
}

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;

    vector<int> is_bag(M + 1);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        is_bag[a] = 1;
    }

    vector<int> P;
    vector<int> conv = convolve(is_bag, is_bag);
    conv.resize(M + 1);
    for (int i = 1; i <= M; i++)
    {
        if (conv[i] && !is_bag[i])
            goto NO;
        else if (!conv[i] && is_bag[i])
            P.push_back(i);
    }

    cout << "YES\n" << P.size() << '\n';
    for (int i = 0; i < SZ(P); i++)
    {
        if (i)
            cout << ' ';
        cout << P[i];
    }
    cout << '\n';
    return 0;

NO:
    cout << "NO\n";
    return 0;
}