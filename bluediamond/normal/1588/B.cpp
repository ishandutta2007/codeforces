/// you look sussy today
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> hidden={2,1,5,4,3};

ll smartinvs(int l,int r){
  assert(1<=l&&l<=r&&r<=hidden.size());
  l--;
  r--;
  ll sol=0;
  for (int i=l;i<=r;i++){
    for (int j=i+1;j<=r;j++){
      sol+=(hidden[i]>hidden[j]);
    }
  }
  return sol;
}

ll get(int l, int r){
  cout<<"? "<<l<<" "<<r<<endl;
  ll sol;
  cin>>sol;
  //sol=smartinvs(l,r);
  return sol;
}

signed main() {


  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    ll s=get(1,n);
    /**

    x*(x-1)/2+y*(y-1)/2=s

    let's find (x-1)*(x-2)/2+y*(y-1)/2=s2

    1 2 3 4 | 5 6 7 8 9
    4 3 2 1 | 9 8 7 6 5

    s-s2=(x*(x-1)-(x-1)*(x-2))/2=(x-1)

    **/

    int l=1, r=n, last0=0;
    while (l<=r){
      int mid=(l+r)/2;
      if (get(1,mid)==0){
        last0=mid;
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
    ll s2=get(last0+1,n);
    ll x=s-s2+1;
    ll yyminus1=2*s-x*(x-1);
    ll y=sqrt(yyminus1);
    cout<<"! "<<last0<<" "<<last0+x<<" "<<last0+x+y<<endl;
  }


  return 0;
}