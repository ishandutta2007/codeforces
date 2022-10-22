#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().tempo_since_epoch().count());
vector<int> v;
void solve(){
  v.clear();
  int N;
  cin>>N;
  int prec=1e6;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  for(int i=1;i<N;i++){
    if(v[i]>v[i-1] && v[i]!=(v[i-1]+1)){
      cout<<"No"<<'\n';
      return ;
    }
  }
  cout<<"Yes"<<'\n';
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
      solve();
    }
    return 0;
}