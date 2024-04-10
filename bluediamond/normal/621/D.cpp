#include <bits/stdc++.h>

bool home=1;

using namespace std;

typedef long double ld;
const ld INF=(ld)1e18;

string str1(int i,int j,int k){
  string sol;
  sol+=(char)('x'+i);
  sol+="^";
  sol+=(char)('x'+j);
  sol+="^";
  sol+=(char)('x'+k);
  return sol;
}

string str2(int i,int j,int k){
  string sol;
  sol+="(";
  sol+=(char)('x'+i);
  sol+="^";
  sol+=(char)('x'+j);
  sol+=")";
  sol+="^";
  sol+=(char)('x'+k);
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif


  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  vector<ld> v(3);
  cin>>v[0]>>v[1]>>v[2];
  ld mx=*max_element(v.begin(), v.end());
  if (mx > 1.05) {
    ld biggest_log_log=-INF;
    string sol="";
    for (int d=0;d<3;d++){
      ld base=v[d];
      if(base<=1.05) continue;
      for(int a=0;a<3;a++){
        if(a==d) continue;
        assert(a!=d);
        int b=3-a-d;
        assert(a!=b);
        assert(d!=b);
        ld val1=log(v[a])*v[b]+log(log(v[d]));
        if(val1>biggest_log_log) biggest_log_log=val1,sol=str1(d,a,b);
      }
      for(int a=0;a<3;a++){
        if(a==d) continue;
        assert(a!=d);
        int b=3-a-d;
        assert(a!=b);
        assert(d!=b);
        ld val2=log(v[b])+log(v[a])+log(log(v[d]));
        if(val2>biggest_log_log) biggest_log_log=val2,sol=str2(d,a,b);
      }
    }
    cout<<sol<<"\n";
  }else{
    ld smallest_log_log=+INF;
    string sol="";
    for (int d=0;d<3;d++){
      for(int a=0;a<3;a++){
        if(a==d) continue;
        assert(a!=d);
        int b=3-a-d;
        assert(a!=b);
        assert(d!=b);
        ld val1=log(v[a])*v[b]+log(log((ld)1/v[d]));
        if(val1<smallest_log_log) smallest_log_log=val1,sol=str1(d,a,b);
      }
      for(int a=0;a<3;a++){
        if(a==d) continue;
        assert(a!=d);
        int b=3-a-d;
        assert(a!=b);
        assert(d!=b);
        ld val2=log(v[b])+log(v[a])+log(log((ld)1/v[d]));
        if(val2<smallest_log_log) smallest_log_log=val2,sol=str2(d,a,b);
      }
    }
    cout<<sol<<"\n";
  }
}