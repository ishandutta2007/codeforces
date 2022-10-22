#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> p;
  vector<int> v;
  v.push_back(0);

  map<int,bool> vis;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p.push_back(a);
    v.push_back(a);
    v[i+1]+=v[i];
  }
  int tot=0;
  for(int i=0;i<N;i++){
    for(int j=2;j<=N;j++){
      int pos=lower_bound(v.begin(),v.begin()+j-2,v[j]-p[i])-v.begin();
      if(v[pos]==(v[j]-p[i])){
          tot++;
          break;
      }
    }
  }
  cout<<tot<<'\n';
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--)solve();
    return 0;
}