#include <bits/stdc++.h>

using namespace std;

#define int long long

bool smart(int a,int b,int c){
  if (a>b)swap(a,b);
  if (a==c||b==c)return 1;
  /// a<=b

  if (c>b)return 0;
  if (a==0)return 0;
  /// a<=b
  /// c<=b
  /// c = b-a*k
  /// a*k=b-c

  if ((b-c)%a==0)return 1;

  return smart(a,b%a,c);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;

  cin>>t;
  while (t--){
    int a,b,c;
    cin>>a>>b>>c;
    if (smart(a,b,c)){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }


  return 0;
}