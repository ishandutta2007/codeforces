#include <bits/stdc++.h>

using namespace std;
#define int long long

bool home = 1;
const int INF=(int)1e18+7;

typedef long long ll;
///#define int long long

vector<int> getdivis(int x){
  vector<int> sol;
  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      sol.push_back(i);
      sol.push_back(x/i);
    }
  }
  return sol;
}

int n,l,r,kzk,in,out;

vector<int> getChanges(int up,int stop){
  if(stop<=0){
    return {};
  }
  vector<int> sol;
  for(int i=1;i<=min(up,stop);i=up/(up/i)+1){
    sol.push_back(i);
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>l>>r>>kzk;

  if(l<=r){
    in=r-l+1;
  }else{
    in=n-l+1+r;
  }


  out=n-in;

  int sol=-1;

  if(kzk>=in) {/// xin=0
    int num=kzk-in;
    for(int jx=1;jx*jx<=num;jx++){
      if(num%jx==0){
        int xout=jx-n;
        if(0<=xout&&xout<=out){
          assert(num%(n+xout)==0);
          sol=max(sol,xout);

        }
        xout=num/jx-n;
        if(0<=xout&&xout<=out){
          assert(num%(n+xout)==0);
          sol=max(sol,xout);
        }
      }
    }
  }

  int print=-INF;

  for(int kpop=kzk;kpop<=kzk+1;kpop++){ /// xin>=1
    int init=kpop-in;

    { /// cycles == 0

      int k=init;
      if(1<=k&&k<=in){

        if(max(1LL,k)<=min(in,k)+out){
          sol=max(sol,min(in,k)+out);
        }
      }
    }
    int stop=init/n;
    vector<int> v0=getChanges(init-in-1,stop);
    vector<int> v1=getChanges(init-n-1,stop);
    vector<int> v2=getChanges(init-1,stop);
    vector<int> v3=getChanges(out+init+n,stop);
    for(auto&x:v1)x--;
    for(auto&x:v2)x--;
    for(auto&cycles:v0)if(1<=cycles&&cycles<=stop){int Lsum=max({1LL,(init-in-1)/cycles-n+1,(init-n-1)/(cycles+1)-(n-1)});int Rsum=min({(init-1)/cycles-n,in+out,(out+init+n)/(cycles+1)-n});if(Lsum<=Rsum){sol=max(sol,Rsum);}}
    for(auto&cycles:v1)if(1<=cycles&&cycles<=stop){int Lsum=max({1LL,(init-in-1)/cycles-n+1,(init-n-1)/(cycles+1)-(n-1)});int Rsum=min({(init-1)/cycles-n,in+out,(out+init+n)/(cycles+1)-n});if(Lsum<=Rsum){sol=max(sol,Rsum);}}
    for(auto&cycles:v2)if(1<=cycles&&cycles<=stop){int Lsum=max({1LL,(init-in-1)/cycles-n+1,(init-n-1)/(cycles+1)-(n-1)});int Rsum=min({(init-1)/cycles-n,in+out,(out+init+n)/(cycles+1)-n});if(Lsum<=Rsum){sol=max(sol,Rsum);}}
    for(auto&cycles:v3)if(1<=cycles&&cycles<=stop){int Lsum=max({1LL,(init-in-1)/cycles-n+1,(init-n-1)/(cycles+1)-(n-1)});int Rsum=min({(init-1)/cycles-n,in+out,(out+init+n)/(cycles+1)-n});if(Lsum<=Rsum){sol=max(sol,Rsum);}}


  }

  print-=n;
  sol=max(sol,print);
  cout<<sol<<"\n";


  return 0;
}