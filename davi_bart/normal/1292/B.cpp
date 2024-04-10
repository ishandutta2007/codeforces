#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > v;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll x0,y0,ax,ay,bx,by;
		ll px,py,t;
		cin>>x0>>y0>>ax>>ay>>bx>>by>>px>>py>>t;
		ll a=x0,b=y0;
		while((abs(a-px)+abs(b-py))>t && a<(ll)(2e16+100) && b<(ll)(2e16+100)){
      a=a*ax+bx;
      b=b*ay+by;
		}
		while(abs(a-px)+abs(b-py)<=t){
      v.push_back({a,b});
      a=a*ax+bx;
      b=b*ay+by;
		}
		if(!v.size()){
      cout<<0;
      return 0;
		}
		ll ma=0;
		ll prec=0;
		for(ll i=0;i<v.size();i++){
      ll j;
      ll z=t-(abs(v[i].first-px)+abs(v[i].second-py));
      for(j=prec;j<v.size();j++){
        if((abs(v[j].first-v[i].first)+abs(v[j].second-v[i].second))>z)break;
      }
      ma=max(ma,j-i);
      prec=j;
		}
		prec=v.size()-1;
		for(ll i=v.size()-1;i>=0;i--){
      ll j;
      ll z=t-(abs(v[i].first-px)+abs(v[i].second-py));
      for(j=prec;j>=0;j--){
        if((abs(v[j].first-v[i].first)+abs(v[j].second-v[i].second))>z)break;
      }
      ma=max(ma,i-j);
      prec=j;
		}
		cout<<ma<<endl;
    return 0;
}