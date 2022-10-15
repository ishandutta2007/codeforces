#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;

  while (t--) {
    int len,n;
    cin>>len>>n;
    vector<int> a(n);
    for(auto&x:a){cin>>x;x--;}
    sort(a.begin(),a.end());
    vector<int> difs(n);
    int sd=0;
    for(int i=0;i<n;i++){
      difs[i]=(a[(i+1)%n]-a[i]+len-1)%len;
      sd+=difs[i];
    }
    assert(sd+n==len);
    sort(difs.rbegin(), difs.rend());
    int i=0,sol=0;
    for(auto &d : difs) {
      d-=4*i++;
      if(d==1){
        sol++;
      }else{
        if(d>=2)sol+=d-1;
      }
    }
    cout<<len-sol<<"\n";
  }


}

/**
**/