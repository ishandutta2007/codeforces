#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int o;
    cin>>o;
    a.push_back(o);
  }
  int tot=0;
  sort(a.begin(),a.end());
  int p=1;
  for(int i=0;i<N;i++){
    if(a[i]>=p){
      tot++;
      p++;
    }
  }
  cout<<tot;
	return 0;
}