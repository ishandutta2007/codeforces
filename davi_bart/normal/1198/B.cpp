#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>soldi;
int last_upd[200010];
int regali[200010], regmax[200010];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  soldi.push_back(0);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    soldi.push_back(a);
  }
  int Q;
  cin>>Q;
  for(int i=1;i<=Q;i++){
    int a,b,c;
    cin>>a;
    if(a==1){
      cin>>b>>c;
      soldi[b]=c;
      last_upd[b]=i;
    }else{
      cin>>b;
      regali[i]=b;
    }
  }
  for(int i=200005;i>0;i--){
    regmax[i]=max(regmax[i+1],regali[i]);
  }
  for(int i=1;i<=N;i++){
    cout<<max(soldi[i],regmax[last_upd[i]+1])<<" ";
  }
  return 0;
}