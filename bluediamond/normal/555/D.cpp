#include <bits/stdc++.h>

bool home = 1;

using namespace std;

#define int long long

const int N=(int)2e5+7;
int n;
int q;
pair<int, int> so[N];
int x[N],inv[N],where[N],what[N];

int fnd(int i,int dir,int len){
  if(dir==+1){
    int low=i,high=n,who=i;
    while(low<=high){
      int j=(low+high)/2;
      if(abs(x[i]-x[j])<=len){
        who=j;
        low=j+1;
      }else{
        high=j-1;
      }
    }
    return who;
  }else{
    assert(dir==-1);
    int low=1,high=i,who=i;
    while(low<=high){
      int j=(low+high)/2;
      if(abs(x[i]-x[j])<=len){
        who=j;
        high=j-1;
      }else{
        low=j+1;
      }
    }
    return who;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>so[i].first;
    so[i].second=i;
  }
  sort(so+1,so+n+1);
  for(int i=1;i<=n;i++){
    x[i]=so[i].first;
    what[i]=so[i].second;
  }
  for(int i=1;i<=n;i++){
    where[what[i]]=i;
  }
  {
    for(int i=1;i<n;i++){
      assert(x[i]<x[i+1]);
    }
  }
  for(int iq=1;iq<=q;iq++){
    int i,len,dir;
    cin>>i>>len;
    dir=+1;
    i=where[i];
    while(1){
      int who=fnd(i,dir,len);
      int who2=fnd(who,dir*-1,len-abs(x[i]-x[who]));
      len=len-abs(x[i]-x[who])-abs(x[who]-x[who2]);

      if(who==who2&&who2==i) break;

      i=who2;

      if(who!=who2){
        len%=(2*abs(x[who]-x[who2]));

        if(len>=abs(x[who]-x[who2])){
          i=who;
          len-=abs(x[who]-x[who2]);
        }
        assert(len<abs(x[who]-x[who2]));
      }
    }
    cout<<what[i]<<"\n";
  }
}