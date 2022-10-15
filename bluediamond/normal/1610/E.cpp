#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while (t--){

    int n;
    cin>>n;
    vector<int>v(n);
    for (auto &x:v){
      cin>>x;
    }
    sort(v.begin(),v.end());
    int l=0,mx=0;
    while (l<n){
      int r=l;
      while (r+1<n&&v[r+1]==v[r])r++;

/**
      last<=(first+next)/2

      2*last<=first+next
      2*last-first<=next
**/

      int sol=r-l+1;

      int first=v[r],last=v[r],lastpos=r+1;

      while (1){
        int low=lastpos,high=n-1,pot=-1;
        while (low<=high){
          int mid=(low+high)/2;
          if (2*last-first<=v[mid]){
            pot=mid;
            high=mid-1;
          }else{
            low=mid+1;
          }
        }
        if(pot==-1)break;
        sol++;
        last=v[pot];
        lastpos=pot+1;
      }



      mx=max(mx,sol);

      l=r+1;
    }
    cout<<n-mx<<"\n";
  }


  return 0;
}