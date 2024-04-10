#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N=(int) 2e5+7;
const int INF=(int)1e18+7;
int n, a[N], s[N], l[N], r[N];
pair<int, int> t[4*N];

pair<int, int> operator + (pair<int, int> a, pair<int, int> b) {
  return {min(a.first,b.first), max(a.second, b.second)};
}

void build(int v,int tl,int tr) {
  if (tl==tr) {
    t[v]={s[tl], s[tl]};
    return;
  }
  int tm=(tl+tr)/2;
  build(2*v,tl,tm);
  build(2*v+1,tm+1,tr);
  t[v]=t[2*v]+t[2*v+1];
}

pair<int, int> get(int v,int tl,int tr,int l,int r) {
  if (tr<l||r<tl) return {INF, -INF};
  if (l<=tl&&tr<=r) return t[v];
  int tm=(tl+tr)/2;
  return get(2*v,tl,tm,l,r)+get(2*v+1,tm+1,tr,l,r);
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++) {
      cin>>a[i];
      s[i]=s[i-1]+a[i];
    }
    vector<int> stk;
    for (int i=1;i<=n;i++) {
      while (!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
      if (stk.empty()) l[i]=1; else l[i]=stk.back()+1;
      stk.push_back(i);
    }
    stk.clear();
    for (int i=n;i>=1;i--) {
      while (!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
      if (stk.empty()) r[i]=n; else r[i]=stk.back()-1;
      stk.push_back(i);
    }
    stk.clear();
    build(1,0,n);
    bool ok=1;
    for (int i=1;i<=n;i++) {
      int MX=get(1,0,n,i,r[i]).second;
      int MN=get(1,0,n,l[i]-1,i-1).first;
      ok&=(a[i]>=MX-MN);
    }
    if(ok) {
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
}

/**
**/