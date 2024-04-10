/*
 *  Code by Anish Kasegaonkar
 *  Created: 28-04-2022 at 09:30:36
 *
 *  Template and snippets by Anish Kasegaonkar
 *  Codeforces: Anish_aak   Atcoder: Anish_aak  Codechef: anish_ak
 *  Github: https://github.com/Anish-aak (code/snippet repository soon!)
 */

#include <bits/stdc++.h>
using namespace std;

// Risky defines
#define int             long long
#define double          long double
#define endl            '\n'
#define vector          deque

#define pb              push_back
#define popb            pop_back
#define popf            pop_front
#define mp              make_pair
#define ff              first
#define ss              second
#define lb              lower_bound
#define ub              upper_bound
#define gri             greater<int>
#define sq(t)           (t)*(t)
#define all(t)          (t).begin(), (t).end()
#define mid(l,r)        (l) + ((r)-(l))/2
#define max3(a,b,c)     max((a), max((b), (c)))
#define max4(a,b,c,d)   max((a), max((b), max((c), (d))))
#define min3(a,b,c)     min((a), min((b), (c)))
#define min4(a,b,c,d)   min((a), min((b), min((c), (d))))
#define rep(i,j)        for(int i = 0; i < (j); ++i)
#define rrep(i,j)        for(int i = (j)-1; i >= 0; --i)
#define maxin(t)        *max_element((t).begin(), (t).end())
#define minin(t)        *min_element((t).begin(), (t).end())
#define sz(t)           (int) (t).size()
#define getunique(v)    {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define modd(x,y)       ((x)%(y)<0 ? (x)%(y)+y : (x)%(y))

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef vector<vector<int> > vvi;
typedef deque<int> di;
typedef deque<pair<int, int> > dpii;
typedef deque<deque<int> > ddi;
typedef map<int, int> mii;
typedef priority_queue<int> maxpq;
typedef priority_queue<int, vector<int>, greater<int> > minpq;
typedef unordered_map<int, int> umapii;
typedef unordered_map<char, int> umapci;
typedef unordered_set<int> useti;
typedef unordered_set<pair<int, int> > usetpii;
typedef set<int> si;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

const char nl = '\n';
const double eps = 1e-6, pi = acos(-1);
const int N = 1e5, mod = 1e9 + 7, inf = 1e18;

void solve()
{
    int n; cin>>n;
    map<int, int> m;
    rep(i, n) {
        int b, d; cin>>b>>d;
        m[d] = max(m[d], b);
    }
    if(m.size() < 10) {
        cout<<"MOREPROBLEMS\n";
    } else {
        int t = 0;
        for(auto i: m) t += i.ss;
        cout<<t<<nl;
    }
}

int32_t main()
{
    #ifdef aak_local
        auto begin = std::chrono::high_resolution_clock::now();
        freopen("/Users/aak/Desktop/C:C++/Competitive/input.txt","r",stdin);
        freopen("/Users/aak/Desktop/C:C++/Competitive/output.txt","w",stdout);
        #define dbg(a) cerr << '\n'; cerr << #a << ": "; _print(a); cerr << '\n' << '\n';
    #else
        #define dbg(a)
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(numeric_limits<double>::max_digits10);
    cout << setprecision(15) << fixed;
    int tt = 1;
    cin >> tt;
    for(int i = 1; i <= tt; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    #ifdef aak_local
       auto end = std::chrono::high_resolution_clock::now();
       cerr << setprecision(4) << fixed;
       cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
    return 0;
}