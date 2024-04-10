#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a[100090];
ll memo[100090][2];
int N;
ll sol(int pos,bool riga){
  if(memo[pos][riga]>0)return memo[pos][riga];
  if(pos==N-1)return a[pos][riga];
  if(pos==N-2)return memo[pos][riga]=a[pos][riga]+sol(pos+1,!riga);
  return memo[pos][riga]=max(sol(pos+1,!riga),sol(pos+2,!riga))+a[pos][riga];
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
      ll o;
      cin>>o;
      a[i].push_back(o);
    }
    for(int i=0;i<N;i++){
      ll o;
      cin>>o;
      a[i].push_back(o);
    }
    cout<<max(sol(0,0),sol(0,1));
    return 0;
}