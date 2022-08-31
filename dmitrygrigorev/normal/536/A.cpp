#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e18;
signed main(){
    int a, b, n;
    cin >> a >> b >> n;
    for (int i=0; i < n; i++){
        int l, m, t;
        cin >> l >> t >> m;
        int start = a + (l - 1) * b;
        int left = -1;
        int right = 1e12;
        while (right - left > 1){
            int mid = (left + right) / 2;
            int F = a + (l-1 + mid) * b;
            if (F > t){
                right = mid;
            }
            else{
                int X = F + start;
                int Y = mid+1;
                if (INF / Y >= X){
                    int eat = (X*Y) / 2;
                    if (eat <= m*t) left = mid;
                    else right = mid;
                }
                else{
                    right = mid;
                }
            }
        }
        if (left == -1) cout << -1 << endl;
        else cout << left+l << endl;
    }
    return 0;
}