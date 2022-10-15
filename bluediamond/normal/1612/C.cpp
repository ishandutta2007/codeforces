#include <bits/stdc++.h>

using namespace std;

#define int long long

int gauss(int n){
  return n*(n+1)/2;
}

int gauss(int l,int r){
  return gauss(r)-gauss(l-1);
}

int smart(int k,int t){
  assert(t<=2*k-1);
  if (t<=k)return gauss(t);
  int sol=gauss(k);
  sol+=gauss(2*k-t,k-1);
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    int k,x;
    cin>>k>>x;
    int low=1,high=2*k-1,sol=0;
    while (low<=high){
      int mid=(low+high)/2;
      if (smart(k,mid-1)<x){
        sol=mid;
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
    cout<<sol<<"\n";
  }

  return 0;
}