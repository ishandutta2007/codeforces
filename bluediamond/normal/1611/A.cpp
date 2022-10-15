#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while (t--){
    string s;
    cin>>s;
    vector<int>v((int)s.size());
    for (int i=0;i<(int)s.size();i++){
      v[i]=s[i]-'0';
    }
    if(v.back()%2==0){
      cout<<"0\n";
    }else{
      if(v[0]%2==0){
        cout<<"1\n";
      }else{
        bool h=0;
        for (auto &x:v)if(x%2==0)h=1;
        if(h){
          cout<<"2\n";
        }else{
          cout<<"-1\n";
        }
      }
    }
  }

  return 0;
}