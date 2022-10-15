#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const char no='s';
const char yes='*';

void print(int n,int p) {

  assert(0<=p&&p<n);
  for (int i=0;i<n;i++) {
    if (i<=p) {
      cout<<no;
    }else
    if (n-i<=p) {
      cout<<no;
    }else{
      cout<<yes;
    }
  }
  cout<<"\n";
}

void print(int n) {
  for (int p=0;p<n;p++) {
    print(n, p);
  }
  cout<<"------\n";
  int i1=n/2,i2=n/2;
  if (n%2) i2++;
  for (int p=0;p<n;p++) {
    if (p==i1||p==i2) cout<<yes;
    else cout<<no;
  }
  cout<<"\n";
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while (t--) {
    int nd;
    string s;
    cin>>nd>>s;
    assert((int)s.size()==nd);
    if ((int)s.size()==1) {
      cout <<"1\n";
      continue;
    }
    reverse(s.begin(),s.end());
    int sol=0;
    for (int it=0;it<2;it++) {
      reverse(s.begin(),s.end());
      int n=(int)s.size();
      int i1=n/2,i2=n/2;
      if (n%2) i2++;
      assert(0<=i1&&i1<=i2&&i2<n);
      if (s[i1]!=s[i2]) continue;
      sol++;
      while (i1-1>=0&&i2+1<n&&s[i1-1]==s[i2+1]) {
        i1--;
        i2++;
        sol++;
      }
    }
    if (nd%2==1) sol++;
    cout<<sol<<"\n";
  }

  ///print(2);


}