#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      ll a;
      cin>>a;
      if(a%14>6 || a%14==0 || a<15)cout<<"NO"<<endl;
      else cout<<"YES"<<endl;
    }
    return 0;
}