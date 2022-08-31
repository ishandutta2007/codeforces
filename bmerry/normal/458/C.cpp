#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
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
    ios::sync_with_stdio(false);
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

class split
{
private:
    priority_queue<int, vector<int>, less<int> > inc;
    priority_queue<int, vector<int>, greater<int> > exc;
    ll sum_ = 0;

public:
    ll sum() const { return sum_; }
    int have() const { return inc.size(); }
    int size() const { return inc.size() + exc.size(); }

    void insert(int v)
    {
        inc.push(v);
        int out = inc.top();
        sum_ += v - out;
        inc.pop();
        exc.push(out);
    }

    bool incr()
    {
        if (exc.empty())
            return false;
        int v = exc.top();
        inc.push(v);
        exc.pop();
        sum_ += v;
        return true;
    }

    bool decr()
    {
        if (inc.empty())
            return false;
        int v = inc.top();
        exc.push(v);
        inc.pop();
        sum_ -= v;
        return true;
    }

    bool setto(int h)
    {
        if (h < 0 || h > size())
            return false;
        while (have() < h)
            incr();
        while (have() > h)
            decr();
        return true;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    int C = 100001;
    vector<vector<int> > bribe(C);
    split pool;
    int self = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
            self++;
        else
            bribe[a].push_back(b);
    }

    ll special = 0;
    int bs = 0;
    for (int i = 0; i < C; i++)
    {
        sort(RA(bribe[i]), greater<int>());
        special += accumulate(RA(bribe[i]), 0LL);
        bs += SZ(bribe[i]);
    }
    sort(bribe.begin() + 1, bribe.end(),
         [](const vi &p, const vi &q) { return p.size() > q.size(); });

    ll ans = LLONG_MAX;
    for (int allow = 0; ; allow++)
    {
        int need = max(0, allow + 1 - self - bs);
        if (need > SZ(pool))
            break;
        pool.setto(need);
        ans = min(ans, special + pool.sum());

        for (int i = 1; i < C; i++)
        {
            if (allow < SZ(bribe[i]))
            {
                bs--;
                special -= bribe[i][allow];
                pool.insert(bribe[i][allow]);
            }
            else
                break;
        }
    }

    cout << ans << '\n';

    return 0;
}