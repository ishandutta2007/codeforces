#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int N=(int)3e5+7;
int n, a[N];
ll pref[N];

struct node{
  ll mn;
  ll mx;
};

node operator + (node a, node b){
  return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

const ll inf=1e18;
const int K=20;
int lg[N];
node t[K][N];

node get(int l, int r){
  int k=lg[r-l+1];
  return t[k][l]+t[k][r-(1<<k)+1];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  for (int i=2;i<N;i++) lg[i]=1+lg[i/2];


  int tt;
  cin>>tt;
  for (int tc=1; tc<=tt; tc++) {

    cin>>n;
    for (int i=1;i<=n;i++){
      cin>>a[i];
      pref[i]=pref[i-1];
      if (i&1)pref[i]+=a[i];
      else pref[i]-=a[i];
      t[0][i]={inf,-inf};
      if (i%2) t[0][i].mn=pref[i];
      else t[0][i].mx=pref[i];
    }
    for (int k=1;(1<<k)<=n;k++)for (int i=1;i+(1<<k)-1<=n;i++)t[k][i]=t[k-1][i]+t[k-1][i+(1<<(k-1))];
    ll sol=0;
    vector<int>c(2,0);
    map<ll, vector<int>> unde;
    for (int l=n;l>=1;l--){
      unde[pref[l]].push_back(l);
      c[l%2]++;
      ll current=0;
      int last=n;
      for (int rest=0;rest<2;rest++){
        int solution=n+1;
        if (rest){
          int solution2=n+1;
          int lo=0,hi=c[rest];
          while (lo<=hi){
            int mid=(lo+hi)/2;
            int pz=l/2*2+rest+2*mid;
            if (get(l,pz).mn<pref[l-1]){
              solution2=pz;
              hi=mid-1;
            }else{
              lo=mid+1;
            }
          }
          solution=min(solution,solution2);
        }else{
          int solution2=n+1;
          int lo=0,hi=c[rest];
          while (lo<=hi){
            int mid=(lo+hi)/2;
            int pz=l/2*2+rest+2*mid;
            if (get(l,pz).mx>pref[l-1]){
              solution2=pz;
              hi=mid-1;
            }else{
              lo=mid+1;
            }
          }
          solution=min(solution,solution2);
        }
        last=min(last,solution-1);
      }
      if (!unde.count(pref[l-1]))continue;
      assert(sizeof(unde)/1024/1024<50);
      int lo=0,hi=unde[pref[l-1]].size()-1,soln=0;
      while (lo<=hi){
        int m=(lo+hi)/2;
        if (unde[pref[l-1]][m]<=last){
          soln=unde[pref[l-1]].size()-m;
          hi=m-1;
        }else {
          lo=m+1;
        }
      }
      sol+=soln;
    }
    cout<<sol<<"\n";

  }

  return 0;
}