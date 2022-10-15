#include <bits/stdc++.h>

using namespace std;

const int N=(int)1e5+7;
const int L=31;
int n,q,a[N],sol[N];
vector<pair<int,int>> qs[N];
vector<int> mn[N];

void print(vector<int> a){
  cout<<" = ";
  for(auto&x:a) {
    cout<<x<<" ";
  }
  cout<<"\n";
}

vector<int> join(vector<int> v,int x){
  v.push_back(x);
  int i=(int)v.size()-1;
  while(i-1>=0&&v[i]<v[i-1]) {
    swap(v[i],v[i-1]);
    i--;
  }
  if((int)v.size()>L) v.resize(L);
  return v;
}

#define add(x) {sol.push_back(x); if((int)sol.size()==L) return sol;}

vector<int> merge_vecs(vector<int> a, vector<int> b) {
  vector<int> sol;
  sol.reserve(min((int)a.size()+(int)b.size(),L));
  int p=0;
  for(auto&x:a){
    while(p<(int)b.size()&&b[p]<x) add(b[p++]);
    add(x);
  }
  while(p<(int)b.size()) add(b[p++]);
  return sol;
}

void rec(int low,int high){
  assert(low<=high);
  if(low==high) {
    return;
  }
  assert(low<high);
  int mid=(low+high)/2;
  mn[mid]={a[mid]};
  mn[mid+1]={a[mid+1]};
  for(int i=mid-1;i>=low;i--) mn[i]=join(mn[i+1],a[i]);
  for(int i=mid+2;i<=high;i++) mn[i]=join(mn[i-1],a[i]);


  for(int l=low;l<=mid;l++){
    while(!qs[l].empty()){
      int r=qs[l].back().first,i=qs[l].back().second;
      assert(r<=high);
      if(r<=mid) break;
      qs[l].pop_back();
      vector<int> joint=merge_vecs(mn[l],mn[r]);
      for(int x=0;x<(int)joint.size();x++){
        for(int y=x+1;y<(int)joint.size();y++){
          sol[i]=min(sol[i],joint[x]|joint[y]);
        }
      }
    }
  }

  rec(low,mid);
  rec(mid+1,high);
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input.txt", "r", stdin);

  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++){
      int l,r;
      cin>>l>>r;
      sol[i]=(1<<30);
      qs[l].push_back({r, i});
    }
    for(int l=1;l<=n;l++) sort(qs[l].begin(),qs[l].end());

    rec(1,n);


    for(int i=1;i<=n;i++) qs[i].clear();
    for(int i=1;i<=q;i++) cout<<sol[i]<<"\n";
  }

  return 0;
}