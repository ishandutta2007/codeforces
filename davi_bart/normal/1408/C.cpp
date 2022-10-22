#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,L;
  cin>>N>>L;
  vector<int>p(N+2);
  for(int i=1;i<=N;i++)cin>>p[i];
  p[N+1]=L;
  p[0]=0;
  ld sx=0,dx=1e9;
  while(dx-sx>1e-8){
    ld m=(sx+dx)/2;
    ld posa=0,a=m;
    int va=1;
    for(int i=1;i<p.size();i++){
      ld timea=(p[i]-posa)/(ld)va;
      if(timea<=a){
        a-=timea;
        va++;
        posa=p[i];
      }else{
        posa+=a*va;
        break;
      }
    }

    ld posb=L,b=m;
    int vb=1;
    for(int i=p.size()-2;i>=0;i--){
      ld timeb=(posb-p[i])/(ld)vb;
      if(timeb<=b){
        b-=timeb;
        vb++;
        posb=p[i];
      }else{
        posb-=b*vb;
        break;
      }
    }
    //cout<<m<<" ";
    //cout<<posa<<" "<<posb<<endl;
    if(posa>=posb)dx=m;
    else sx=m;
  }
  cout<<fixed<<setprecision(20)<<sx<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}