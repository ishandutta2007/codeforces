#include <bits/stdc++.h>

using namespace std;

bool home=1;
typedef long long ll;
#define int ll

const int INF=(int)1e18;

vector<int> operator + (vector<int> a, vector<int> b) {
  for (auto &x : b) {
    a.push_back(x);
  }
  return a;
}

vector<int> place(int n) {
  vector<int> sol;
  for (int d=2;d*d<=n;d++){
    bool e=0;
    while (n%d==0)e=1,n/=d;
    if (e)sol.push_back(d);
  }
  if (n>1)sol.push_back(n);
  return sol;
}

const int N=(int)1e6+7;
int n,c1,c2,a[N],pref[N],suf[N],lol[N];
bool ok[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int sol=INF;

  cin>>n>>c1>>c2;
  for (int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<int>d;
  for (int x=-1;x<=+1;x++){
  d=d+place(a[1]+x);
  d=d+place(a[n]+x);

  }

  for (auto &p:d){
    int cbad=0;
    for (int i=1;i<=n;i++) {
      int r=a[i]%p;
      ok[i]=(r==0||r==1||r==p-1);
      cbad+=!ok[i];
      pref[i]=pref[i-1]+c2*(r!=0);
    }
    for (int i=1;i<=n;i++)suf[i]=pref[n]-pref[i-1];
    lol[n]=INF;
    for (int i=n-1;i>=1;i--)lol[i]=min(lol[i+1],i*c1+suf[i+1]);
    if (cbad==0){
      sol=min(sol,pref[n]);
      for (int l=1;l<=n;l++){
        int cur=INF;
        for (int r=n;r<=n;r++){
          if (l==1&&r==n)continue;
          cur=min(cur,r*c1+suf[r+1]);
        }
        cur=min(cur,lol[l]);
        sol=min(sol,cur+pref[l-1]+(1-l)*c1);
      }
    }else{
      int st=0,dr=0;
      for (int i=1;i<=n;i++)if (!ok[i]){
        if (st==0)st=i;
        dr=i;
      }
      /// [st,dr]
      for (int l=1;l<=st;l++){
        int cur=INF;
        for (int r=n;r<=n;r++){
          if (l==1&&r==n)continue;
          cur=min(cur,r*c1+suf[r+1]);
        }
        cur=min(cur,lol[dr]);
        sol=min(sol,cur+pref[l-1]+(1-l)*c1);
      }
    }
  }

  cout<<sol<<"\n";

  return 0;
}