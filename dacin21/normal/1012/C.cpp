//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native") // yandex

#include <bits/stdc++.h>
using namespace std;
using ll = int;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

constexpr ll inf = 1e9;

int n;
vector<ll> a;
vector<vector<array<ll, 2> > > cache;

ll rhdiff(int x){
   if(x == n-1) return -1ll;
   return a[x+1] - a[x];
}
ll lhdiff(int x){
   if(x == n-1) return -1ll;
   return a[x+1] - a[x];
}

ll rec(int x, int k, bool did){
    if(k<0) return inf;
    if(x <= 0){
        if(did) return inf;
        if(k>0) return inf;
        return 0;
    }
    ll &ca = cache[x][k][did];
    if(ca != -1) return ca;
    ca = inf;
    if(!did){
        xmin(ca, rec(x-1, k, false));
        xmin(ca, rec(x-1, k, true));
    } else {
        if(k == 0) return inf;
        {
            ll rcost = (x==n ? 0 : a[x] - a[x-1]+1);
            xmax(rcost, 0);
            ll lcost = (x==1 ? 0 : a[x-2] - a[x-1]+1);
            xmax(lcost, 0);
            xmin(ca, rec(x-2, k-1, false) + lcost + rcost);
        }
        if(x>2){
            ll rcost = (x==n ? 0 : a[x] - a[x-1]+1);
            xmax(rcost, 0);
            ll lcost = min(a[x-3]-1, a[x-2]) - a[x-1]+1;
            xmax(lcost, 0);
            xmin(ca, rec(x-2, k-1, true) + lcost + rcost);
        }
    }

    return ca;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    ///CODE
    cin >> n;
    a.assign(n, 0);
    for(auto &e:a){
        cin >> e;
    }
    cache.assign(n+1, vector<array<ll, 2> >(n+1, array<ll, 2>{-1, -1}));

    for(int i=1;i<=(n+1)/2;++i){
        ll ans = rec(n, i, true);
        ll ans2 = rec(n, i, false);
        ll out = min(ans, ans2);
        cout << out << " ";
    }
    cout << "\n";

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}