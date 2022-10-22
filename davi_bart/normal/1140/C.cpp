#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >p;
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N,K;
		cin>>N>>K;
		for(ll i=0;i<N;i++){
      ll a,b;
      cin>>a>>b;
      p.push_back({b,a});
		}
		sort(p.begin(),p.end(),greater<pair<ll,ll> >());
		ll ma=0,s=0;
		for(ll i=0;i<N;i++){
      s+=p[i].second;
      q.push(p[i].second);
      if(i>=K){
        s-=q.top();
        q.pop();
      }
      ma=max(ma,s*p[i].first);
		}
		cout<<ma;
		return 0;
}