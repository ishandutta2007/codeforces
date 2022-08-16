#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll inf = 3e18;

unordered_map<int, ll> ca;
ll calc(int x){
    if(x==0) return 0;
    if(x==1) return 1;
    if(x==2) return 9;
    if(ca.count(x)) return ca[x];
    ll ans = 1+2*calc(x-1)*calc(x-1) + 2*calc(x-1);
    ca[x] = ans;
    return ans;
}
map<int, vector<ll> >ca2;
vector<ll> calc2(int n){
    if(n==0) return vector<ll>();
    if(n==1) return vector<ll>(1, 1);
    if(ca2.count(n)) return ca2[n];
    auto e = calc2(n-1);
    int k = e.size();
    vector<ll> ans(2*k+1, 0);
    //single tree
    for(int i=0;i<k;++i){
        ans[i]+=2*e[i];
    }
    //double tree
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            ans[i+j+1+1]+=e[i]*e[j]*2;
        }
    }
    // single
    ++ans[0];
    // attach
    for(int i=0;i<k;++i){
        ans[i+1]+=2*(i+2)*e[i];
    }
    ca2[n] = ans;
    cerr << n << " : ";
    for(auto &e:ans) cerr << e << " "; cerr << "\n";
    return ans;
}
ll mod = 1e9+7;
vector<ll> cache3;
ll calc3(int n, int k){
    if(k<0) return 0;
    if(n==0) return k==0;
    if(n==1) return k<=1;
    if(cache3[n*500+k]!=-1) return cache3[n*500+k];
    ll ans = 0;
    array<ll, 5> tmp;
    // unused
    for(int i=0;i<=k;++i){
        ans+=calc3(n-1, i)*calc3(n-1, k-i)%mod;
    }
    tmp[0] = ans;
    // add single
    for(int i=0;i<k;++i){
        ans+=calc3(n-1, i)*calc3(n-1, k-i-1)%mod;
    }
    tmp[1] = ans;
    // append / prepend
    for(int i=0;i<=k;++i){
        ans+=2*k*calc3(n-1, i)%mod*calc3(n-1, k-i)%mod;
    }
    tmp[2] = ans;
    // merge single
    for(int i=0;i<=k+1;++i){
        ans+=2*i*(i-1)*calc3(n-1, i)%mod*calc3(n-1, k-i+1)%mod;
    }
    tmp[3] = ans;
    // merge double
    for(int i=0;i<=k+1;++i){
        ans+=2*i*(k+1-i)*calc3(n-1, i)%mod*calc3(n-1, k+1-i)%mod;
    }
    tmp[4] = ans;
    ans%=mod;
    //for(ll e:tmp) cerr << e << " "; cerr << "\n";
    //cerr << n <<  " " << k << " : " << ans << "\n";
    cache3[n*500+k] = ans;
    return ans;
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
    cache3.resize(400*400*2, -1);

    int n;
    cin >> n;
    //auto e = calc2(n);
    //cout << accumulate(e.begin(), e.end(), 0ll) << "\n";
    cout << calc3(n, 1) << "\n";
    //cout << calc(n) << "\n";






    #ifdef LOCAL_RUN
    //cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}