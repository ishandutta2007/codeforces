#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> a(200010),b(200010);
vector<int> ans;
vector<bool> vis(200010);
vector<int> k(200010);
vector<int> last;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    for(int i=1;i<=N;i++){
      cin>>b[i];
      if(b[i]>0){
          k[b[i]]++;
      }
    }
    queue<int> q;
    for(int i=1;i<=N;i++){
       if(k[i]==0)q.push(i);
    }
    int tot=0;
    while(q.size()){
      int pos=q.front();
      q.pop();
      if(a[pos]>=0)ans.push_back(pos);
      else last.push_back(pos);
      tot+=a[pos];
      if(b[pos]==-1)continue;
      k[b[pos]]--;
      if(a[pos]>0)a[b[pos]]+=a[pos];
      if(k[b[pos]]==0)q.push(b[pos]);
    }
    cout<<tot<<'\n';
    for(int x:ans){
        if(x)cout<<x<<" ";
    }
    reverse(last.begin(),last.end());
    for(int x:last){
        if(x)cout<<x<<" ";
    }
}