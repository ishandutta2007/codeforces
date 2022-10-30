#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 45, K = 15;

int n, k, uniq[K], cnt[K];
ll cover[K], icover[K][N], tot[K];

bool calc(ll mask, int step){
    if(step == k){
        int o = __builtin_popcountll(mask);
        int z = n-o;
        ll targ = ((1ll<<o)-1)<<z;
        return mask==targ;
    }
    int mn = __builtin_popcountll(mask&cover[step]);
    mask |= cover[step];
    for(int i = mn; i<=mn+uniq[step]; i++)
        if(!calc(mask&icover[step][i], step+1)) return 0;
    return 1;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i<k; i++){
        cin >> cnt[i];
        icover[i][cnt[i]] = (1ll<<n)-1;
        for(int j = 0; j<cnt[i]; j++){
            int pos; cin >> pos; --pos;
            cover[i] |= (1ll<<pos);
            icover[i][cnt[i]-j-1] = (~cover[i]);
        }
        if(!i) uniq[i] = __builtin_popcountll(cover[i]);
        else uniq[i] = __builtin_popcountll(cover[i]&(~tot[i-1]));
        if(!i) tot[i] = cover[i];
        else tot[i] = (tot[i-1]|cover[i]);
    }
    if(n == 1){
        cout << "ACCEPTED" << '\n';
        exit(0);
    }
    if(k == 0){
        cout << "REJECTED" << '\n';
        exit(0);
    }
    if(cnt[k-1] == n){
        cout << "ACCEPTED" << '\n';
        exit(0);
    }
    if(tot[k-1] != (1ll<<n)-1){
        cout << "REJECTED" << '\n';
        exit(0);
    }
    if(calc(0, 0)) cout << "ACCEPTED" << '\n';
    else cout << "REJECTED" << '\n';
}