#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, l, k;
    cin >> n >> l >> k;
    
    vector<ll> v(26, 0);
    for (int i = 0; i < n*l; ++i){
        char c;
        cin >> c;
        v[c-'a']++;
    }
    
    vector<string> res(n, string(l, ' '));
    int p = 0, cur = 0, cnt = k;
    for (int i = 0; i < l; ++i){
        while (v[p] == 0) ++p;
        if (v[p] >= cnt){
           // cerr << "eeeei " << i << " " << 
            for (int j = cur; j < k; ++j){
                res[j][i] = 'a'+p;
               // if (j == 2) cerr << "coooom" << endl;
            }
            v[p] -= cnt;
        }
        else{
            for (int j = cur; j < cur+v[p]; ++j){
                res[j][i] = 'a'+p;
               // if (j == 2) cerr << i << " coooom2 " << cur << " " << cnt << " " << v[p] << endl;
            }
            cnt -= v[p];
            cur += v[p];
            v[p] = 0;
            --i;
        }
       // cerr << i << " " << cnt <<  " " << cur << " " << v[p] << endl;
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < l; ++j){
            while (v[p] == 0) ++p;
            if (res[i][j] == ' '){
           // cerr << "eeem " << i << " " << j << " " <<  p << endl;
                res[i][j] = 'a'+p;
                --v[p];
            }
        }
        cout << res[i] << endl;
    }
    
}