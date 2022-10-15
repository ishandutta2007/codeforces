#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;

const int N=(int)1e5+7;
int is[26];
int n;
int v[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  //home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--){
    string s;
    cin>>n;
    cin>>s;
    for (int i=0;i<26;i++) is[i]=0;
    int k;
    cin>>k;
    for (int i=0;i<k;i++) {
      string ch;
      cin>>ch;
      assert((int)ch.size()==1);
      int val=ch[0]-'a';
      assert(0<=val&&val<26);
      is[val]=1;
    }
    assert((int)s.size()==n);
    for (int i=1;i<=n;i++) {
      int x=s[i-1]-'a';
      assert(0<=x&&x<26);
      v[i]=is[x];
    }
    const int INF=(int)1e9+7;
    int d=-INF,sol=0;
    for (int i=n;i>=1;i--) {
      d++;
      sol=max(sol,d);
      if (v[i]==1) {
        d=0;
      }
    }
    cout<<sol<<"\n";
  }

}