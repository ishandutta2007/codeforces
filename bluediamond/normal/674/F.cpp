#include <bits/stdc++.h>

bool home = 1;
using namespace std;

typedef long long ll;
unsigned n,p,q;
const int N=137;
unsigned int m[N];

void add(map<int, int>& F, int x, int SGN) {
  for (int p=2; p*p <= x; p++) {
    int e=0;
    while (x%p==0) {
      x/=p;
      e++;
    }
    if (e) {
      F[p]+=e*SGN;
    }
  }
  if (x>1) {
    F[x]+=1*SGN;
  }
}

unsigned int comb(int n,int k){

  map<int, int> F;

  for(int i=1;i<=k;i++){
    add(F,n+1-i,+1);
    add(F,i,-1);
  }

  unsigned int sol=1;
  for(auto&IT:F) {
    for(int j=1;j<=IT.second;j++){
      sol*=IT.first;
    }
  }
  return sol;
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

  cin>>n>>p>>q;

  p=min(n-1,p);
  for(int j=0;j<=p;j++){
    m[j]=comb(n,j);
  }

  unsigned int sol=0;

  for (unsigned int v=1;v<=q;v++){

    unsigned int cf=1,cur=0;

    for(int k=0;k<=p;k++){
      cur+=cf*m[k];
      cf*=v;
    }
    sol^=cur*v;
  }
  cout<<sol<<"\n";
}