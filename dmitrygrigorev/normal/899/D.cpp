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
    if (n <= 4){
        cout << (n * (n-1)) / 2;
        return 0;
    }
    int nine, now = 5;
    for (int i=0; i < 100; i++){
        if (n < now){
            nine = i;
            break;
        }
        now *= 10;
    }
    int ans = 0;
    now /= 5;
    int c = now;
    for (int i=0; i < 5; i++){
        if (n >= now){
            ans += c / 2 + c * i;
        }
        else{
            int diff = n - (now - c) + 1;
            ans += diff*i;
            if (diff > c/2){
                ans += diff - c/2;
            }
            break;
        }
        now += c;
    }
    ans -= (n+1) / c;
    cout << ans << endl;
    return 0;
}