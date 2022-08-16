#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x, y, z;

set<pair<int, int> > s;
ll ar;

set<pair<int, int> >::iterator del_p(set<pair<int, int> >::iterator it){
    assert(it!=s.begin());
    auto e = prev(it);
    auto f = next(it);
    assert(f!=s.end());
    ar-=(it->first - e->first)*(ll)(it->second - f->second);
    //cerr << "rem: " << it->first << "/" << it->second << " ==> " << ar << "\n";
    return s.erase(it);
}

void add_p(pair<int, int> const&p){
    auto it = s.lower_bound(p);
    if(it->second >= p.second) return;
    for(;;){
        auto e = prev(it);
        if(e->second<=p.second){
            del_p(e);
        } else break;
    }
    auto e = prev(it);
    ar+= (p.first-e->first)*(ll)(p.second - it->second);
    //cerr << "add: " << p.first << "/" << p.second << " ==> " << ar << "\n";
    s.insert(p);
}

const int inf = 1e9;

int main()
{
    #ifdef LOCAL_RUN
    freopen("inD.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif // LOCAL_RUN
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> x >> y >> z;
    vector<vector<pair<int, int> > > v(z+1);

    // add special
    s.insert({0, inf});
    s.insert({inf, 0});

    for(int i=0;i<n;++i){
        int a, b, c;
        cin >> a >> b >> c;
        add_p({a, b});
        //add_p({a, 0});
        //add_p({0, b});
        //v[c].push_back({a, b});
        v[c].push_back({x, b});
        v[c].push_back({a, y});
    }
    ll ans = 0;
    for(int i=z;i>0;--i){
        for(auto e:v[i]){
            add_p(e);
        }
        //if(ar>=x*(ll)y) break;
        ans +=x*(ll)y;
        ans-=ar;
    }
    cout << ans << "\n";

    return 0;
}