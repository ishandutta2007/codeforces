#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ll N,K;
    cin>>N>>K;
    ll sx=0,dx=N;
    if(N==1){
      cout<<0;
      return 0;
    }
    while(sx<dx-1){
      ll m=(sx+dx)/2;
      ll o=m+(m+1)*m/2-K;
      if(o==N){
        cout<<(m+1)*m/2-K;
        return 0;
      }
      if(o>N)dx=m;
      else sx=m;
    }
    return 0;
}