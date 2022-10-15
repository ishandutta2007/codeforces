#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while(t--){
    int n,c,sol=0;
    cin>>n>>c;
    vector<int> f(101,0);
    for(int i=1;i<=n;i++){
      int a;
      cin>>a;
      f[a]++;
    }
    for (int i=0;i<=100;i++) {
      sol+=min(f[i],c);
    }
    cout<<sol<<"\n";
  }

  return 0;
}