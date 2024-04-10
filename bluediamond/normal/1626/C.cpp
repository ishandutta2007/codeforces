#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long

int gauss(int x){
  return x*(x+1)/2;
}


const int N=100+7;
int n;
int k[N];
int h[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    cin>>n;
    for (int i=1;i<=n;i++)cin>>k[i];
    for (int i=1;i<=n;i++)cin>>h[i];
    vector<pair<int,int>>segs;
    for (int i=1;i<=n;i++){
      segs.push_back({k[i]-h[i]+1,k[i]});
    }
    sort(segs.begin(),segs.end());
    int i=0,sol=0;
    while(i<n){
      int j=i,big=segs[j].second;
      while(j+1<n&&segs[j+1].first<=big){
        j++;
        big=max(big,segs[j].second);
      }
      sol+=gauss(big-segs[i].first+1);
    //  cout<<i<<" "<<j<<"\n";
      i=j+1;
    }
    cout<<sol<<"\n";


  }
}