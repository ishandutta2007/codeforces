#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int x,y,z;
  cin>>x>>y>>z;
  int a,b,c;
  cin>>a>>b>>c;
  if(a<x){
    cout<<"NO";
    return 0;
  }
  a-=x;
  if(a+b<y){
    cout<<"NO";
    return 0;
  }
  if(a+b+c<y+z){
    cout<<"NO";
    return 0;
  }
  cout<<"YES";
  return 0;
}