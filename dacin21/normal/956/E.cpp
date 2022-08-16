#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

template<typename T>
struct Frac{
    T a, b;
    Frac():a(0), b(1){}
    Frac(T _a):a(_a), b(1){}
    Frac(T _a, T _b):a(_a), b(_b){
        if(b<0){
            b=-b;
            a=-a;
        }
    }
    Frac operator-()const{
        return Frac(-a, b);
    }
    bool operator<(Frac const&o)const{
        return a*o.b < b*o.a;
    }
};
using ft = Frac<ll>;

ft inters(pair<int, int> const&p, int w){
    return ft(p.first, p.second+w);
}

struct F_Tree{
    int n;
    vector<int> da;
    F_Tree(int _n):n(_n+5), da(n, 0){}
    int q(int x){
        int ans = 0;
        for(++x;x;x-=x&-x){
            ans+=da[x];
        }
        return ans;
    }
    void u(int x, int v){
        for(++x;x<n;x+=x&-x){
            da[x]+=v;
        }
    }
};

constexpr int inf = 1e9;

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

    int n, l, r;
    cin >> n >> l >> r;
    vector<pair<int, int> > v(n);
    int w = 0;
    for(auto &e:v){
        cin >> e.second;
        w+=e.second;
    }
    for(auto &e:v) {
        cin >> e.first;
        e.first*=-1;
    }
    vector<int> dp(w+1, -inf);
    dp[w] = 0;
    sort(v.rbegin(), v.rend());
    for(auto &e:v){
        for(int i=e.second;i<=w;++i){
            xmax(dp[i-e.second], dp[i]-e.first*((l<=(i-e.second)) & ((i-e.second)<=r)));
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}