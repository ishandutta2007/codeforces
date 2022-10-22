#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> k,mosse;
int x;
int h,h1;
void f(int p){
  if(p>=(k.size()/2) || (k[2*p]==0 && k[2*p+1]==0)){
    k[p]=0;
    return;
  }
  if(k[2*p]>k[2*p+1]){
    k[p]=k[2*p];
    f(2*p);
  }else{
    k[p]=k[2*p+1];
    f(2*p+1);
  }
}
int alt(int p){
  if(p>=(k.size()/2) || (k[2*p]==0 && k[2*p+1]==0)){
    return (32-__builtin_clz(p));
  }
  if(k[2*p]>k[2*p+1])return alt(2*p);
  else return alt(2*p+1);
}
bool dfs(int pos){
  //cout<<pos<<endl;
  if(alt(pos)>h1 && x>0 && k[pos]>0){
    f(pos);
    x--;
    mosse.push_back(pos);
    return 1;
  }
  if(k[pos]==0 || pos>=k.size()/2)return 0;
  int a=1;
  while(a){
    a=dfs(pos*2);
    if(a && alt(pos)>h1 && x>0&& k[pos]>0){
      f(pos);
      x--;
      mosse.push_back(pos);
      return 1;
    }
  }
  a=1;
  while(a){
    a=dfs(pos*2+1);
    if(a && alt(pos)>h1 && x>0&& k[pos]>0){
      f(pos);
      x--;
      mosse.push_back(pos);
      return 1;
    }
  }
  return 0;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
      k.clear();
      mosse.clear();
      k.push_back(0);
      cin>>h>>h1;
      for(int i=0;i<((1<<h)-1);i++){
        int a;
        cin>>a;
        k.push_back(a);
      }
      x=((1<<h)-(1<<h1));
      while(x>0){
          dfs(1);
      }
      ll s=0;
      for(int i=0;i<k.size();i++)s+=(ll)k[i];
      cout<<s<<'\n';
      for(int i=0;i<mosse.size();i++){
        cout<<mosse[i]<<" ";
      }
      cout<<'\n';
		}
    return 0;
}