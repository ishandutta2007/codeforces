#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> v(N);
  vector<int> prec(N),succ(N);
  for(int i=1;i<N;i++)prec[i]=i-1;
  prec[0]=N-1;

  for(int i=0;i<N-1;i++)succ[i]=i+1;
  succ[N-1]=0;


  for(int &i:v)cin>>i;
  queue<int> q;

  vector<int> ans;
  int salta=-1;
  vector<bool>tolto(N,0);

  vector<int> p;
  for(int i=1;i<N;i++)p.pb(i);
  p.pb(0);

  while(p.size()){
    set<int> prox;
    for(int i=0;i<p.size();i++){
      int pos=p[i];
      //cout<<pos<<endl;
      if(tolto[pos])continue;

      if(pos==salta){
        prox.insert(pos);
        salta=-1;
        continue;
      }

      if(gcd(v[pos],v[prec[pos]])==1){
        ans.pb(pos);
        tolto[pos]=1;
        salta=succ[pos];
        prox.insert(succ[pos]);
        succ[prec[pos]]=succ[pos];
        prec[succ[pos]]=prec[pos];
      }
    }
    p.clear();
    for(int k:prox)p.pb(k);
    if(p[0]==0 && p.size()>1){
      p.erase(p.begin());
      p.pb(0);
    }
  }

  /*for(int i=1;i<N;i++)q.push(i);
  q.push(0);


  while(q.size()){
    int pos=q.front();
    q.pop();
    //cout<<pos+1<<endl;
    if(tolto[pos])continue;

    if(salta==pos){
      q.push(pos);
      salta=-1;
      continue;
    }
    salta=-1;

    if(gcd(v[pos],v[prec[pos]])==1){
      ans.pb(pos);
      tolto[pos]=1;
      salta=succ[pos];
      //q.push(succ[pos]);
      succ[prec[pos]]=succ[pos];
      prec[succ[pos]]=prec[pos];
    }
  }*/
  cout<<ans.size()<<" ";
  for(int o:ans)cout<<o+1<<" ";
  cout<<'\n';

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}