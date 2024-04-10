#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const int N=(int)4e5+7; /// change later!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
vector<int> divi[N];

int get_cnt(int x,int under){
  int sol=0;
  int low=0,high=(int)divi[x].size()-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(divi[x][mid]<=under){
      sol=mid+1;
      low=mid+1;
    }else{
      high=mid-1;
    }
  }
  return sol;
}

ll lcm(ll a, ll b) {
  return a*b/__gcd(a,b);
}

ll lcm(ll a, ll b, ll c) {
  return lcm(a,lcm(b,c));
}

ll get_dumb(ll l, ll r) {
  ll sol=0;
  set<vector<ll>> s;
  for(ll i=l;i<=r;i++) {
    for(ll j=i+1;j<=r;j++) {
      for(ll k=j+1;k<=r;k++){
        sol+=((lcm(i,j,k)>=(i+j+k)));
        bool ok1=((lcm(i,j,k)>=(i+j+k)));
        bool ok2=(lcm(lcm(j,k),i)==lcm(j,k));
        if(lcm(i,j,k)<(i+j+k)){
          assert(ok2);
          assert((lcm(j,k))%(i)==0);
          assert(lcm(j,k)/k<=2);
          assert((2*lcm(i,k))%(j)==0);
        ///  cout<<" = "<<lcm(j,k)/i<<"\n";
          ///assert(lcm(lcm(i,j),k)%lcm(i,j)==0);
          ll x=i,y=j,z=k;



          ///cout<<lcm(lcm(i,k),j)/lcm(i,k)<<"\n";
          assert(lcm(lcm(i,k),j)/lcm(i,k)<=2);
          assert(lcm(lcm(j,k),i)==lcm(j,k));
       ///   cout<<lcm(lcm(j,k),i)/lcm(j,k)<<"\n";
          continue;
         /// s.insert({i/d,j/d,k/d});
          ///cout<<"bad : "<<i/d<<" "<<j/d<<" "<<k/d<<"\n";
        }
      }
    }
  }
  int cnt=0;
  for(auto&v:s){
    cnt++;
   /// cout<<cnt<<" : "<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
  }
  return sol;
}

ll get_smart(int l, int r) {
  set<vector<ll>> s;
  ll bad=0;
  for(int k=l;k<=r;k++) {
    int over=0;
    for(auto&j:divi[k]){
      if(l<=j&&j<k){
        over++;
      }
    }
    bad+=over*(ll)(over-1)/2;
  }
  for(int k=l;k<=r;k++) {
    for(auto&j:divi[2*k]) {
      if(l<=j&&j<k) {
        int st=max(l,k+1-j),dr=j-1;
        if(st<=dr) {
          bad+=get_cnt(2*k,dr)-get_cnt(2*k,st-1);
        }
      }
    }
  }
  ll len=r-l+1;
  ll total=len*(len-1)*(len-2)/6;
  return total-bad;
}

ll solve(ll l,ll r){
  ll db=get_dumb(l,r);
  ll sm=get_smart(l,r);
  cout<<"dumb  = "<<db<<"\n";
  cout<<"smart = "<<sm<<"\n";
  assert(db==sm);
  return db;
}

signed main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  for(int i=1;i<N;i++){
    for(int j=i;j<N;j+=i){
      divi[j].push_back(i);
    }
  }

  int t;
  cin>>t;
  for(int tc=1;tc<=t;tc++){
    ll l,r;
    cin>>l>>r;
    cout<<get_smart(l,r)<<"\n";
  }
}