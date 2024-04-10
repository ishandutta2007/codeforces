#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  if(N<K){
    cout<<"NO"<<'\n';
    return ;
  }
  if((N%2)==(K%2)){
    cout<<"YES"<<'\n';
    for(int i=0;i<(K-1);i++){
      cout<<1<<" ";
      N--;
    }
    cout<<N<<'\n';
    return ;
  }
  if(N<2*K || N%2){
    cout<<"NO"<<'\n';
    return;
  }
  cout<<"YES"<<'\n';
  for(int i=0;i<K-1;i++){
    cout<<2<<" ";
    N-=2;
  }
  cout<<N<<'\n';
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