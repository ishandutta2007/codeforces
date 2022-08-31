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

static void clean(int cnt[], int mx, int slots)
{
    while (mx >= 0 && slots > 0)
    {
        int d = min(slots, cnt[mx]);
        cnt[mx] -= d;
        slots -= d;
        mx--;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    int musk[3];
    cin >> N >> musk[0] >> musk[1] >> musk[2];
    sort(musk, musk + 3);
    int buckets[7] =
    {
        musk[0], musk[1], musk[2],
        musk[0] + musk[1], musk[0] + musk[2], musk[1] + musk[2],
        musk[0] + musk[1] + musk[2]
    };
    sort(buckets, buckets + 7);
    int cnt[7] = {};
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        int b = 0;
        while (b < 7 && t > buckets[b])
            b++;
        if (b == 7)
        {
            cout << "-1\n";
            return 0;
        }
        cnt[b]++;
    }

    int ans = cnt[6] + cnt[5] + cnt[4] + cnt[3];
    if (musk[2] < musk[0] + musk[1])
    {
        clean(cnt, 0, cnt[5]);
        clean(cnt, 1, cnt[4]);
        clean(cnt, 2, cnt[3]);
        int best = INT_MAX;
        for (int r = 0; 2 * r <= cnt[2]; r++)
        {
            int x = cnt[0];
            int y = cnt[1];
            int z = cnt[2] - 2 * r;
            int score = r + max(max(z, (y + z + 1) / 2), (x + y + z + 2) / 3);
            best = min(best, score);
        }
        ans += best;
    }
    else
    {
        clean(cnt, 0, cnt[5]);
        clean(cnt, 1, cnt[4]);
        int best = INT_MAX;
        for (int r = 0; r <= cnt[2]; r++)
        {
            int s = cnt[2] - r;
            int u = cnt[3] + s - r;
            if (u < 0)
                break;
            int score = s;
            int nxt[2] = {cnt[0], cnt[1]};
            clean(nxt, 0, u);
            clean(nxt, 1, u);
            score += max((nxt[1] + 1) / 2, (nxt[0] + nxt[1] + 2) / 3);
            best = min(score, best);
        }
        ans += best;
    }
    cout << ans << '\n';
    return 0;
}