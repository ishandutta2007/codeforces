#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  if(N==2 || N==3){
    cout<<-1<<'\n';
    return ;
  }
  if(N==4){
    cout<<"3 1 4 2"<<'\n';
    return ;
  }
  for(int i=1;i<=N;i+=2)cout<<i<<" ";
  int last;
  if(N%2)last=N;
  else last=N-1;
  if(N%2){
    cout<<last-3<<" "<<last-1<<" ";
    last=last-5;
  }else{
    cout<<last-3<<" "<<last+1<<" "<<last-1<<" ";
    last=last-5;
  }
  for(int i=last;i>0;i-=2)cout<<i<<" ";
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