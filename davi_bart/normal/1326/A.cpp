#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      int N;
      cin>>N;
      if(N==1){
        cout<<-1<<'\n';
        continue;
      }
      N--;
      if((2*N)%3==0){
        for(int i=0;i<N-1;i++){
          cout<<2;
        }
        cout<<33<<'\n';
      }else{
        for(int i=0;i<N;i++)cout<<2;
        cout<<3<<'\n';
      }
    }

    return 0;
}