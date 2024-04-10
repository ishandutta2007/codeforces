#include <bits/stdc++.h>

using namespace std;

#define int long long
int ask(int l, int r){
    cout << "? " << l+1 << " " << r+1 << endl;
    int res;
    cin >> res;
    cout << "? " << l+1 << " " << r+1 << endl;
    cin >> res;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int n, t;
    cin >> n >> t;
    int St = t;
    int calc = 0, sep = 0;
    vector<int> ans(n);
    for (int i=n-1; i >= 1; i--){
        if (2*sep == calc){
            while (true){
                int T = ask(0, i-1);
                if (T==t) continue;
                if (T > t) ans[i] = 0;
                else ans[i] = 1;
                t = T;
                calc++;
                sep += (1-ans[i]);
                break;
            }
        }
        else if (abs(2*sep - calc) == 1){
            for (int j=0; j < 3+rand()%2; j++){
                int T = ask(0, i);
                if (T==t) continue;
                sep = calc-sep;
                t = T;
            }
            bool was = false;
            for (int j=0; j < 30; j++){
                int T = ask(0, i-1);
                if (T==t) continue;
                int X = 0;
                if (2*sep > calc) X = 1;
                ans[i] = X;
                sep = calc-sep;
                calc++;
                sep += 1-X;
                t=T;
                was=true;
                break;
            }
            if (!was){
                ans[i] = (2*sep < calc);
                calc++;
                sep = calc/2;
            }
        }
        else{
            while (2*sep < calc){
                int T = ask(0, i);
                if (T > t){
                    sep = calc-sep;
                    t=T;
                    break;
                }
            }
            while (true){
                int T = ask(0, i-1);
                if (T==t) continue;
                int delta = 2*sep-calc;
                if (T-t < -delta){
                    ans[i] = 1;
                    sep = calc-sep;
                    calc++;
                    t=T;
                    break;
                }
                else{
                    ans[i] = 0;
                    sep = calc-sep;
                    sep++, calc++;
                    t=T;
                    break;
                }
            }
        }
    }
    int sum = 0;
    for (int i=1; i < n; i++) sum += ans[i];
    if (sum == St) ans[0] = 0;
    else ans[0] = 1;
    cout << "! ";
    for (int i=0;i<n;i++) cout << ans[i];
    cout << endl;
    return 0;
}