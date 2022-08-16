#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
ll inf = 1e18;

ll cdiv(ll a, ll b){
    return (a+b-1)/b;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTTT; cin >> TTTT;
    while(TTTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &e:a) cin >> e;
    vector<pair<ll, int> > v;
    vector<pair<int, ll> > laval(n);
    ll cur = 0;
    ll cura = 0;

    for(int i=0;i<n;++i){
        // TODO: speedup
        laval[i] = make_pair(a[i], -a[i]);
        cura+=a[i];
        for(ll j=2;j<=a[i];){
            assert(cdiv(a[i], j) != cdiv(a[i], j-1));
            {
                v.emplace_back(j, i);
                //cerr << i << " " << a[i] << " : " << j << "\n";
            }
            if(cdiv(a[i], j) == 1) break;
            int k = j;
            j = max(j+1, cdiv(a[i], cdiv(a[i], j)-1));
            if(j>k+1) assert(cdiv(a[i], j) == cdiv(a[i], k)-1);
        }
    }
    v.emplace_back(a[0]+k+1, 0);
    sort(v.begin(), v.end());
    ll ans = 1;
    ll last = 1;
    for(auto const&e:v){
        if(e.first!=last){
            //cerr << e.first << " : " << cur << "/" << cura << "\n";
            if(cur <= k){
                if(cura>0) ans = min(e.first-1, last + (k-cur)/cura);
                else ans = e.first-1;
            }
            cur+=cura*(e.first-last);
            last = e.first;
        }
        int i = e.second;
        //cerr << "at: " << i << " : " << laval[i].first << " " << laval[i].second << " " << (laval[i].second + laval[i].first*(last)) << "   /   ";
        cur-=(laval[i].second + laval[i].first*(last));
        cura-=laval[i].first;
        laval[i] = make_pair(cdiv(a[i] , last), cdiv(a[i], last)*last%a[i] - cdiv(a[i], last)*last);
        cura+=laval[i].first;
        cur+=(laval[i].second + laval[i].first*(last));
        //cerr << laval[i].first << " " << laval[i].second << " " << (laval[i].second + laval[i].first*(last))  << "\n";
    }


    cout << ans << "\n";






    #ifdef LOCAL_RUN
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}