#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int pot[]={1,10,100,1000,10000};
void solve(){
  int N;
  cin>>N;
  vector<int> sol;
  string a=to_string(N);
  for(int i=0;i<a.size();i++){
    if(a[i]!='0'){
      sol.push_back((a[i]-'0')*pot[(int)a.size()-i-1]);
    }
  }
  cout<<sol.size()<<'\n';
  for(int i=0;i<sol.size();i++)cout<<sol[i]<<" ";
  cout<<'\n';
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