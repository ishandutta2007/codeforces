//A new day, a new age, a new face, a new lay, a new love, a new drug, a new me, a new you..

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll max_n = 1e5 + 50;
const ll INF = 1e9 + 7;

ll n, l, w;
vector<pair<ll, ll>>  adj[max_n];
ll ans;
ll sz[max_n];
bool block[max_n];
ordered_set st;
vector<pair<ll, ll>>   sec;

ll get_size(ll v, ll p = -1){
    sz[v] = 1;
    for (pair<ll, ll> e:adj[v]){
        ll u = e.first;
        if (u != p && !block[u])    
            sz[v] += get_size(u, v);
    }
    return  sz[v];
}

void insert(ll v, ll p = -1, ll de = 0, ll c = 0){
    sec.push_back({de, c});
    for (pair<ll, ll> e:adj[v]){
        ll u = e.first;
        if (!block[u] && u != p)    insert(u, v, de + 1, c + e.second);
    }
}

void add(ll v, int p, ll lplus, ll wplus, ll type){
    sec.clear();
    insert(v, p);
    sort(sec.begin(), sec.end());
    st.clear();
    
    ll h = 0;
    for (ll i = sec.size() - 1; i >= 0; i--){
        ll a = sec[i].first, b = sec[i].second;
        while (h < sec.size() && sec[h].first + a + lplus <= l)
            st.insert({sec[h].second, h++});
        
        ans += type * (ll)st.order_of_key({w - b - wplus, INF});
    }
}

void solve(ll v, ll p = -1){
    ll size = get_size(v);
    bool flag = 1;
    while (flag){
        flag = 0;
        for (pair<ll, ll> e:adj[v]){
            ll u = e.first;
            if (u != p && !block[u] && sz[u] > size/2){
                p = v;
                v = u;
                flag = 1;
                break;   
            }
        }
    }
    
    block[v] = 1;
    for (pair<ll, ll> e:adj[v])
        if (!block[e.first])    solve(e.first);
    block[v] = 0;
    
    add(v, -1, 0, 0, 1);
    for (pair<ll, ll> e:adj[v]){
        ll u = e.first;
        if (block[u])   continue;
        add(u, v, 2, e.second * 2, -1);
    }
}   

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> w;
    for (ll i = 1; i < n; i++){
        ll p, c;   cin >> p >> c;  p--;
        adj[p].push_back({i, c});
        adj[i].push_back({p, c});
    }
    solve(0);
    cout << (ans-n) / 2 << endl;
    return 0;
}