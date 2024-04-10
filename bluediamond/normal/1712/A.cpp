#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const int N=100+7;
int n,k,a[N];

signed main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  for(int tc=1;tc<=t;tc++){
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
      cin>>a[i];
    }
    int bad=0;
    for (int i=k+1;i<=n;i++) {
      if (a[i]<=k)bad++;
    }
    cout<<bad<<"\n";
  }
}