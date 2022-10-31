#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll Q = 2e5 + 3;
const ll T = 1 << 16;

ll k, q, sz;
vector<array<ll, 3>> sweepline;
vector<array<ll, 3>> qu;

vector<ll> st[16 * 4 * T];
bool st_ans[16 * 4 * T];
bool ans[16 * 2 * T];

bool check(ll i, ll l, ll r){
    if(l == r){
        for(ll j = 0; j < 16; ++j){
            if(st_ans[i + j]){
                for(ll x: st[i + j]){
                    if(ans[x]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    ll mid = (l + r) >> 1;
    if(!check(2 * i + 16, l, mid)) return false;
    if(!check(2 * i + 32, mid + 1, r)) return false;

    for(ll j = 0; j < 16; ++j){
        st_ans[i + j] = st_ans[i + j] || st_ans[2 * i + 16 + j] || st_ans[2 * i + 32 + j];
        if(st_ans[i + j]){
            for(ll x: st[i + j]){
                if(ans[x]){
                    return false;
                }
            }
        }
    }

    return true;
}

void build(ll i, ll l, ll r){
    if(l == r){
        for(ll j = 0; j < 16; ++j)
            ans[l * 16 + j] = st_ans[i + j];
        return;
    }

    for(ll j = 0; j < 16; ++j){
        if(st_ans[i + j]){
            st_ans[2 * i + 16 + j] = true;
            st_ans[2 * i + 32 + j] = true;
        }
    }

    ll mid = (l + r) >> 1;
    build(2 * i + 16, l, mid);
    build(2 * i + 32, mid + 1, r);
}

void update(ll i, ll l, ll r, ll sl, ll sr, ll big, ll v){
    if(l > sr || r < sl) return;
    if(sl <= l && r <= sr){
        for(ll j = 0; j < 16; ++j){
            if((v >> j) & 1)
                st_ans[i + j] = true;
            else
                st[i + j].push_back(big * 16 + j + 16 * sz);
        }
        return;
    }

    ll mid = (l + r) >> 1;
    update(2 * i + 16, l, mid, sl, sr, big, v);
    update(2 * i + 32, mid + 1, r, sl, sr, big, v);
}

void add_edges(ll l, ll r, ll v){
    ll big = l / sz;
    l %= sz;
    r %= sz;

    for(ll i = 0; i < 16; ++i)
        if((v >> i) & 1)
            ans[big * 16 + i + 16 * sz] = true;

    update(0, 0, sz - 1, l, r, big, v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> q;

    for(ll i = 0; i < q; ++i){
        ll l, r, v;
        cin >> l >> r >> v;

        sweepline.push_back({l, -1, v});
        sweepline.push_back({r, 1, v});
    }

    sort(sweepline.begin(), sweepline.end());
    ll curr = -1, cnt_ = 0, start = -1;
    for(ll i = 0; i < 2 * q; ++i){
        auto arr = sweepline[i];
        if(arr[1] == -1){
            if(curr != -1 && arr[2] != curr){
                cout << "impossible\n";
                return 0;
            }
            curr = arr[2];
            if(!cnt_) start = arr[0];
            cnt_++;
        }
        else{
            if(cnt_ == 1)
                qu.push_back({start, arr[0], curr});
            cnt_--;
            if(!cnt_) curr = -1;
        }
    }

    sz = (1 << k);
    
    for(ll i = 0; i < qu.size(); ++i){
        auto [l, r, v] = qu[i];
        if(l / sz == r / sz)
            add_edges(l, r, v);
        else{
            add_edges(l, (l / sz) * sz + sz - 1, v);
            add_edges((r / sz) * sz, r, v);
            for(ll j = (l / sz) * sz + sz; j < (r /sz) * sz; j += sz)
                add_edges(j, j + sz - 1, v);
        }
    }

    build(0, 0, sz - 1);
    if(!check(0, 0, sz - 1)){
        cout << "impossible\n";
        return 0;
    }

    cout << "possible\n";
    for(ll i = 0; i < 32 * sz; i += 16){
        ll x = 0;
        for(ll j = 0; j < 16; ++j)
            if(ans[i + j])
                x += (1 << j);
        cout << x << "\n";
    }
}