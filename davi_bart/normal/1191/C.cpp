#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>p;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ll N,M,K;
    cin>>N>>M>>K;
    for(ll i=0;i<M;i++){
      ll a;
      cin>>a;
      p.push_back(a);
    }
    ll tot=0;
    ll pos=0;
    while(pos<M){
      ll g=p[pos]-pos;
      ll last=((g-1)/K+1)*K+1+pos;
      for(ll i=pos;i<p.size();i++){
        if(p[i]>=last){
          pos=i;
          break;
        }
        if(i==p.size()-1)pos=p.size();
      }
      tot++;
    }
    cout<<tot;
    return 0;
}