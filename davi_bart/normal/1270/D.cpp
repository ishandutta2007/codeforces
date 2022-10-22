#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K;
bool vis[550];
void solve1(){
	vector<ll> p;
	for(ll i=0;i<K;i++){
		ll presi=0;
		cout<<"? ";
		for(ll j=0;j<N;j++){
			if(vis[j]==0){
				cout<<j+1<<" ";
				presi++;
			}
			if(presi==K)break;
		}
		cout<<endl;
		ll a,b;
		cin>>a>>b;
		vis[a-1]=1;
		p.push_back(b);
	}
	cout<<"? ";
	for(ll i=0;i<N;i++)if(vis[i])cout<<i+1<<" ";
	cout<<endl;
	ll a,b;
	cin>>a>>b;
	sort(p.begin(),p.end());
	for(ll i=0;i<p.size();i++){
		if(p[i]==b){
			cout<<"! "<<i+1<<endl;
			return ;
		}
	}
}
void stampa(vector<ll> p){
  cout<<"? ";
  for(ll i=0;i<p.size();i++)cout<<p[i]<<" ";
  cout<<endl;
}
void solve2(){
  vector<ll> t;
  cout<<"? ";
  for(ll j=0;j<K;j++){
    cout<<j+1<<" ";
    t.push_back(j+1);
  }
  cout<<endl;
  ll a,b;
  cin>>a>>b;
  ll mi=0,ma=0;
  t[a-1]=K+1;
  stampa(t);
  ll h,hh;
  cin>>h>>hh;
  bool prec=0;
  if(hh<b)prec=1;
  t[a-1]=a;
  for(ll i=0;i<K;i++){
    if(i==a-1)continue;
    t[i]=K+1;
    stampa(t);
    ll o,oo;
    cin>>o>>oo;
    if(prec==0){
      if(oo>b)mi++;
    }else{
      if(oo==b)mi++;
    }
    t[i]=i+1;
  }
  if(prec==0)cout<<"! "<<mi+1<<endl;
  else cout<<"! "<<mi+1<<endl;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cin>>N>>K;
		if(N-K+1>=K){
			solve1();
			return 0;
		}
		solve2();
    return 0;
}