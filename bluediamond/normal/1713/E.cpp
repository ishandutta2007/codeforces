#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen("___input___.txt","r",stdin);

  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(auto&v:a)for(auto&x:v)cin>>x;
    vector<int> t(n),by(n,0);
    iota(t.begin(),t.end(),0);
    function<pair<int,int>(int)>get=[&](int a) {
      if(t[a]==a){
        return make_pair(a,0);
      }else{
        pair<int,int>it=get(t[a]);
        t[a]=it.first;
        by[a]^=it.second;
        return make_pair(t[a],by[a]);
      }
    };
    function<pair<int,int>(int)>get_no=[&](int a) {
      if(t[a]==a){
        return make_pair(a,0);
      }else{
        pair<int,int>it=get(t[a]);
        return make_pair(it.first,by[a]^it.second);
      }
    };
    function<void(int,int,int)>join=[&](int a,int b,int xr){
      if(get(a).first!=get(b).first){
        int v=get(a).first;
        t[get_no(a).first]=get_no(b).first;
        if((get_no(a).second^get_no(b).second)!=xr) {
          by[v]^=1;
        }
        return;
      }
    };

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++) {
        if(a[i][j]==a[j][i]) continue;
        join(i,j,a[i][j]>a[j][i]);
      }
    }

    for(int k=0;k<n;k++){
      if(get(k).second){
        for(int i=0;i<n;i++){
          swap(a[i][k],a[k][i]);
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<a[i][j]<<" ";
      }
      cout<<"\n";
    }
  }

}