#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      vector<pair<int,int> >sol;
      int N,B;
      cin>>N>>B;
      bool k=0;
      if(N>B){
        swap(N,B);
        k=1;
      }
      B--;
      if(3*N<B){
        cout<<"NO"<<endl;
        continue;
      }
      int x=3,y=3;
      sol.push_back({x,y});
      while(B>N){
        sol.push_back({x,y+1});
        N--;
        sol.push_back({x+1,y+1});
        B--;
        sol.push_back({x,y+2});
        B--;
        sol.push_back({x-1,y+1});
        B--;
        y+=2;
      }
      x++;
      int diff=N-B;
      for(int i=0;i<diff;i++)sol.erase(sol.begin()+sol.size()-1);
      for(int i=0;i<N;i++){
        sol.push_back({x,y});
        sol.push_back({x+1,y});
        x+=2;
      }
      cout<<"YES"<<endl;
      for(int i=0;i<sol.size();i++){
        cout<<sol[i].first-k<<" "<<sol[i].second<<endl;
      }
    }
    return 0;
}