#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string x;
    cin>>x;
    int a=(x[0]-'0')*10+x[1]-'0';
    int b=(x[3]-'0')*10+x[4]-'0';
    while(1){
      b++;
      if(b==60){
        b=0;
        a++;
        if(a==24)a=0;
      }
      if(a%10==b/10 && a/10==b%10){
        if(a<10)cout<<0;
        cout<<a<<":";
        if(b<10)cout<<0;
        cout<<b;
        return 0;
      }
    }
}