#include <bits/stdc++.h>

using namespace std;

signed main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int n=(int)s.size();
    vector<int> digits(n), mn(n);
    for (int i=0;i<n;i++) {
      digits[i]=s[i]-'0';
      assert(0<=digits[i]&&digits[i]<=9);
      mn[i]=digits[i];
    }
    for (int i=n-2;i>=0;i--){
      mn[i]=min(mn[i+1],mn[i]);
    }
    /**

    **/
    vector<int> hand(10,0);
    for (int i=0;i<n;i++) {
      if (mn[i]==digits[i]){
        for (int x=0;x<=digits[i];x++) {
          while(hand[x]){
            cout<<x;
            hand[x]--;
          }
        }
        cout<<mn[i];
        continue;
      }
      hand[min(9,digits[i]+1)]++;
    }
    for (int x=0;x<=9;x++) {
      while(hand[x]){
        cout<<x;
        hand[x]--;
      }
    }
    cout<<"\n";
  }

  return 0;
}