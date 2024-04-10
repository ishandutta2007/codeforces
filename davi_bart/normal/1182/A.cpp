#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  if(N%2!=0){
    cout<<0;
    return 0;
  }
  long long int tot=0;
  tot=pow(2,N/2);
  cout<<tot;
  return 0;
}