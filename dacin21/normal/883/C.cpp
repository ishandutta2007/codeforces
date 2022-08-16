#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

const ll inf = 1e18;

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

    int n, T, t0;
    cin >> n >> T >> t0;
    int s1, t1, p1;
    cin >> s1 >> t1 >> p1;
    int s2, t2, p2;
    cin >> s2 >> t2 >> p2;
    ll cost = inf;
    for(int it=0;it<2;++it){
        // iter of pack
        ll cnt1 = n, cnt2 = 0;
        while(cnt1>=0 && cnt2 <= n){
            ll puren = max(0ll, n - cnt1*s1-cnt2*s2);
            ll n2 = max(0ll, min(cnt2*s2, n-cnt1*s1));
            ll n1 = max(0ll, min(cnt1*s1, (ll)n));
            assert(n1+n2+puren == n);
            ll tt = n1*t1+n2*t2+puren*t0;
            if(tt<=T){
                xmin(cost, cnt1*p1+cnt2*p2);
                --cnt1;
            } else {
                ++cnt2;
            }
        }
        // only use one pack
        for(cnt1=0;cnt1<=n;++cnt1){
            ll puren = max(0ll, n - cnt1*s1);
            ll n1 = max(0ll, min(cnt1*s1, (ll)n));
            ll tt = n1*t1+puren*t0;
            if(tt<=T){
                xmin(cost, cnt1*p1);
            }
        }
        swap(s1, s2);
        swap(t1, t2);
        swap(p1, p2);
    }
    if(cost == inf){
        cout << "-1\n";
    } else {
        cout << cost << "\n";
    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}