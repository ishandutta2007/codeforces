#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int F, S;
    cin >> F >> S;
    int uch = -1, wh = -1;
    int s = 0;
    for (int i=0; i < S-F; i++) s += v[i];
    for (int i=0; i < n; i++){
        int R = F-i;
        while (R <= 0) R += n;
        //cout << s << " " << R << endl;
        if (s > uch){
            uch = s, wh = R;
        }
        else if (s==uch){
            wh = min(wh, R);
        }
        s -= v[i];
        s += v[(i+S-F)%n];
    }
    cout << wh << endl;
}