#pragma GCC optimize("O3")
#include <unordered_map>
#include <iostream>
using namespace std;
int vis[500];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      string a;
      fill(vis,vis+490,0);
      cin>>a;
      for(int o=0;o<a.size();o++){
        vis[a[o]-'0']++;
      }
      bool p=0;
      int tot=0;
      for(int j=0;j<500;j++){
        if(vis[j]>0)p=1;
        if(vis[j]>1 || (vis[j]==0 && p==1)){
          break;
        }
        if(vis[j]==1)tot++;
      }
      if(tot==a.size())cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }

    return 0;
}