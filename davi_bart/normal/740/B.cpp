#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M;
    cin>>N>>M;
    vector<int> v(N,0);
    for(int &i:v)cin>>i;
    int tot=0;
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      int s=0;
      for(int j=a-1;j<b;j++)s+=v[j];
      if(s>0)tot+=s;
    }
    cout<<tot;
}