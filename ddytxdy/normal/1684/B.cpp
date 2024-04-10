#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=4500;
int T,a,b,c,x,y,z;
void solve(){
  scanf("%d%d%d",&a,&b,&c);
  z=c;
  y=b+c;
  x=(0ll+c+b+c-1)/(b+c)*(b+c)+a;
  cout<<x<<" "<<y<<" "<<z<<endl;
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}