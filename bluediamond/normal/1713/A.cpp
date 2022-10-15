#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen("___input___.txt","r",stdin);
  int t;
  cin>>t;
  while(t--){
    int n,z=0;
    cin>>n;
    vector<vector<int>> guys(4);
    for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      assert(x==0||y==0);

      if(x==0&&y==0) {z++;continue;}
      if(x==0&&y>=0) guys[0].push_back(abs(x+y));
      if(x==0&&y<0) guys[1].push_back(abs(x+y));
      if(y==0&&x>=0) guys[2].push_back(abs(x+y));
      if(y==0&&x<0) guys[3].push_back(abs(x+y));
    }
    {
      int sum=(int)guys[0].size()+(int)guys[1].size()+(int)guys[2].size()+(int)guys[3].size();
      assert(sum==n-z);
    }
    int sol=0;
    for(auto &v:guys){
      if(v.empty())continue;
      sort(v.begin(),v.end());

      for(auto&x:v)assert(x>=0);
      sol+=2*v.back();

    }
    cout<<sol<<"\n";
  }
}