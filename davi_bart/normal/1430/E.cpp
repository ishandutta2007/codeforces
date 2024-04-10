#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>pos[30];
class fen{
  public:
  const int dim=1<<19;
  vector<int> v=vector<int>(dim+1);
  void upd(int pos){
    for(int i=pos;i<=dim;i+=(i&(-i)))v[i]++;
  }
  int query(int pos){
    int t=0;
    for(int i=pos;i>0;i-=(i&(-i)))t+=v[i];
    return t;
  }
  int q(int k){
    return v[dim]-query(k);
  }
};
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int N;
  cin>>N;
  string a,t;
  cin>>a;
  t=a;
  for(int i=0;i<N;i++){
    pos[a[i]-'a'].push_back(i);
  }
  for(int i=0;i<28;i++)reverse(pos[i].begin(),pos[i].end());
  reverse(t.begin(),t.end());
  fen k;
  int ans=0;
  for(int i=0;i<N;i++){
    int y=t[i]-'a';
    int cur=pos[y].back();
    pos[y].pop_back();
    k.upd(cur+1);
    cur+=k.q(cur+1);
    ans+=abs(cur-i);
  }
  cout<<ans;
}