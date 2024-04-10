#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int a,b,c;
  cin>>a>>b>>c;
  int prec=0;
  if(a>0)for(int i=0;i<a+1;i++)cout<<0;
  if(c>0)for(int i=0;i<c+1;i++)cout<<1;
  if(c>0)prec=1;
  if(a>0 && c>0)b--;
  if(a==0 && c==0)b++;
  for(int i=0;i<b;i++){
      prec=!prec;
    cout<<prec;
  }
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