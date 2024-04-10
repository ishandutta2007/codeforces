#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int j=0;j<N;j++){
    int K;
    cin>>K;
    bool p=0;
    for(int i=0;i<K;i++){
      char a;
      cin>>a;
      int o=a-'0';
      if(o==8 && i<=K-11)p=1;
    }
    if(p)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

	return 0;
}