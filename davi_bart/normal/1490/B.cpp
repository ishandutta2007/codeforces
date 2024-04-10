#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  int a[3]={0,0,0};
  for(int i=0;i<N;i++){
    int k;
    cin>>k;
    a[k%3]++;
  }
  int mi=10000000000;
  for(int h=0;h<3;h++){
      if(a[h]>N/3)continue;
    int tot=0;
    tot+=max((int)0,a[h]-N/3);
    a[(h+1)%3]+=max((int)0,a[h]-N/3);
    a[h]=min(a[h],N/3);

    tot+=max((int)0,a[(h+1)%3]-N/3);
    a[(h+2)%3]+=max((int)0,a[(h+1)%3]-N/3);
    tot+=max((int)0,a[(h+2)%3]-N/3);
    a[h]+=max((int)0,a[(h+2)%3]-N/3);
    tot+=max((int)0,a[h]-N/3);
    mi=min(mi,tot);
  }

  cout<<mi<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}