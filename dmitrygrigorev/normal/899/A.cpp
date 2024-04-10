#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        if (x == 1) a++;
        else b++;
    }
    int ans = 0;
    for (int i=0; i <= b; i++){
        int teams = i;
        if (a < teams){
            continue;
        }
        else{
            int A = a - teams;
            ans = max(ans, teams + A/3);
        }
    }
    cout << ans << endl;
    return 0;
}