#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d,n,ans;
int main(int argc, char const *argv[]) {

  int n;

  cin>>a>>b>>c>>d>>n;
  for(int i=1;i<=n;i++){
    if(i%a&&i%b&&i%c&&i%d)ans++;
  }
  cout<<n-ans<<endl;
  return 0;
}