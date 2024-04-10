#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 98
#define cerr if(false)cout
#endif

#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
void Main();

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Main();
    return 0;
}
const int maxn = 25;
ll a[maxn][maxn];
map<ll,int> Cnt1,Cnt2;
int n,m;
ll k;
ll ans;
void brute_forward(int x,int y,ll now){
    now^= a[x][y];
    if (x==1&&y==1){
        Cnt1[now]++;
        return;
    }
    if (x>1){
        brute_forward(x-1,y,now);
    }
    if (y>1){
        brute_forward(x,y-1,now);
    }
}
void brute_backward(int x,int y,ll now){
    now ^= a[x][y];
    if (x==n&&y==m){
        Cnt2[now]++;
        return;
    }
    if (x<n)
        brute_backward(x+1,y,now);
    if (y<m)
        brute_backward(x,y+1,now);
}
void calc(int x,int y){
    ll K = k^a[x][y];
    for (auto xx:Cnt1)
        ans+=1LL*xx.second*Cnt2[K^xx.first];
}
void Main() {

    multiset<int> s;
    vector<int> v;
    int n,k;
    cin >> n >> k;
    vi a(n, 0), b(2010, 0);
    rep(i, 0, n)
        cin >> a[i] , b[i+1]=a[i];
    sort(rall(a));
    //return;
    ll sum = 0;
    rep(i, 0, k) {
        s.insert(a[i]);
        sum += a[i];
    }
    //return;
    v.push_back(0);
    REP(i, 1, n) {
        if(s.size() == 1) break;
        if(s.count(b[i])) {
            v.push_back(i);
            s.erase(s.find(b[i]));
        }
    }
    cout << sum << endl;
    for(int i = 1;i < v.size(); ++i) cout << v[i] - v[i - 1] << ' ';
    cout << n-v[v.size()-1] << endl;
    return;
}