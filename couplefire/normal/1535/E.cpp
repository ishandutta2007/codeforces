#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 300005;

int q;
int arr[N], crr[N];
int fa[N], up[N][20];

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q >> arr[0] >> crr[0];
    for(int i = 1; i<=q; i++){
        int type; cin >> type;
        if(type == 1){
            cin >> fa[i] >> arr[i] >> crr[i];
            up[i][0] = fa[i];
            for(int j = 1; j<20; j++)
                up[i][j] = up[up[i][j-1]][j-1];
        } else{
            int v, w; cin >> v >> w;
            int tv = -1, ans = 0; int tw = w;
            while(w && tv != v){
                tv = v;
                for(int j = 19; j>=0; j--)
                    if(arr[up[tv][j]] > 0) tv = up[tv][j];
                int a = w, b = arr[tv];
                ans += min(a, b)*crr[tv]; arr[tv] -= min(a, b);
                w -= min(a, b);
            }
            cout << tw-w << " " << ans << endl;
        }
    }
}