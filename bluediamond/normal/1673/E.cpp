#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;
#define int long long
const int N=(1<<20)+7;
const int M=(1<<20);
int n;
int k;
int a[N];
int pref[N];
int yep[N];
int sol[N];
vector<int> shibai[N];

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

  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    pref[i]=pref[i-1]+a[i];
  }


  for (int l=1;l<=n;l++){
    for(int r=l;r<=n&&pref[r]-pref[l]<=20&&a[l]*(1LL<<(pref[r]-pref[l]))<M;r++){
      assert(r-l<=21);
      int spaces_l=(l-1);
      int spaces_r=(n-r);
      int need_xor=k;
      if(spaces_l>0) spaces_l--, need_xor--;
      if(spaces_r>0) spaces_r--, need_xor--;
      need_xor=max(need_xor,0LL);
      int spaces=spaces_l+spaces_r;


      if(0<=need_xor&&need_xor<=spaces){

        if(shibai[spaces].empty()) {
          int curi=spaces;
          while(curi){
            shibai[spaces].push_back(curi);
            curi=(curi-1)&spaces;
          }
          shibai[spaces].push_back(curi);
          reverse(shibai[spaces].begin(),shibai[spaces].end());
        }
        assert(spaces<N);
        int lw=0,rh=(int)shibai[spaces].size()-1,c_sm=0;
        while(lw<=rh){
          int m=(lw+rh)/2;
          if(shibai[spaces][m]<need_xor){
            c_sm=m+1;
            lw=m+1;
          }else{
            rh=m-1;
          }
        }
        assert(pref[r]>=pref[l]);
        sol[a[l]*(1LL<<(pref[r]-pref[l]))]^=((int)shibai[spaces].size()-c_sm)%2;
      }
    }
  }

  int biggest=-1;
  for(int i=0;i<M;i++){
    if(sol[i]) biggest=i;
  }
  if(biggest==-1) biggest=0;
  for(int i=biggest;i>=0;i--){
    cout<<sol[i];
  }
  cout<<"\n";
}