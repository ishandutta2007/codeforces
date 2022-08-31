#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

vector<ll> get_ineq(vector<ll> const&a){
    int n = a.size();
    vector<ll> ret(n);
    ll cur = 1e17;
    for(int i=0;i<n;++i){
        xmin(++cur, a[i]);
        ret[i] = cur;
    }
    return ret;
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

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
        cin >> b[i];
        b[i]+=a[i];
    }
    vector<vector<ll> > ineq;
    for(int it=0;it<2;++it){
        ineq.push_back(get_ineq(b));
        reverse(b.begin(), b.end());
    }
    bool f = false;
    ll su = 0;
    for(int i=0;i<n;++i){
        b[i] = min(ineq[0][i], ineq[1][n-i-1]);
        if(b[i]<a[i]) f=true;
        su+=b[i]-a[i];
    }
    if(f){
        cout << "-1\n";
    } else{
        cout << su << "\n";
        copy(b.begin(), b.end(), ostream_iterator<ll>(cout, " "));
        cout << "\n";
    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}