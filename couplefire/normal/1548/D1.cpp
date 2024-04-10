#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, cnt[2][2], stuff[2][2][2][2];
ll ans;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; ++i){
        int x, y; cin >> x >> y;
        x /= 2, y /= 2;
        cnt[x%2][y%2]++;
    }
    for(int a = 0; a<2; ++a)
        for(int b = 0; b<2; ++b)
            for(int c = 0; c<2; ++c)
                for(int d = 0; d<2; ++d)
                    stuff[a][b][c][d] = gcd(abs(a-c), abs(b-d));
    for(int a = 0; a<2; ++a)
        for(int b = 0; b<2; ++b){
            ll val1 = cnt[a][b]; cnt[a][b]--;
            for(int c = 0; c<2; ++c)
                for(int d = 0; d<2; ++d){
                    ll val2 = val1*cnt[c][d]; cnt[c][d]--;
                    for(int e = 0; e<2; ++e)
                        for(int f = 0; f<2; ++f){
                            ll val3 = val2*cnt[e][f];
                            if((stuff[a][b][c][d]+stuff[a][b][e][f]+stuff[c][d][e][f])%2==0) ans += val3;
                        }
                    cnt[c][d]++;
                }
            cnt[a][b]++;
        }
    cout << ans/6 << '\n';
}