#include <bits/stdc++.h>

using namespace std;

bool home = 1;

#define int long long

const int N=5000+7;
const int INF=(int)1e9;
int ok[N][N];
/**
0 = bad
1 = take
2 = don't take
3 = take and terminate
**/
int n,k,want,a[N],full[N],simi;
vector<vector<int>> all;

void op(int cnt,int i,int j){
  if(cnt==0)return;
  assert(i!=j);
  assert(1<=i&&i<=n);
  assert(1<=j&&j<=n);
  all.push_back({cnt,i,j});
  int take=min(a[i],k*cnt);
  a[i]-=take;
  a[j]+=take;
}

int rep(int x){
  x%=k;
  if(x<0)x+=k;
  return x;
}

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


  cin>>n>>k>>want;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    simi+=a[i];
    full[i]=a[i]/k;
  }

  if(simi<want){
    cout<<"NO\n";
    return 0;
  }
  if(want%k==0){
    for(int i=2;i<=n;i++){
      op(INF,i,1);
    }
    op(want/k,1,2);
    assert(a[2]==want);

cout<<"YES\n";
  for(auto&it:all){

    cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
  }
    exit(0);
  }
/**
0 = bad
1 = take
2 = don't take
3 = take and terminate
**/
  for(int i=1;i<=n;i++){
    for(int b=0;b<k;b++){
      if(ok[i-1][b]){
        ok[i][b]=2;
        ok[i][(b+a[i])%k]=1;
      }
    }
    ok[i][a[i]%k]=3;
  }

  /// simi>=want
  int r=(want%k);
  if(!ok[n][r]){
    cout<<"NO\n";
    return 0;
  }



  vector<int> inds;
  int i=n;
  while(1){
    assert(i>=1);
    assert(ok[i][r]);
    int type=ok[i][r];
    if(type%2==1){
      inds.push_back(i);
      r=rep(r-a[i]);
    }
    if(type==3) {
      break;
    }
    i--;
  }

  //assert(r==0);
  assert(!inds.empty());

  int root=inds[0];

  cout<<"YES\n";


  set<int> tro;
  tro.insert(root);
  for(int i=1;i<(int)inds.size();i++){
    int guy=inds[i];
    op(INF,guy,root);
    tro.insert(guy);
  }

  vector<int> no;

  for(int i=1;i<=n;i++){
    if(!tro.count(i)){
      no.push_back(i);
     /// op(a[i]/k,i,root);
    }
  }

  assert(a[root]%k==want%k);

  int oth=1;
  if(root==1){
    oth=2;
  }
  if(a[root]>=want){
    op((a[root]-want)/k,root,oth);
  }else{
    assert(a[root]<want);
    if(!no.empty()){
      for(auto&i:no){
        if(i!=no[0]){
          op(INF,i,no[0]);
        }
      }
      op((want-a[root])/k,no[0],root);

    }
  }
  assert(a[root]==want);





  assert(a[root]==want);
  for(auto&it:all){
    cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
  }
  ///assert(a[root]>=want);

  /**

  def op(i, j):
    t = min(v[i], k)
    v[i] -= t
    v[j] += t

  **/

  return 0;
}