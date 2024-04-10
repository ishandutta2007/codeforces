#include <bits/stdc++.h>

using namespace std;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
 // freopen("input","r",stdin);
  int t;
  cin>>t;
  while(t--){
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    vector<int>a;
    for (int i=1;i<=n;i++){
      int x;
      cin>>x;
      if(l<=x&&x<=r)a.push_back(x);
    }
    sort(a.begin(),a.end());
    int sol=0;
    for (auto &x:a){
      if (x<=k){
        k-=x;
        sol++;
      }
    }
    cout<<sol<<"\n";
  }
  return 0;
}