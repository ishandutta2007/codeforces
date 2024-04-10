#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int x,int a,int b) {
  if (x<=a) return 0;
  if (a+1<=x && x<=b) return x-a;
  if (b+1<=x) return b-a+(x-b)/2;
  cout << "why are you running???\n";
}

int opt(int n,int l1,int r1,int l2,int r2,int mana) {
  int cur=n*max(0LL,min(r1,r2)-max(l1,l2));
  int a=max(0LL,max(l1,l2)-min(r1,r2));
  int b=2*(max(r1,r2)-min(l1,l2))-(r1-l1)-(r2-l2);
  int sol=f(mana,a,b);
  int sol2=0;
  if (b>0) {
    int t=min(n,mana/b);
    mana-=t*b;
    sol2+=t*f(b,a,b);
    if (mana && t) {
      int sol3=0;
      if (t<n) {
        sol3=sol2+f(mana,a,b);
      }
      sol2-=f(b,a,b);
      sol2+=f(b+mana,a,b);
      sol2=max(sol2,sol3);
    }
  }
  sol=max(sol,sol2);
  return sol+cur;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n,wanna,l1,r1,l2,r2;
    cin>>n>>wanna>>l1>>r1>>l2>>r2;
    int lo=0,hi=(int)1e18,sol=-1;
    while (lo<=hi) {
      int mid=(lo+hi)/2;
      if (opt(n,l1,r1,l2,r2,mid)>=wanna) {
        sol=mid;
        hi=mid-1;
      } else lo=mid+1;
    }
    cout<<sol<<"\n";
  }
  return 0;
}