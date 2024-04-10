#include<bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  int res = 0;
  res += 2*min(a,c)*b+min(a,c)*min(a,c);
  res += 2*min(d,f)*e+min(d,f)*min(d,f);
  res += 2*(b+min(a,c))*(max(a,c)+max(d,f)-(c+d));
  cout<<res<<endl;
}