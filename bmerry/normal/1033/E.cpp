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
}

/*** TEMPLATE CODE ENDS HERE */

template<typename It>
static int query(It first, It last, int extra)
{
    int k = last - first + (extra != -1);
    if (k < 2)
        return 0;
    cout << "? " << k << endl;
    bool have = false;
    for (It i = first; i != last; ++i)
    {
        if (have)
            cout << ' ';
        have = true;
        cout << *i + 1;
    }
    if (extra != -1)
    {
        if (have)
            cout << ' ';
        have = true;
        cout << extra + 1;
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

template<typename It>
static int query2(It first, It last, It first2, It last2)
{
    int k = last - first + (last2 - first2);
    if (k < 2)
        return 0;
    cout << "? " << k << endl;
    bool have = false;
    for (It i = first; i != last; ++i)
    {
        if (have)
            cout << ' ';
        have = true;
        cout << *i + 1;
    }
    for (It i = first2; i != last2; ++i)
    {
        if (have)
            cout << ' ';
        have = true;
        cout << *i + 1;
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

static int query2(const vi &verts, int A, int B, int P, int Q)
{
    return query2(verts.begin() + A,
                  verts.begin() + B,
                  verts.begin() + P,
                  verts.begin() + Q);
}

static array<int, 2> find_cross(const vi &verts, int A, int B, int P, int Q)
{
    while (B - A > 1)
    {
        int mid = (A + B) / 2;
        int q = query2(verts, A, mid, P, Q);
        if (q)
            B = mid;
        else
            A = mid;
    }

    while (Q - P > 1)
    {
        int mid = (P + Q) / 2;
        int q = query2(verts, A, B, P, mid);
        if (q)
            Q = mid;
        else
            P = mid;
    }
    array<int, 2> ans{{verts[A], verts[P]}};
    return ans;
}

static array<int, 2> find_edge(const vi &verts, int first, int last, int total)
{
    assert(last - first > 1);
    int mid = (first + last) / 2;
    int left = query(verts.begin() + first, verts.begin() + mid, -1);
    if (left)
        return find_edge(verts, first, mid, left);
    int right = query(verts.begin() + mid, verts.begin() + last, -1);
    if (right)
        return find_edge(verts, mid, last, right);

    return find_cross(verts, first, mid, mid, last);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;

    vi sides[2];
    int done[2] = {0, 0};
    vi parent(N, -1);
    vi other;
    for (int i = 1; i < N; i++)
        other.push_back(i);
    sides[0].push_back(0);
    while (done[0] < SZ(sides[0]) || done[1] < SZ(sides[1]))
    {
        if (other.empty())
            break;
        int s = (done[0] < SZ(sides[0])) ? 0 : 1;
        assert(done[s] < SZ(sides[s]));
        stack<pii> todo;
        todo.emplace(0, SZ(other));
        int cur = sides[s][done[s]];
        vi new_other;
        while (!todo.empty())
        {
            pii task = todo.top();
            todo.pop();
            int e0 = query(other.begin() + task.first, other.begin() + task.second, -1);
            int e1 = query(other.begin() + task.first, other.begin() + task.second, cur);
            int e = e1 - e0;
            if (e == task.second - task.first)
            {
                for (int i = task.first; i < task.second; i++)
                {
                    sides[!s].push_back(other[i]);
                    parent[other[i]] = cur;
                }
            }
            else if (e == 0)
            {
                for (int i = task.first; i < task.second; i++)
                    new_other.push_back(other[i]);
            }
            else
            {
                int mid = (task.first + task.second) / 2;
                todo.emplace(task.first, mid);
                todo.emplace(mid, task.second);
            }
        }
        done[s]++;
        other = move(new_other);
    }

    for (int s = 0; s < 2; s++)
    {
        int total = query(RA(sides[s]), -1);
        if (total == 0)
            continue;
        array<int, 2> edge = find_edge(sides[s], 0, SZ(sides[s]), total);
        vi paths[2];
        for (int t = 0; t < 2; t++)
        {
            int x = edge[t];
            while (x != -1)
            {
                paths[t].push_back(x);
                x = parent[x];
            }
        }
        reverse(RA(paths[1]));
        int pos = 0;
        while (count(RA(paths[1]), paths[0][pos]) == 0)
            pos++;
        vi cycle(paths[0].begin(), paths[0].begin() + pos);
        pos = find(RA(paths[1]), paths[0][pos]) - paths[1].begin();
        cycle.insert(cycle.end(), paths[1].begin() + pos, paths[1].end());
        cout << "N " << SZ(cycle) << '\n';
        for (int v : cycle)
            cout << v + 1 << ' ';
        cout << endl;
        return 0;
    }

    cout << "Y " << SZ(sides[0]) << "\n";
    for (int v : sides[0])
        cout << v + 1 << ' ';
    cout << endl;

    return 0;
}