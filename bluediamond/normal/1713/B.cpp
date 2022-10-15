#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
int n,a[N],pref[N],suf[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen("___input___.txt","r",stdin);
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    pref[1]=a[1];
    for(int i=2;i<=n;i++)pref[i]=max(pref[i-1],a[i]);
    suf[n]=a[n];
    for(int i=n-1;i>=1;i--)suf[i]=max(suf[i+1],a[i]);
    bool ok=1;
    for(int i=2;i<n;i++) {
      if(pref[i-1]>a[i]&&suf[i+1]>a[i]){
        ok=0;
      }
    }
    cout<<((ok)?("YES"):("NO"))<<"\n";
  }
}