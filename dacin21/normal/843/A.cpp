#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

vector<int> p;
int f(int x){return p[x]<0?x:p[x]=f(p[x]);}
void u(int a, int b){
    if(f(a)!=f(b)) p[f(a)]=f(b);
}
const int inf = int(1e9)+5;
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
    int n;
    cin >> n;
    p.assign(n, -1);
    vector<int> a(n), x;
    for(int&e:a) cin >> e;
    x=a;
    sort(x.begin(), x.end());
    for(int i=0;i<n;++i){
        u(i, lower_bound(x.begin(), x.end(), a[i])-x.begin());
    }
    int bcnt = 0;
    vector<vector<int> > b(n+1);
    for(int i=0;i<n;++i){
        if(f(i)==i) {
            ++bcnt;
        }
        b[f(i)].push_back(i);
    }
    cout << bcnt << "\n";
    for(auto const&e:b){
        if(!e.empty()){
            cout << e.size();
            for(int f:e) cout << " " << f+1;
            cout << "\n";
        }
    }

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}