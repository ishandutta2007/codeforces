#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

const int block = 1000;
bool cmp(array<int, 4> const&a, array<int, 4> const&b){
    if(a[0]/block!=b[0]/block) return a[0]<b[0];
    return ((a[1]<b[1]) != ((a[0]/block)&1)) && (a[1]!=b[1]);
}

mt19937 rng(363253);
int getrand(int a, int b){
    return uniform_int_distribution<int>(a, b)(rng);
}
const int inf = 1e9;
signed gen(){
    int n=3e5, q=3e5;
    ofstream o("gen.txt");
    o << n << " " << q << "\n";
    for(int i=0;i<n;++i){
        o << getrand(1, 5)*getrand(1, 5) << " ";
    }
    o << "\n";
    for(int i=0;i<q;++i){
        int a, b;
        a=getrand(1, n), b=getrand(1, n);
        if(a>b) swap(a, b);
        o << a << " " << b << " " << getrand(2, 5) << "\n";
    }
    o << endl;
    o.close();
    return 0;
}
signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT;
    if(TTT<0) return gen();
    while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    ///CODE
    int n, q;
    cin >> n >> q;
    vector<array<int, 4> >qs;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    for(int i=0;i<q;++i){
        int l, r, k;
        cin >> l >> r >> k;
        --l; --r;
        qs.push_back({l, r, k, i});
    }
    sort(qs.begin(), qs.end(), cmp);
    int l=0, r=-1;
    vector<pair<int, int> > tmp;
    vector<int> cnt(n+5, 0);
    vector<int> out(q);
    for(auto const& e:qs){
        while(l<e[0]){
            --cnt[a[l]];
            ++l;
        }
        while(l>e[0]){
            --l;
            ++cnt[a[l]];
        }
        while(r<e[1]){
            ++r;
            ++cnt[a[r]];
        }
        while(r>e[1]){
            --cnt[a[r]];
            --r;
        }
        int ans = inf;
        for(int i=0;i<100;++i){
            int x = a[getrand(l, r)];
            if(cnt[x]*e[2]>(r-l+1)) ans = min(ans, x);
        }
        out[e[3]] = (ans==inf?-1:ans);
    }
    copy(out.begin(), out.end(), ostream_iterator<int>(cout, "\n"));



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}