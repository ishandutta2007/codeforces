#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ask(int a,int b){
  cout<<"? "<<a+1<<" "<<b+1<<endl;
  int k;
  cin>>k;
  return k;
}
vector<int> sol(1010);
void solve(int a,int b){
  vector<int> k;
  int tot=0;
  for(int i=a;i<b;i++){
    k.push_back(ask(i,i+1));
    if(i%2!=a%2)tot+=k.back();
  }
  sol[a]=ask(a,b)-tot;
  for(int i=a;i<b;i++){
    int y=k[i-a];
    sol[i+1]=y-sol[i];
  }
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int N;
  cin>>N;
  if(N%2)solve(0,N-1);
  else{
      solve(0,2);
      solve(3,N-1);
  }
  cout<<"! ";
  for(int i=0;i<N;i++)cout<<sol[i]<<" ";
  cout<<endl;
}