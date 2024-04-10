#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  //freopen("ciao.txt", "r", stdin);
  //freopen("sol.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    int a,b,c;
    cin>>a>>b>>c;
    if(b>c)swap(b,c);
    int coppia=b+c-a;
    cout<<c-coppia+1<<endl;
  }
  return 0;
}