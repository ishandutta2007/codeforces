#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}


vector<int> p;
int f(int x){
    return p[x]<0?x:p[x] = f(p[x]);
}
void u(int a, int b){
    if((a=f(a))!=(b=f(b))){
        p[b] = a;
    }
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

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &e:v) cin >> e;
    p.assign(n+m, -1);
    auto ro = [&](int x){return x;};
    auto col = [&](int x){return n+x;};
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(v[i][j] == '#'){
                u(ro(i), col(j));
            }
        }
    }
    bool fail = false;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(f(ro(i)) == f(col(j))){
                if(v[i][j] != '#'){
                    fail=true;
                }
            }
        }
    }

    if(fail){
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}