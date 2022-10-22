#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c)cout<<a<<" "<<c<<endl;
    else cout<<a<<" "<<c+1<<endl;
  }
}