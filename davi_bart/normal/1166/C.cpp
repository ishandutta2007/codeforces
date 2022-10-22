#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  int u;
  for(int i=0;i<N;i++){
    cin>>u;
    v.push_back(abs(u));
  }
  sort(v.begin(),v.end());
  long long int tot=0;
  for(int i=0;i<N;i++){
    tot+=(long long int)(lower_bound(v.begin(),v.end(),2*v[i]+1)-v.begin()-i-1);
  }
  cout<<tot;
	return 0;
}