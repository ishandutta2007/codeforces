#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 kk(490571098);
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		ll sx=0,dx=1e9+1;
		ll t=0;
		while(sx<dx-1){
      t++;
      ll m=(sx+dx)/2;
      cout<<"> "<<m<<endl;
      ll a;
      cin>>a;
      if(a)sx=m;
      else dx=m;
		}
		ll x=sx+1;
		vector<ll> p;
		vector<ll> kkk;
		for(int i=0;i<N;i++)kkk.push_back(i);
		shuffle(kkk.begin(),kkk.end(),kk);
		for(ll i=0;i<min(60-t,N);i++){
      cout<<"? "<<kkk[i]+1<<endl;
      ll a;
      cin>>a;
      if(a!=x)p.push_back(a);
		}
		p.push_back(x);
		sort(p.begin(),p.end());
		reverse(p.begin(),p.end());
		vector<ll> di;
		ll diff=p[0]-p[1];
		for(ll i=1;i*i<=diff;i++){
      if(diff%i==0){
        di.push_back(i);
        di.push_back(diff/i);
      }
		}
		for(ll i=0;i<di.size();i++){
      bool ok=1;
      for(ll j=1;j<p.size();j++){
        ll g=p[0]-p[j];
        if(g%di[i]==0 && g/di[i]<(N-p.size()+j+1))continue;
        ok=0;
        break;
      }
      if(ok && p[0]-(N-1)*di[i]>=0){
        cout<<"! "<<p[0]-(N-1)*di[i]<<" "<<di[i]<<endl;
        return 0;
      }
		}
    return 0;
}