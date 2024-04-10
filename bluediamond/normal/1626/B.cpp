#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int long long

int fdigit(int x){
  while(x>=10)x/=10;
  assert(0<=x&&x<=9);
  return x;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    vector<int>s;
    {
      string str;
      cin>>str;
      for (auto &ch:str)s.push_back(ch-'0');
    }
    int n=(int)s.size();
    {
      /// can it stay the same length?
      bool ok=0;
      for (int i=n-2;i>=0;i--){
        if(s[i]+s[i+1]>=10){
          ok=1;
          for (int j=0;j<i;j++)cout<<s[j];
          cout<<s[i]+s[i+1];
          for (int j=i+2;j<n;j++)cout<<s[j];
          cout<<"\n";
          break;
        }
      }
      if(ok)continue;
    }
    cout<<s[0]+s[1];
    for (int i=2;i<n;i++)cout<<s[i];
    cout<<"\n";
  }
}