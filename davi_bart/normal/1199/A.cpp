#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N,p,d;
  cin>>N>>p>>d;
  vector<int>v;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  for(int i=0;i<N;i++){
    bool ok=0;
    for(int j=i-1;j>=max(0,i-p);j--){
      if(v[j]>v[i])continue;
      ok=1;
      break;
    }
    for(int j=i+1;j<=min(N-1,i+d);j++){
      if(v[j]>v[i])continue;
      ok=1;
      break;
    }
    if(ok==0){
      cout<<i+1;
      return 0;
    }
  }
  return 0;
}