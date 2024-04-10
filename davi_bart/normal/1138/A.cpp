#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[4];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  int ma=0,prec=-1;
  for(int i=0;i<N;i++){
    int c;
    cin>>c;
    if(c==prec){
      a[c]++;
    }else{
      prec=c;
      a[c]=1;
    }
    ma=max(ma,min(a[1],a[2]));
  }
  cout<<ma*2;
  return 0;
}