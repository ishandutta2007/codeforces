#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> p;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p.push_back(a);
  }
  int x=0,y=0,tot=0;
  int sx=0,dx=N-1;
  int prec=0;
  while(1){
    if(sx>dx)break;
    int curr=0;
    for(;sx<=dx;sx++){
      curr+=p[sx];
      if(curr>prec){
        break;
      }
    }
        x+=curr;
        prec=curr;
    tot++;
    sx++;
    if(sx>dx)break;
    curr=0;
    for(;sx<=dx;dx--){
      curr+=p[dx];
      if(curr>prec){
        break;
      }
    }
        y+=curr;
        prec=curr;
    tot++;
    dx--;
  }
  cout<<tot<<" "<<x<<" "<<y<<'\n';
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