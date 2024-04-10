#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,M;
    cin>>N>>M;
    int a=N*2;
    int b=M*3;
    int c=0;
    for(int i=0;i<M;i++){
      c+=3;
      if(c%2)continue;
      if(c>a)break;
      if(a<=b){
        a+=2;
      }else{
        b+=3;
        c+=3;
      }
    }
    cout<<max(a,b);
}