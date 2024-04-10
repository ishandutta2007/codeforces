#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
      int N,K;
      cin>>N>>K;
      vector<int> sol;
      ll sum=0;
      for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        sum+=a;
        if(sum%2 && sol.size()<K-1){
          sum=0;
          sol.push_back(i+1);
        }
      }
      if(sum%2==0 || sol.size()!=K-1){
        cout<<"NO"<<endl;
        continue;
      }
      sol.push_back(N);
      cout<<"YES"<<endl;
      for(int i=0;i<sol.size();i++)cout<<sol[i]<<" ";
      cout<<endl;
    }
    return 0;
}