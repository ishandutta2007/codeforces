#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int B = 330;

int n, q;
int arr[N], lazy[B], val[N];

int huh(int i){return max(0, arr[i]-lazy[i/B]);}

void upd(int b){
    for(int i = b*B; i<(b+1)*B; i++){
        if(i>=n) break;
        if(huh(i)<b*B) val[i] = i;
        else val[i] = val[huh(i)];
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i<n; i++)
        cin >> arr[i], --arr[i];
    for(int i = 0; i<B; i++) upd(i);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, x; cin >> l >> r >> x; --l, --r;
            int lb = l/B, rb = r/B;
            if(lb == rb){
                for(int i = l; i<=r; i++)
                    arr[i] = max(0, arr[i]-x);
                upd(lb); continue;
            }
            for(int i = l; i<(lb+1)*B; i++) arr[i] = max(0, arr[i]-x);
            for(int i = rb*B; i<=r; i++) arr[i] = max(0, arr[i]-x);
            for(int i = lb+1; i<rb; i++){
                int pl = lazy[i];
                lazy[i] = min(lazy[i]+x, n+1);
                if(pl<=B) upd(i);
            }
            upd(lb); upd(rb);
        } else{
            int u, v; cin >> u >> v; --u; --v;
            while(val[u] != val[v]){
                if(val[u] < val[v]) swap(u, v);
                u = huh(val[u]);
            }
            while(u != v){
                if(u < v) swap(u, v);
                u = huh(u);
            }
            cout << u+1 << '\n';
        }
    }
}