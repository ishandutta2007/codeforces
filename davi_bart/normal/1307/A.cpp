#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      int N,M;
      cin>>N>>M;
      int tot;
      cin>>tot;
      for(int i=1;i<N;i++){
        int a;
        cin>>a;
        int p=min(M/i,a);
        tot+=p;
        M-=p*i;
      }
      cout<<tot<<'\n';
    }
    return 0;
}