#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 30;
ll cnt[N];

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < n; i ++ ){
        cin >> cnt[i];
    }
    int ty;
    ll x;
    int pos;
    ll opr;
    ll shit;
    int id;
    ll take;
    ll ff;
    ll soln;
    for(int qq = 0; qq < q; qq ++ ){
        cin >> ty;
        if(ty == 1){
            cin >> pos >> x;
            cnt[pos]=x;
        }
        else{
            cin >> pos >> x;
            opr = 0;
            shit = 0;
            for(int i = 0 ; i <= pos; i ++ ){
                shit += ((1ll << i) - 1) * cnt[i];
                x -= cnt[i];
            }
            if(x <= 0){
                cout << 0 << "\n";
                continue;
            }
            id = pos + 1;
            while(id < n){
                ff = (1ll<<(id-pos));
                take = min(x/ff,cnt[id]);
                x -= take * 1ll * ff;
                opr += take * 1ll * (ff - 1);
                shit += take * 1ll * ff * 1ll * ((1ll << pos) - 1);
                if(take == cnt[id]) id ++ ;
                else{
                    break;
                }
            }
            if(id==n){
                if(x <= shit){
                    cout << opr + x << "\n";
                }
                else{
                    cout << "-1\n";
                }
                continue;
            }
            if(x <= 0){
                cout << opr << "\n";
                continue;
            }
            soln = (ll)1e18;
            while(id > pos){
                if(shit >= x){
                    soln = min(soln, opr + x);
                }
                opr ++ ;
                id--;
                if(x >= (1ll<<(id-pos))){
                    x -= (1ll<<(id-pos));
                    opr += (1ll<<(id-pos))-1;
                    shit += (1ll<<(id-pos))*1ll*((1ll<<pos)-1);
                }
            }
            soln = min(soln,opr);
            cout << soln << "\n";
        }
    }
    return 0;
}