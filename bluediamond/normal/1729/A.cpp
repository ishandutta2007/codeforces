#include <bits/stdc++.h>

using namespace std;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 /// freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    int cost1=abs(a-1);
    int cost2=abs(b-c)+abs(c-1);
    if(cost1==cost2)cout<<"3\n";
    else if(cost1<cost2)cout<<"1\n"; else cout<<"2\n";
  }

}