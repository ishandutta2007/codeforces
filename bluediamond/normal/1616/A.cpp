#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while (t--)
  {
    int n;
    cin>>n;
    map<int,int>mp;
    for (int i=1;i<=n;i++) {
      int x;
      cin>>x;
      mp[abs(x)]++;
    }
    int mx=0;
    for (auto &it:mp){
      if(it.first==0)mx+=min(1,it.second);else
      mx+=min(2,it.second);
    }

    cout<<mx<<"\n";
  }
}