#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      int N;
      cin>>N;
      vector<int> a(N,0),b(N,0);
      for(int i=0;i<N;i++){
        cin>>a[i];
      }
      for(int i=0;i<N;i++){
        cin>>b[i];
      }
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
      }
      cout<<'\n';
      for(int i=0;i<N;i++){
        cout<<b[i]<<" ";
      }
      cout<<'\n';
    }
    return 0;
}