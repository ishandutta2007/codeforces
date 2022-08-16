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

    int n, w;
    cin >> n >> w;
    vector<pair<int, int> > pl(n);
    vector<pair<ft, ft> > ev;
    vector<ft> deco;
    for(auto &e:pl){
        cin >> e.first >> e.second;
        ev.emplace_back(inters(e, -w), -inters(e, w));
        deco.push_back(ev.back().second);
    }
    sort(deco.begin(), deco.end());
    auto de = [&](ft const&x)->int{
        return lower_bound(deco.begin(), deco.end(), x) - deco.begin();
    };
    sort(ev.begin(), ev.end());

    F_Tree ft(n);
    ll ans = 0;
    for(auto &e:ev){
        int x = de(e.second);
        ans+=ft.q(x);
        ft.u(x, 1);
    }
    cout << ans << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}