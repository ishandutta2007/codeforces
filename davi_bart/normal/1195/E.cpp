#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tot=0;
ll h[3009][3009];
ll mi[3009][3009];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ll N,M,a,b;
    cin>>N>>M>>a>>b;
    ll g,x,y,z;
    cin>>g>>x>>y>>z;
    ll d1=0,d2=0;
    for(ll i=0;i<N*M;i++){
      h[d1][d2]=(ll)(g);
      d2++;
      if(d2==M){
        d2=0;
        d1++;
      }
      g=(g*x+y)%z;
    }
    for(ll j=0;j<M;j++){
      deque<ll> q;
      for(ll i=N-1;i>=0;i--){
        ll p=h[i][j];
        while(q.size()>0 && p<q.back())q.pop_back();
        q.push_back(p);
        mi[i][j]=q.front();
        if(i<=N-a){
          ll k=h[i+a-1][j];
          if(q.front()==k)q.pop_front();
        }
      }
    }
    for(ll i=0;i<=N-a;i++){
      deque<ll> q;
      for(ll j=M-1;j>=0;j--){
        ll p=mi[i][j];
        while(q.size()>0 && p<q.back())q.pop_back();
        q.push_back(p);
        if(j<=M-b)tot+=q.front();
        if(j<=M-b){
          ll k=mi[i][j+b-1];
          if(q.front()==k)q.pop_front();
        }
      }
    }
    cout<<tot;
    return 0;
}