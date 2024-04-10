#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  //ios_base::sync_with_stdio(0);
  float H,L;
  cin>>H>>L;
  float a=(L*L+H*H)/(2*H)-H;
  printf("%.12f",a);
  return 0;
}