#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_ok(ll n,ll sum, ll mx) {
  ll orice=(((n+1)/2)*((n+1)/2));
  ll doar=((n/2)*((n+1)/2));
  return mx<=orice+doar&&sum<=orice+2*doar;
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  int t;
  cin>>t;
  while(t--){
    int sum,k,mx=0;
    cin>>sum>>k;
    vector<int> times(k);
    for (int i=0;i<k;i++){
      cin>>times[i];
      mx=max(mx,times[i]);
    }
    int n=0;
    while(!is_ok(n,sum,mx))n++;
    vector<vector<int>> a(n,vector<int> (n,-1));

    int pm=max_element(times.begin(),times.end())-times.begin();

    vector<pair<int, int>> orice,doar1,doar2;
    for (int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(i%2==0&&j%2==0)orice.push_back({i,j});
        if(i%2==0&&j%2==1)doar1.push_back({i,j});
        if(i%2==1&&j%2==0)doar2.push_back({i,j});
      }
    }
    while(!doar1.empty()&&times[pm]>0) {
      a[doar1.back().first][doar1.back().second]=pm;
      doar1.pop_back();
      times[pm]--;
    }

    while(!orice.empty()&&times[pm]>0) {
      a[orice.back().first][orice.back().second]=pm;
      orice.pop_back();
      times[pm]--;
    }
    for (int i=0;i<k;i++) {
      if(i==pm)continue;
      while(!doar1.empty()&&times[i]>0) {
        a[doar1.back().first][doar1.back().second]=i;
        doar1.pop_back();
        times[i]--;
      }
      while(!doar2.empty()&&times[i]>0) {
        a[doar2.back().first][doar2.back().second]=i;
        doar2.pop_back();
        times[i]--;
      }

      while(!orice.empty()&&times[i]>0) {
        a[orice.back().first][orice.back().second]=i;
        orice.pop_back();
        times[i]--;
      }
    }
    for(int i=0;i<k;i++) {
      assert(times[i]==0);
    }
    cout<<n<<"\n";
    for(auto&v:a){
      for(auto&x:v){
        cout<<x+1<<" ";
      }
      cout<<"\n";
    }
  }

  exit(0);
}