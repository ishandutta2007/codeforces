#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
set<pair<int,int> >vis;
struct node{
  int ma=0;
  int add=0;
};
vector<node> s(1<<21);
int dim=1<<20;
int sx(int p){return p*2;}
int dx(int p){return p*2+1;}
void upd(int pos,int l,int r,int a,int b,int val){
  if(a<=l && r<=b)s[pos].add+=val;
  if(s[pos].add){
    if(pos<dim){
      s[sx(pos)].add+=s[pos].add;
      s[dx(pos)].add+=s[pos].add;
    }
    s[pos].ma+=s[pos].add;
    s[pos].add=0;
  }
  if(b<l || r<a)return ;
  if(a<=l && r<=b)return ;
  upd(sx(pos),l,(l+r)/2,a,b,val);
  upd(dx(pos),(l+r)/2+1,r,a,b,val);
  s[pos].ma=max(s[sx(pos)].ma,s[dx(pos)].ma);
}
int query(int pos,int l,int r,int a,int b){
  if(s[pos].add){
    if(pos<dim){
      s[sx(pos)].add+=s[pos].add;
      s[dx(pos)].add+=s[pos].add;
    }
    s[pos].ma+=s[pos].add;
    s[pos].add=0;
  }
  if(b<l || r<a)return 0;
  if(a<=l && r<=b)return s[pos].ma;
  return max(query(sx(pos),l,(l+r)/2,a,b),query(dx(pos),(l+r)/2+1,r,a,b));
}
multiset<int> v;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M,K;
    cin>>N>>K>>M;
    for(int i=1;i<=2*N;i++)upd(1,0,dim-1,i,i,i);
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      int pos=b+abs(a-K);
      //cout<<"pos="<<pos<<'\n';
      if(vis.find({a,b})!=vis.end()){
        vis.erase({a,b});
        v.erase(v.find(-pos));
        upd(1,0,dim-1,0,pos,-1);
      }else{
        vis.insert({a,b});
        v.insert(-pos);
        upd(1,0,dim-1,0,pos,1);
      }
      cout<<max((ll)0,query(1,0,dim-1,0,-(*v.begin()))-N-1)<<'\n';
    }
}