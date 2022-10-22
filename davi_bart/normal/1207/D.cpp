#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=998244353;
vector<pair<ll,ll> >v;
vector<ll> a,b;
ll aa[300010],bb[300010];
vector<ll> fact;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		fact.push_back(1);
		for(ll i=1;i<300010;i++){
			fact.push_back((fact.back()*i)%mod);
		}
		ll N,tot=0;
		cin>>N;
		for(ll i=0;i<N;i++){
			ll c,d;
			cin>>c>>d;
			a.push_back(c);b.push_back(d);
			aa[c]++;bb[d]++;
			v.push_back({c,d});
		}
		sort(a.begin(),a.end());sort(b.begin(),b.end());
		a.resize(unique(a.begin(),a.end())-a.begin());
		b.resize(unique(b.begin(),b.end())-b.begin());
		if(a.size()==0 || b.size()==0){
			cout<<0;
			return 0;
		}
		ll aaa=1,bbb=1;
		for(ll i=0;i<a.size();i++){
			if(i==0)aaa*=fact[aa[a[i]]-1];
			else aaa*=fact[aa[a[i]]];
			aaa%=mod;
		}
		for(ll i=0;i<b.size();i++){
			if(i==0)bbb*=fact[bb[b[i]]-1];
			else bbb*=fact[bb[b[i]]];
			bbb%=mod;
		}
		sort(v.begin(),v.end());
		ll molt=0;
		ll comuni=1;
		for(int i=1;i<N;i++){
      if(v[i].second<v[i-1].second){
        comuni=0;
        break;
      }
		}
		for(ll i=1;i<N;i++){
			if(v[i].first==v[i-1].first && v[i].second==v[i-1].second)molt++;
			else{
				comuni*=fact[molt];
				comuni%=mod;
				molt=1;
			}
		}
		comuni*=fact[molt];
		comuni%=mod;
		for(ll i=0;i<N;i++){
			tot+=fact[N-1];
			if(v[i].first==a[0])tot-=aaa;
			if(v[i].second==b[0])tot-=bbb;
			if(v[i].first==a[0] && v[i].second==b[0])tot+=comuni;
			tot+=5*mod;
			tot%=mod;
		}
		cout<<tot;
		return 0;
}