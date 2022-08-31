#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inf = 1e18;

int idVal = 0;
struct segTree{
    using T=int;
    vector<T> data;
    int N;
    T combine(T const& a, T const& b){
        return a+b;
    }
    void leafMod(T &a, T const&b){
        a=b;
    }
    segTree(int _n):N(_n){
        data.resize(2*N);
        fill(data.begin()+N, data.end(), 1);
        for(int i=N-1;i>=0;--i){
            data[i]=combine(data[i<<1], data[i<<1|1]);
        }
    }
    void update(int pos, T val){
        for(leafMod(data[pos+=N], val);pos>>=1;){
            data[pos]=combine(data[pos<<1], data[pos<<1|1]);
        }
    }
    T query(int l, int r){
        T retL=idVal, retR=idVal;
        for(l+=N, r+=N;l<r;l>>=1, r>>=1){
            if(l&1)retL=combine(retL, data[l++]);
            if(r&1)retR=combine(data[--r], retR);
        }
        return combine(retL, retR);
    }
};



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

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > p;
    for(auto &e:a) cin >> e;
    p.resize(*max_element(a.begin(), a.end())+2);
    for(int i=0;i<n;++i){
        p[a[i]].emplace_back(i);
    }
    segTree st(n);
    ll ans = 0;
    int x=0;
    for(int i=0;i<(int)p.size();++i){
        if(!p[i].empty()){
            auto it = lower_bound(p[i].begin(), p[i].end(), x);
            int y;
            if(it == p[i].begin()){
                y = p[i].back();
            } else {
                y = *(--it);
            }
            if(y<x){
                ans+= st.query(x, n);
                ans+= st.query(0, y);
                ans+= 1;
                x=y;
            } else {
                ans+= st.query(x, y);
                ans+= 1;
                x=y;
            }
            for(int e:p[i]){
                st.update(e, 0);
            }
            p[i].clear();
            //cerr << i << " : " << ans << "\n";
        }
    }

    cout << ans << "\n";






    #ifdef LOCAL_RUN
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}