#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*vector<int> p(2000,0);
vector<int> v[1009];
vector<int> c;*/
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    int io;
    cin>>io;
    priority_queue<int>q;
    int tot=0;
    for(int i=0;i<N-1;i++){
      int a;
      cin>>a;
      q.push(a);
    }
    while(!q.empty()){
      int x=q.top();
      q.pop();
      if(x<io)break;
      tot++;
      io++;
      q.push(x-1);
    }
    cout<<tot;
    /*int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>p[i];
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      v[a-1].push_back(b-1);
      v[b-1].push_back(a-1);
    }
    c.resize(N);
    for(int i=0;i<N;i++){
      for(int j:v[i])c[i]+=p[j];
      cout<<c[i]<<" ";
    }
    cout<<endl;
    int tot=0;
    for(int i=0;i<N;i++){
      int mi=1e12,best;
      for(int j=0;j<N;j++){
        if(c[j]<mi){
          mi=c[j];
          best=j;
        }
      }
      tot+=mi;
      c[best]=1e12;
      for(int x:v[best]){
        c[x]-=p[best];
      }
      cout<<best<<" ";
    }
    cout<<tot;*/
}