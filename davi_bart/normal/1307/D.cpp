#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<bool> p(200010);
vector<ll> v[200010];
vector<ll> dist_0(200010,-1),dist_N(200010,-1);
vector<ll> d;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N,M,K;
    cin>>N>>M>>K;
    for(ll i=0;i<K;i++){
      ll a;
      cin>>a;
      a--;
      p[a]=1;
    }
    for(ll i=0;i<M;i++){
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    queue<pair<ll,ll> >q;
    q.push({0,0});
    while(!q.empty()){
      ll pos=q.front().first;
      ll dist=q.front().second;
      q.pop();
      if(dist_0[pos]!=-1)continue;
      dist_0[pos]=dist;
      for(ll i=0;i<v[pos].size();i++)q.push({v[pos][i],dist+1});
    }
    q.push({N-1,0});
    while(!q.empty()){
      ll pos=q.front().first;
      ll dist=q.front().second;
      q.pop();
      if(dist_N[pos]!=-1)continue;
      dist_N[pos]=dist;
      if(p[pos]){
        d.push_back(pos);
      }
      for(ll i=0;i<v[pos].size();i++)q.push({v[pos][i],dist+1});
    }
    ll ma=0;
    for(ll i=0;i<d.size()-1;i++){
      ll a=d[i],b=d[i+1];
      ll k=min(dist_0[a]+dist_N[a],dist_0[b]+dist_N[b]);
      k=min(k,dist_0[a]+dist_N[b]+1);
      k=min(k,dist_N[a]+dist_0[b]+1);
      ma=max(ma,k);
    }
    ma=min(ma,dist_0[N-1]);
    cout<<ma<<endl;
    return 0;
}