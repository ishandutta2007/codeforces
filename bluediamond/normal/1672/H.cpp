#include <bits/stdc++.h>

bool home = 1;

using namespace std;

///#define int long long

const int N=(int)2e5+7;
int n;
int q;
string str;
int a[N];
int s[2][N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>q>>str;
  for(int i=1;i<=n;i++){
    a[i]=str[i-1]-'0';
  }
  a[n+1]='#';
  for(int x=0;x<2;x++){
    for(int i=1;i<=n;i++){
      s[x][i]=s[x][i-1]+(a[i]==x&&a[i+1]==x);
    }
  }
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<max(s[0][r-1]-s[0][l-1]+1,s[1][r-1]-s[1][l-1]+1)<<"\n";
  }
}