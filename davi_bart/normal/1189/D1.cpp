#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[100010];
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=0;i<=N;i++){
    if(v[i].size()==2){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
  return 0;
}