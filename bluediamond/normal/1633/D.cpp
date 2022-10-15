#include <bits/stdc++.h>


using namespace std;

bool home = 1;

const int N=(int)1e3+7;
const int K=(int)1e6+7;
int n,k;
int want[N];
int gold[N];
int best[K];
int pay[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  {
    vector<int> que={1};
    for (int i=1;i<N;i++)pay[i]=-1;
    pay[1]=0;
    for (int it=0;it<(int)que.size();it++){
      int a=que[it];
      for (int x=1;x<=a;x++){
        int b=a+a/x;
        if(1<=b&&b<N&&pay[b]==-1){
          pay[b]=1+pay[a];
          que.push_back(b);
        }
      }
    }
  }

  int tests;
  cin>>tests;
  while(tests--){
    cin>>n>>k;
    for (int i=1;i<=n;i++)cin>>want[i];
    for (int i=1;i<=n;i++)cin>>gold[i];
    vector<pair<int,int>>ofs;
    for (int i=1;i<=n;i++){
      ofs.push_back({pay[want[i]],gold[i]});
    }

    int limit=0;

    for (auto &it:ofs){
      assert(limit<K);
      int cost=it.first,get=it.second;
      ///cout<<cost<<" "<<get<<"\n";
      for (int j=limit;j>=0;j--){
        best[j+cost]=max(best[j+cost],best[j]+get);
      }
      limit+=cost;
      for (int j=1;j<=limit;j++){
        best[j]=max(best[j-1],best[j]);
      }

    }
      assert(limit<K);
    if(k>limit)k=limit;

    cout<<best[k]<<"\n";

    for (int i=0;i<=limit;i++)best[i]=0;

  }

  return 0;
}