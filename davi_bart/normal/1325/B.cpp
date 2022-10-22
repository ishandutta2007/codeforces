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
      set<int> v;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.insert(a);
      }
      cout<<v.size()<<'\n';

    }
    return 0;
}