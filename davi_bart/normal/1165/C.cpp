#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<char> sol;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  string a;
  cin>>a;
  int tot=0;
  bool even=1;
  for(int i=0;i<N;i++){
    if(i!=N-1 && even && a[i]==a[i+1]){
      tot++;
      even=!even;
    }else{
      sol.push_back(a[i]);
    }
    even=!even;
  }
  cout<<tot+sol.size()%2<<endl;
  for(int i=0;i<sol.size()-1;i++){
    cout<<sol[i];
  }
  if(sol.size()%2==0)cout<<sol.back();
	return 0;
}