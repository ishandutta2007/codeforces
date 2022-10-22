#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  vector<int> p;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p.push_back(a);
  }
  if(N==1 && p[0]==K){
    cout<<"YES"<<'\n';
    return;
  }
  int pos=0;
  for(int i=0;i<N;i++){
    if(p[i]==K){
        pos=i;
        break;
    }
    if(i==(N-1)){
      cout<<"NO"<<'\n';
      return ;
    }
  }
  for(int i=1;i<N;i++){
    if(p[i]==K && p[i-1]==K){
      cout<<"YES"<<'\n';
      return ;
    }
    if(i>1 && p[i]==K && p[i-2]==K){
      cout<<"YES"<<'\n';
      return ;
    }
  }
  int v=0,V=0;
  for(int i=pos+1;i<N;i++){
    if(p[i]==K){
      v=0;
      V=0;
      continue;
    }
    if(p[i]<K)v++;
    else V++;
    if((v+V)/2==v){
      cout<<"YES"<<'\n';
      return ;
    }
  }
  v=0;V=0;
  for(int i=N-1;i>=0;i--){
    if(p[i]==K){
      pos=i;
      break;
    }
  }
  for(int i=pos-1;i>=0;i--){
    if(p[i]==K){
      v=0;
      V=0;
      continue;
    }
    if(p[i]<K)v++;
    else V++;
    if((v+V)/2==v){
      cout<<"YES"<<'\n';
      return ;
    }
  }
  for(int i=0;i<N-1;i++){
    if(p[i]>K && p[i+1]>K){
      cout<<"YES"<<'\n';
      return;
    }
    if(p[i]>K && i<(N-2) && p[i+2]>K){
      cout<<"YES"<<'\n';
      return;
    }
  }
  cout<<"NO"<<'\n';
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