#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long double ld;

ld read_ld(){
  int x;
  cin>>x;
  return x;
}

const int N=(int)1e5+7;
int n;
ld p;
ld q;
ld a[N];
ld b[N];

ld solve(ld y1){
  ld y2=1;
  for (int i=1;i<=n;i++){
    y2=min(y2,(1-b[i]*y1)/a[i]);
  }
  return y1*q+y2*p;
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



  cin>>n;
  p=read_ld();
  q=read_ld();

  for(int i=1;i<=n;i++){
    a[i]=read_ld();
    b[i]=read_ld();
  }

  ///exit(0);

  ld l=0,r=(ld)1/(*max_element(b+1,b+n+1));
  for(int s=1;s<=100;s++){
    ld m=(l+r)/2;
    if(solve(m)<solve(m+1e-14)){
      l=m;
    }else{
      r=m;
    }
  }
  if(home){
    cout<<"sol = ";
  }
  cout<<fixed<<setprecision(6)<<solve(l)<<"\n";


}