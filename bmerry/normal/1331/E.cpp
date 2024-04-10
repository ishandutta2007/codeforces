//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

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
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static vector<uint64_t> masks{205420232704ULL, 4300726075392ULL, 9943141842944ULL, 102772080771072ULL, 234260485308416ULL, 723091532955648ULL, 1929901949378560ULL, 7962145521006592ULL, 16163718647774208ULL, 36001995886165504ULL, 72057594037927680ULL, 144115188075855744ULL, 144115188075855744ULL, 288230376151711680ULL, 576460752303423456ULL, 576460752303423456ULL, 1152921504606846960ULL, 2305843009213693944ULL, 2305843009213693920ULL, 576412923518779264ULL, 71777768313191948ULL, 3466203809432795196ULL, 9079473177587753214ULL, 9206058851405956094ULL, 9220848794270097406ULL, 9197581204444447742ULL, 18414869574287814655ULL, 18420741636752033791ULL, 18426746848929380351ULL, 18415823286090401791ULL, 18437647845276217343ULL, 18413224286464100351ULL, 18420404737790451711ULL, 18444146654698651647ULL, 18438754119921373183ULL, 18444712607746252799ULL, 18442905914206388223ULL, 18446482373293113343ULL, 9222888249038077950ULL, 9223372004642521086ULL, 9223372024775180286ULL, 9223372034908618750ULL, 4611686010441433084ULL, 4611686017353644540ULL, 2296835806200851448ULL, 2271494263009059832ULL, 2292441381606829048ULL, 1150432316586299376ULL, 575754606495084512ULL, 575406797197246432ULL, 287974233452855232ULL, 144099394269413248ULL, 144050217612541824ULL, 72048513284964096ULL, 36027165100998144ULL, 18010923323096064ULL, 9005072994269184ULL, 2251791223742464ULL, 1125899906826240ULL, 281474976645120ULL, 140737488224256ULL, 17592184995840ULL, 4398042316800ULL, 274810798080ULL};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int r, c;
    cin >> r >> c;
    cout << (((masks[r] >> c) & 1) ? "IN\n" : "OUT\n");

    return 0;
}