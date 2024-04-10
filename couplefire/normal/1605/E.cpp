#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

const int N = 200005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, q, arr[N], brr[N], dif[N];
vector<int> facs[N]; pll huh[N];
ll ans[N]; pll qs[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; ++i)
        cin >> arr[i];
    for(int i = 1; i<=n; ++i)
        cin >> brr[i], dif[i] = brr[i]-arr[i];
    for(int i = 1; i<=n; ++i)
        for(int j = i; j<=n; j+=i)
            facs[j].push_back(i);
    huh[1] = {0, 1};
    for(int i = 2; i<=n; ++i){
        huh[i] = {dif[i], 0};
        for(auto x : facs[i])
            if(x!=i) huh[i].f -= huh[x].f, huh[i].s -= huh[x].s;
    } cin >> q;
    for(int i = 0; i<q; ++i){
        int x; cin >> x;
        qs[i] = {x-arr[1], i};
    }
    sort(qs, qs+q);
    vector<int> sgn(n+1);
    vector<int> ord(n+1);
    iota(ord.begin(), ord.end(), 1);
    vector<ll> isect(n+1);
    for(int i = 1; i<=n; ++i){
        auto [a, b] = huh[i];
        if(b<0) sgn[i] = 1;
        else if(b>0) sgn[i] = -1;
        else sgn[i] = (a<0?-1:1);
        if(b==0) isect[i] = INF;
        else if(b>0) isect[i] = ceil((.0-a)/(.0+b));
        else isect[i] = ceil((.0+a)/(.0-b));
    }
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return isect[a]<isect[b];
    });
    pll lans = {0, 0}, rans = {0, 0};
    for(int i = 1; i<=n; ++i)
        if(sgn[i]<0) lans.f += huh[i].f, lans.s += huh[i].s;
        else rans.f += huh[i].f, rans.s += huh[i].s;
    int cur = 0;
    for(int i = 0; i<q; ++i){
        auto [val, id] = qs[i];
        while(cur<n && isect[ord[cur]]<=val){
            int x = ord[cur];
            if(sgn[x]<0){
                lans.f -= huh[x].f, lans.s -= huh[x].s;
                rans.f += huh[x].f, rans.s += huh[x].s;
            } else{
                rans.f -= huh[x].f, rans.s -= huh[x].s;
                lans.f += huh[x].f, lans.s += huh[x].s;
            } ++cur;
        }
        ans[id] = -(lans.f+lans.s*val)+(rans.f+rans.s*val);
    }
    for(int i = 0; i<q; ++i)
        cout << ans[i] << '\n';
}