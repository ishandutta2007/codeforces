#include<bits/stdc++.h>
#define ll long long
#define str string
#define pb push_back
using namespace std;
int main()
{
    ll t;
    cin >> t;
    for(int i = 0; i < t; i ++){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int j = 0; j < n; j ++){
          cin >> a[j];
        }
        int p = -1;
        for(int j = 0; j < n - 1; j ++){
          if(a[j] > 0){
            p = j;
            break;
          }
        }
        if(p == -1){
          cout << 0 << endl;
        } 
        else{
          ll ans = 0;
          for(int j = 0; j < n - 1; j ++){
            ans += a[j];
          }
            for(int j = p; j < n - 1; j ++){
                if(a[j] == 0){
                  ans ++;
                }
            }
            cout << ans << endl;
        }
    }
}