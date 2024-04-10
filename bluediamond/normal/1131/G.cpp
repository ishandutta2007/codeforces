#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
const int N=(int) 1e7+7;
const ll INF=(ll) 1e18+7;
int blocks,n,a[N],lft[N],rgh[N];
ll c[N],dp[N];

template<typename T>
void print(T vec[]){
  cout<<" ---> ";
  for (int i=1;i<=n;i++){
    cout<<vec[i]<<" ";
  }
  cout<<"\n";
}

int mindp[N];

struct Seg{
  int l,r;
  ll mn;
};

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  {

    cin>>blocks>>n;
    vector<pair< vector<int>,vector<int> > > dt;
    for (int iq=0;iq<blocks;iq++){
      int k;
      cin>>k;
      dt.push_back(make_pair(vector<int>(k),vector<int>(k)));
      for(auto&it:dt.back().first) cin>>it;
      for(auto&it:dt.back().second) cin>>it;
    }

    {
      int y=0;
      int q;
      cin>>q;
      while(q--){
        int id,mlt;
        cin>>id>>mlt;
        id--;
        assert(0<=id&&id<blocks);
        for (int j=0;j<(int)dt[id].first.size();j++){
          y++;
          a[y]=dt[id].first[j];
          c[y]=(ll)dt[id].second[j]*mlt;
        }
      }
      assert(y==n);
    }
  }
  for (int i=1;i<=n;i++){
    lft[i]=max(1,i-a[i]+1);
    rgh[i]=min(n,i+a[i]-1);
  }
  vector<int> stk;
  for (int i=1;i<=n;i++){
    while(!stk.empty()&&lft[stk.back()]>=lft[i]) stk.pop_back();

    if(!stk.empty()&&stk.back()>=lft[i]){
      lft[i]=lft[stk.back()];
    }

    /// lft[i] a scazut


    while(!stk.empty()&&lft[stk.back()]>=lft[i]) stk.pop_back();
    stk.push_back(i);
  }
  stk.clear();

  for (int i=n;i>=1;i--){
    while(!stk.empty()&&rgh[stk.back()]<=rgh[i]) stk.pop_back();

    if(!stk.empty()&&stk.back()<=rgh[i]){
      rgh[i]=rgh[stk.back()];
    }

    /// rgh[i] a crescut

    while(!stk.empty()&&rgh[stk.back()]<=rgh[i]) stk.pop_back();

    stk.push_back(i);
  }
  for(int i=1;i<=n;i++){
    dp[i]=INF;
  }



  vector<Seg> segs;

  for (int i=1;i<=n;i++){
    /// to da right
    dp[rgh[i]]=min(dp[rgh[i]],dp[i-1]+c[i]);
    ll best=INF;
    /// find the next lft that is smaller
    {
      int l=lft[i],r=i,ff=r;
      /// segment [l,r]
      while(!segs.empty()&&segs.back().l>=l){
        best=min(best,segs.back().mn);
        ff=segs.back().l;
        segs.pop_back();
      }
      int last=((segs.empty())?0:(segs.back().r+1));
      best=min(best,dp[r-1]);
      for(int j=last;j<=ff;j++){
        best=min(best,dp[j-1]);
      }
      segs.push_back({l,r,best});
    }
    dp[i]=min(dp[i],best+c[i]);
  }
  cout<<dp[n];
  return 0;
}