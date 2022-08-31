#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

struct DSU{
    int n;
    vector<int> p;
    DSU(int n_):n(n_), p(n, -1){}
    int f(int x){
        return p[x]<0 ? x : p[x]=f(p[x]);
    }
    bool u(int a, int b){
        if((a=f(a))!=(b=f(b))){
            if(p[a] > p[b]) swap(a, b);
            p[a]+=p[b];
            p[b]=a;
            return true;
        }
        return false;
    }
    int compcnt(){
        return count_if(p.begin(), p.end(), [](int x){return x<0;});
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

    int n, m, q;
    cin >> n >> m >> q;
    DSU uni(n);
    vector<vector<int> > cols(m);
    for(int i=0;i<q;++i){
        int x, y;
        cin >> x >> y;
        --x; --y;
        cols[y].push_back(x);
    }
    int ans = 0;
    for(auto &e:cols){
        if(e.empty()) ++ans;
        else {
            for(int i=1;i<(int)e.size();++i){
                uni.u(e[i-1], e[i]);
            }
        }
    }
    ans+=uni.compcnt() - 1;
    cout << ans << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}