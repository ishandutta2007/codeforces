#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>p;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  int o;
  for(int i=0;i<N;i++){
    cin>>o;
    p.push_back(o);
  }
  sort(p.begin(),p.end());
  if(p[p.size()-3]+p[p.size()-2]<=p[p.size()-1]){
    cout<<"NO";
    return 0;
  }
  swap(p[p.size()-2],p[p.size()-1]);
  cout<<"YES"<<endl;
  for(int i=0;i<p.size();i++){
    cout<<p[i]<<" ";
  }
  return 0;
}