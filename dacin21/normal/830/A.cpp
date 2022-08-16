#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inf = 4e18;
template<typename T1, typename T2>
void xmin(T1 &a, T2 const&b){
    if(b<a) a=b;
}

int main()
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

    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<vector<ll> > DP(n+1, vector<ll>(k+1, inf));
    DP[0][0] = 0;
    vector<ll> ppos(n);
    vector<ll> kpos(k);
    for(auto &e:ppos) cin >> e;
    for(auto &e:kpos) cin >> e;
    sort(ppos.begin(), ppos.end());
    sort(kpos.begin(), kpos.end());

    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            xmin(DP[i+1][j+1], max(DP[i][j], abs(ppos[i]-kpos[j]) + abs(kpos[j] - p)));
            xmin(DP[i][j+1], DP[i][j]);
            //cerr << i << " " << j << " " << DP[i][j] << "\n";
        }
    }
    ll ans = *min_element(DP[n].begin(), DP[n].end());
    cout << ans << "\n";





    #ifdef LOCAL_RUN
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}