#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
int n,q;
string s;

struct node{
  int no_a;
  int no_b;
  int no_c;
  int no_ab;
  int no_bc;
  int no_abc;
};

node operator + (node ff,node ss){
  node sol;
  sol.no_a=ff.no_a+ss.no_a;
  sol.no_b=ff.no_b+ss.no_b;
  sol.no_c=ff.no_c+ss.no_c;
  sol.no_ab=min(ff.no_a+ss.no_ab,ff.no_ab+ss.no_b);
  sol.no_bc=min(ff.no_b+ss.no_bc,ff.no_bc+ss.no_c);
  sol.no_abc=min({ff.no_a+ss.no_abc,ff.no_ab+ss.no_bc,ff.no_abc+ss.no_c});
  return sol;
}

node t[4*N];

void upd(int v,int tl,int tr,int i,char ch){
  if(tr<i||i<tl)return;
  if(tl==tr){
    t[v].no_a=t[v].no_b=t[v].no_c=0;
    if (ch=='a')t[v].no_a=1;
    if (ch=='b')t[v].no_b=1;
    if (ch=='c')t[v].no_c=1;
    return;
  }
  int tm=(tl+tr)/2;
  upd(2*v,tl,tm,i,ch);
  upd(2*v+1,tm+1,tr,i,ch);
  t[v]=t[2*v]+t[2*v+1];
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input","r",stdin);

  cin>>n>>q>>s;
  for (int i=1;i<=n;i++)upd(1,1,n,i,s[i-1]);
  while (q--){
    int i;
    string tt;
    cin>>i>>tt;
    upd(1,1,n,i,tt[0]);
    cout<<t[1].no_abc<<"\n";
  }


  return 0;
}