#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;
const int N=300000+7;
int n;
int k;
int a[N];
int lft[N];
int rgh[N];
int s[N];
vector<int> w[N],difs;

int get_id_of(int x) {
  int l=0,r=(int)difs.size()-1;
  while(l<=r) {
    int m=(l+r)/2;
    if(difs[m]==x) return m;
    if(difs[m]<x) l=m+1;
    else r=m-1;
  }
  return -1;
}

int cnt_bef(int x, int limit) {
  int l=0,r=(int)w[x].size()-1,sol=0;
  while(l<=r) {
    int m=(l+r)/2;
    if(w[x][m]<=limit){
      sol=m+1;
      l=m+1;
    }else{
      r=m-1;
    }
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  //home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>k;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    s[i]=(s[i-1]+a[i])%k;
  }
  for (int i=0;i<=n;i++) difs.push_back(s[i]);
  sort(difs.begin(),difs.end());
  difs.resize(unique(difs.begin(),difs.end())-difs.begin());

  for (int i=0;i<=n;i++) {
    w[lower_bound(difs.begin(),difs.end(),s[i])-difs.begin()].push_back(i);
  }

  {
    vector<int> stk;
    for (int i=1;i<=n;i++) {
      while (!stk.empty()&&a[i]>=a[stk.back()]) stk.pop_back();
      lft[i]=((stk.empty())?(1):(stk.back()+1));
      stk.push_back(i);
    }
  }
  {
    vector<int> stk;
    for (int i=n;i>=1;i--) {
      while (!stk.empty()&&a[i]>a[stk.back()]) stk.pop_back();
      rgh[i]=((stk.empty())?(n):(stk.back()-1));
      stk.push_back(i);
    }
  }
  ll sol=0;
  for (int i=1;i<=n;i++) {
    if(i-lft[i]<=rgh[i]-i) {
      for (int l=lft[i];l<=i;l++) {
        int x=get_id_of((a[i]+s[l-1])%k);
        if(x==-1) continue;
        sol+=cnt_bef(x,rgh[i])-cnt_bef(x,i-1);
      }
    }else{
      for (int r=i;r<=rgh[i];r++) {
        int x=get_id_of((s[r]-a[i]%k+k)%k);
        if(x==-1) continue;
        sol+=cnt_bef(x,i-1)-cnt_bef(x,lft[i]-2);
      }
    }
  }

  sol-=n;
  cout<<sol<<"\n";
}