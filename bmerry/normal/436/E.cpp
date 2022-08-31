// WRONG ANSWER ON PRETEST 10

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

struct level
{
    int a;
    int b;
    int idx;

    bool operator<(const level &other) const
    {
        return b < other.b;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, W;
    cin >> N >> W;
    vector<level> levels;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        levels.push_back(level{a, b, i});
    }
    sort(RA(levels));

    ll best = LLONG_MAX;
    int besti = -1;
    for (int pass = 0; pass < 2; pass++)
    {
        set<pii> step;
        for (int i = 0; i < N; i++)
            step.insert(pii(levels[i].a, i));
        ll score = 0;
        int pos = min(W, N);
        auto ptr = step.begin();
        for (int i = 0; i < pos; i++)
        {
            score += ptr->first;
            ptr++;
        }

        for (int i = 0; i <= min(W, N); i++)
        {
            if (pass == 1 && i == besti)
            {
                assert(score == best);
                assert(pos == W - i);
                assert(distance(step.begin(), ptr) == pos);
                cout << best << '\n';
                string t(N, '0');
                for (int j = 0; j < i; j++)
                    t[levels[j].idx] = '1';
                for (auto j = step.begin(); j != ptr; ++j)
                    t[levels[j->second].idx]++;
                cout << t << '\n';
                return 0;
            }
            if (pos == W - i && score < best)
            {
                best = score;
                besti = i;
            }

            if (i == min(W, N))
                break;
            score += levels[i].a;
            pii del(levels[i].a, i);
            pii add(levels[i].b - levels[i].a, i);
            if (ptr == step.end() || del < *ptr)
            {
                score -= del.first;
                pos--;
            }
            if (ptr == step.end() || add < *ptr)
            {
                score += add.first;
                pos++;
            }
            if (ptr != step.end() && *ptr == del)
                ++ptr;
            step.erase(del);
            step.insert(add);
            while (pos > W - (i + 1))
            {
                --ptr;
                --pos;
                score -= ptr->first;
            }
            while (ptr != step.end() && pos < W - (i + 1))
            {
                score += ptr->first;
                ++ptr;
                ++pos;
            }
        }
    }

    return 0;
}