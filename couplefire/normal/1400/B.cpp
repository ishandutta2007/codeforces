#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long p, f; cin >> p >> f;
        long long cs, cw; cin >> cs >> cw;
        long long s, w; cin >> s >> w;
        if(s > w){
            swap(cs, cw);
            swap(s, w);
        }
        long long ans = 0;
        for(int i = 0; i<=cs; i++){
            if(p < i*s) continue;
            long long cnt = 0;
            long long pp = p;
            long long ff = f;
            long long ccs = cs;
            long long ccw = cw;
            pp -= i*s;
            ccs -= i;
            cnt += i;
            long long mi = min(pp/w, cw);
            pp -= mi*w;
            ccw -= mi;
            cnt += mi;
            long long mi2 = min(ff/s, ccs);
            ff -= mi2*s;
            ccs -= mi2;
            cnt += mi2;
            long long mi3 = min(ff/w, ccw);
            cnt += mi3;
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
}