#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--){
        int k;
        cin >> k;
        VI a(7, 0), prefs(8, 0);
        for (int i = 0; i < 7; ++i){
            cin >> a[i];
            prefs[i+1] = prefs[i] + a[i];
        }
        
        int ans = 2e9;
        for (int i = 0; i < 7; ++i){
            for (int j = 0; j < 7; ++j){
                int cur = ((j-i)+7)%7 + 1;
                int val = 0;
                if (j >= i){
                    val = prefs[j+1] - prefs[i];
                }
                else{
                    val = prefs[7] - (prefs[i]-prefs[j+1]);
                }
                //cerr << val << " " << i << " " << j << endl;
                if (val <= k and (k-val)%prefs[7] == 0){
                    ans = min(ans, cur + 7*(k-val)/prefs[7]);
                }
            }
        }
        cout << ans << endl;
    }
}