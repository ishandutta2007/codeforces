#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

map<int, pair<int, int> > cache;
pair<int, int> query(int id){
    if(!cache.count(id)){
        cout << "? " << id << endl;
        int val, ne;
        cin >> val >> ne;
        cache[id] = make_pair(val, ne);
    }
    return cache[id];
}

mt19937 rng;

int getrand(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

signed main()
{
    #ifdef LOCAL_RUN
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    rng = mt19937(5325 ^ time(0));

    ///CODE
    int n, start, x;
    cin >> n >> start >> x;
    for(int it=0;it<1000;++it){
        int a = getrand(1, n);
        pair<int, int> res = query(a);
        if(res.first<x && res.first > query(start).first) start = a;
    }
    while(query(start).second>=0 && query(start).first<x){
        start = query(start).second;
    }
    if(query(start).first>=x){
        cout << "! " << query(start).first << endl;
    } else {
        cout << "! " << -1 << endl;
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}