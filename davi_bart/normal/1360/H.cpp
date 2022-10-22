#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<string,bool>t;
string meno(string a){
  string b;
  while(1){
    b=a;
    for(int i=b.size()-1;i>=0;i--){
      if(b[i]=='1'){
        b[i]='0';
        break;
      }
      b[i]='1';
    }
    if(t.count(b))a=b;
    else return b;
  }
}
string piu(string a){
  string b;
  while(1){
    b=a;
    for(int i=b.size()-1;i>=0;i--){
      if(b[i]=='0'){
        b[i]='1';
        break;
      }
      b[i]='0';
    }
    if(t.count(b))a=b;
    else return b;
  }
}
void solve(){
  t.clear();
  int N,M;
  cin>>N>>M;
  string m="0";
  int K=1<<M;
  for(int i=0;i<M-1;i++)m+="1";
  for(int i=0;i<N/2;i++)m=meno(m);
  for(int i=0;i<N;i++){
    string a;
    cin>>a;
    if(a<=m)m=piu(m);
    t[a]=1;
  }
  /*if(t[m]){
      m=piu(m);
  }*/
  cout<<m<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--)solve();
}