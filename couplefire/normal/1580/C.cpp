#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int B = 450;

int n, m, x[N], y[N], dif[N], pos[N], stuff[B][B], cur;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<n; ++i)
        cin >> x[i] >> y[i];
    for(int i = 0; i<m; ++i){
        int opt, k; cin >> opt >> k; --k;
        if(opt==1){
            pos[k] = i;
            if(x[k]+y[k]>=B){
                for(int j = i+x[k]; j<m; j+=x[k]+y[k]) ++dif[j];
                for(int j = i+x[k]+y[k]; j<m; j+=x[k]+y[k]) --dif[j];
            } else{
                for(int j = 0; j<y[k]; ++j)
                    stuff[x[k]+y[k]][(i+x[k]+j)%(x[k]+y[k])]++;
            } cur += dif[i];
        } else{ cur += dif[i];
            if(x[k]+y[k]>=B){
                for(int j = pos[k]+x[k]; j<m; j+=x[k]+y[k]) --dif[j];
                for(int j = pos[k]+x[k]+y[k]; j<m; j+=x[k]+y[k]) ++dif[j];
                if((i-pos[k])%(x[k]+y[k])>=x[k]) --cur;
            } else{
                for(int j = 0; j<y[k]; ++j)
                    stuff[x[k]+y[k]][(pos[k]+x[k]+j)%(x[k]+y[k])]--;
            }
        }
        int ans = cur;
        for(int j = 1; j<B; ++j)
            ans += stuff[j][i%j];
        cout << ans << '\n';
    }
}