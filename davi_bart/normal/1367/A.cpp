#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
      string a;
      cin>>a;
      for(int i=0;i<a.size();i+=2)cout<<a[i];
      cout<<a.back()<<'\n';
    }
}