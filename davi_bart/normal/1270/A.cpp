#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      int N,a,b;
      cin>>N>>a>>b;
      bool p=0;
      for(int i=0;i<a;i++){
        int o;
        cin>>o;
      }
      for(int i=0;i<b;i++){
        int o;
        cin>>o;
        if(o==N)p=1;
      }
      if(p==0)cout<<"YES"<<'\n';
      else cout<<"NO"<<'\n';
    }
    return 0;
}