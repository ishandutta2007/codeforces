#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  int k=K/(N-1)*N;
  K%=(N-1);
  if(K==0)K--;
  cout<<k+K<<'\n';
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