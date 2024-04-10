#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk
#define endl '\n'

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void print(pt x)
{
    cout << char('a' + x.first) << 1 + x.second;
}

void print_move(pt x, pt y)
{
    print(x);
    cout << "-";
    print(y);
    cout << endl;
}

bool good(pt x)
{
    return x.x >= 0 && x.x < 8 && x.y >= 0 && x.y < 8;
}

pt operator +(const pt& a, const pt& b)
{
    return mp(a.x + b.x, a.y + b.y);
}

int f[8][8];
int f2[8][8];

vector<pair<pt, pt> > ans;

void go(pt s, pt t)
{
    queue<pt> q;
    map<pt, pt> p;
    p[s] = mp(-1, -1);
    q.push(s);
    while(!q.empty())
    {
        pt k = q.front();
        q.pop();
        forn(z, 8)
        {
            pt k2 = k + mp(dx[z], dy[z]);
            if(good(k2) && !p.count(k2))
            {
                q.push(k2);
                p[k2] = k;
            }
        }
    }
    vector<pt> path;
    vector<int> needed;
    path.pb(t);
    needed.pb(0);
    while(t != s)
    {
        t = p[t];
        path.pb(t);
        needed.pb(f[t.x][t.y]);
    }
    swap(needed[0], needed.back());
    forn(i, sz(path))
    {
        if(needed[i] != f[path[i].x][path[i].y])
        {
            int j = i + 1;
            for(; j < sz(path); j++) {
                if (f[path[j].x][path[j].y])
                    break;
            }
            for(int z = j; z > i; z--)
                ans.pb(mp(path[z], path[z - 1]));
            swap(f[path[i].x][path[i].y], f[path[j].x][path[j].y]);
        }
    }
}

bool read() {
    int x;
    cin >> x;
    forn(i, x)
    {
        string s;
        cin >> s;
        f[s[0] - 'a'][s[1] - '1'] = 1;
    }
    forn(j, 8)
        forn(i, 8)
        {
            if(x == 0)
                break;
            else
            {
                x--;
                f2[i][j] = 1;
            }
        }
    return true;
}


void solve() {
    while(true)
    {
        pt x = mp(-1, -1);
        pt y = mp(-1, -1);
        forn(i, 8) forn(j, 8)
        {
            if(f[i][j] < f2[i][j])
                x = mp(i, j);
            if(f[i][j] > f2[i][j])
                y = mp(i, j);
        }
        if(x.x == -1)
            break;
        go(y, x);
    }
    cout << sz(ans) << endl;
    for(auto x : ans)
        print_move(x.x, x.y);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}