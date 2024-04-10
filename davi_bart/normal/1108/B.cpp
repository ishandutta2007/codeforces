#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>h;
vector<int> d;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    d.push_back(a);
    h[a]++;
  }
  sort(d.begin(),d.end());
  int x=d.back();
  for(int i=d.size()-2;i>=0;i--){
    if(x%d[i]!=0 || h[d[i]]==2){
        cout<<x<<" "<<d[i];
        return 0;
    }
  }
}