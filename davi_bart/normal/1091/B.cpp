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
    int N;
    cin>>N;
    vector<pair<int,int> >k,v;
    for(int i=0;i<N;i++){
      int a,b;
      cin>>a>>b;
      k.push_back({a,b});
    }
    for(int i=0;i<N;i++){
      int a,b;
      cin>>a>>b;
      v.push_back({a,b});
    }
    map<pair<int,int>,int>x;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        x[{k[i].first+v[j].first,k[i].second+v[j].second}]++;
      }
    }
    for(auto y:x){
      if(y.second==N){
        cout<<y.first.first<<" "<<y.first.second;
        return 0;
      }
    }
}