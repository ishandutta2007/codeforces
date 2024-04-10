#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> p;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      p.push_back(a);
    }
    int pk;
    bool ok=0;
    for(int i=30;i>=0;i--){
      bool a=0;
      for(int j=0;j<N;j++){
        if(((1<<i) & p[j])>0){
          if(a){
            a=0;
            break;
          }
          a=1;
          pk=j;
        }
      }
      if(a){
        ok=1;
        break;
      }

    }
    if(ok){
      cout<<p[pk]<<" ";
      p.erase(p.begin()+pk);
    }
    sort(p.begin(),p.end());
    for(int i=p.size()-1;i>=0;i--)cout<<p[i]<<" ";
    return 0;
}