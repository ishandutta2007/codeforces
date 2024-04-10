#include <bits/stdc++.h>


using namespace std;

const int N=(int)5e5+7;
int n,nim[N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  for (int i=1;i<=100;i++) {
    set<int> s;
    for (int j=0;j<=i-2;j++){
      s.insert(nim[j]^nim[i-2-j]);
    }
    while(s.count(nim[i]))nim[i]++;
  }
  for (int i=100+1;i<N;i++){
    nim[i]=nim[i-34];
  }
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0,b=0;
    for (auto &ch:s){
      a+=(ch!='B');
      b+=(ch=='B');
    }
    if(a>b){
      cout<<"Alice\n";
      continue;
    }
    if(a<b){
      cout<<"Bob\n";
      continue;
    }
    int total=0;
    int l=0;
    while (l<n){
      int r=l;
      while(r+1<n&&s[r+1]!=s[r]){
        r++;
      }
      total^=nim[r-l+1];
      l=r+1;
    }
    cout<<((total)?("Alice"):("Bob"))<<"\n";
  }

  return 0;
}