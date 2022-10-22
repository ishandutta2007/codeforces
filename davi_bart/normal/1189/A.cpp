#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  string a;cin>>a;
  int zero=0,uno=0;
  for(int i=0;i<N;i++){
    if(a[i]-'0'==0)zero++;
    else uno++;
  }
  if(uno!=zero){
    cout<<1<<endl<<a;
    return 0;
  }
  cout<<2<<endl;
  cout<<a[0]<<" ";
  for(int i=1;i<N;i++)cout<<a[i];
  return 0;
}