#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const int N=(int)1e5+7;
const int inf=(int)1e9+7;
int n,a[N],last[N];
bool need[N];

set<int> rem;

void clr(int limit) {
  while(!rem.empty()&&*rem.begin()<=limit){
    int i=*rem.begin();
    rem.erase(i);
    need[a[i]]=1;
    if(last[a[i]]>limit){
      clr(last[a[i]]);
    }
  }
}

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
    cin>>n;
    rem.clear();
    for(int i=1;i<=n;i++) {
      last[i]=0;
      need[i]=0;
      rem.insert(i);
    }
    for(int i=1;i<=n;i++) {
      cin>>a[i];
      last[a[i]]=i;
    }
    int mn=inf;
    for(int i=n;i>=1;i--){
      if(a[i]>mn){
        clr(i);
        break;
      }else{
        mn=a[i];
      }
    }
    int sol=0;
    for(int i=1;i<=n;i++){
      sol+=need[i];
    }
    cout<<sol<<"\n";
  }
}