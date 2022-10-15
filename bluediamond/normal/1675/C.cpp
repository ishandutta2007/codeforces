#include <bits/stdc++.h>

bool home = 1;

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n;
string s;
int a[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

//  home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--) {
    cin>>s;
    n=(int)s.size();
    assert((int)s.size()==n);
    for (int i=0;i<n;i++) {
      char ch=s[i];
      assert(ch=='0'||ch=='1'||ch=='?');
      if (ch=='?') {
        a[i+1]=-1;
      }else {
        a[i+1]=ch-'0';
      }
    }

    int x=-1,y=-1;
    for (int i=1;i<=n;i++) if(a[i]==0) {x=i; break;}
    for (int i=n;i>=1;i--) if (a[i]==1) {y=i;break;}
    int sol=0;
    for (int i=1;i<=n;i++) {
      bool ok=1;
      if (x!=-1&&x<i) ok=0;
      if (y!=-1&&y>i) ok=0;
      sol+=ok;
    }
    cout<<sol<<"\n";
    /**

    **/
  }

}