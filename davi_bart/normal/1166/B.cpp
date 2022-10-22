#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
char voc[5]={'a','e','i','o','u'};
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int K,N=0,M=0;
  cin>>K;
  if(K<25){
    cout<<-1;
    return 0;
  }
  for(int i=5;i<K;i++){
    if(K%i==0 && K/i>4){
      N=i;
      M=K/i;
      break;
    }
  }
  if(N+M==0){
    cout<<-1;
    return 0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<voc[(i+j)%5];
    }
  }
	return 0;
}