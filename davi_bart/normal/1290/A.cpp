#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      vector<int> v;
      vector<pii> p;
      int N,M,K;
      cin>>N>>M>>K;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
      }
      for(int i=0;i<M;i++){
        p.push_back({v[i],v[N+i-M]});
      }
      K=min(K,M-1);
      int ok=M-K;
      int ma=0;
      for(int i=0;i<=M-ok;i++){
        int o=1000000000;
        for(int j=i;j<i+ok;j++){
          o=min(max(p[j].first,p[j].second),o);
        }
        ma=max(ma,o);
      }
      cout<<ma<<'\n';
    }
    return 0;
}