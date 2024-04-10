#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--){
    string a;
    cin>>a;
    vector<int> p(a.size(),0),v(a.size(),0);
    for(int i=0;i<a.size();i++){
      p[i]=(i>0?p[i-1]:0)+(a[i]=='1');
    }
    for(int i=a.size()-1;i>=0;i--){
      v[i]=(i<a.size()-1?v[i+1]:0)+(a[i]=='1');
    }
    int mi=min(p[a.size()-1],(ll)a.size()-p[a.size()-1]);
    for(int i=1;i<a.size();i++)mi=min(min(mi,(ll)p[i-1]+(ll)a.size()-i-v[i]),i-p[i-1]+v[i]);
    cout<<mi<<'\n';
  }
}