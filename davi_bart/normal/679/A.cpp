#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int>p;
    for(int i=2;i<50;i++){
      bool k=1;
      for(int j=2;j*j<=i;j++){
        if(i%j==0)k=0;
      }
      if(k){
          p.push_back(i);
          if(i*i<100)p.push_back(i*i);
      }
    }
    int t=0;
    for(int i=0;i<19;i++){
      cout<<p[i]<<endl;
      string a;
      cin>>a;
      if(a=="yes")t++;
    }
    if(t>1)cout<<"composite";
    else cout<<"prime";
}