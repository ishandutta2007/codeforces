#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,M;
    cin>>N>>M;
    if(__builtin_popcountll(N)>M || N<M){
      cout<<"NO";
      return 0;
    }
    cout<<"YES\n";
    priority_queue<int>q;
    for(int i=0;i<30;i++){
      if(N&(1<<i))q.push((1<<i));
    }
    while(q.size()<M){
      int x=q.top();
      q.pop();
      q.push(x/2);
      q.push(x/2);
    }
    while(q.size()){
      cout<<q.top()<<" ";
      q.pop();
    }
}