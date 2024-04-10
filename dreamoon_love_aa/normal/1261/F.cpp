#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,m,l,r;
ll mod = 998244353,inv2 = (mod+1)/2;
vector<pll> v1,v2;
vector<pll> v1f[64],v2f[64];
vector<pll> fin;
int main(){
	read(n);
	for(int i=0;i<n;i++){
		read(l);read(r);
		r+=1;
		while((l+(l&(-l)))<=r){
			v1.push_back(make_pair(l,(l+(l&(-l))-1)));
			l+=l&(-l);
		}
		while((r-(r&(-r)))>=l){
			v1.push_back(make_pair(r-(r&(-r)),r-1));
			r-=r&(-r);
		}
	}
	read(m);
	for(int i=0;i<m;i++){
		read(l);read(r);
		r+=1;
		while((l+(l&(-l)))<=r){
			v2.push_back(make_pair(l,(l+(l&(-l))-1)));
			l+=l&(-l);
		}
		while((r-(r&(-r)))>=l){
			v2.push_back(make_pair(r-(r&(-r)),r-1));
			r-=r&(-r);
		}
	}
	for(auto ct1:v1){
		pll cc = ct1;
		for(int i=0;i<60;i++){
			if(((1ll)<<i)-1 == cc.second-cc.first){
				v1f[i].push_back(cc);
				ll cn = ((1ll)<<(i+1))-1;
				if((cc.second&cn) == cn){
					cc.first-=((1ll)<<i);
				}else{
					cc.second+=((1ll)<<i);
				}
			}
		}
	}
	for(auto ct1:v2){
		pll cc = ct1;
		for(int i=0;i<60;i++){
			if(((1ll)<<i)-1 == cc.second-cc.first){
				v2f[i].push_back(cc);
				ll cn = ((1ll)<<(i+1))-1;
				if((cc.second&cn) == cn){
					cc.first-=((1ll)<<i);
				}else{
					cc.second+=((1ll)<<i);
				}
			}
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	v1.erase(unique(v1.begin(),v1.end()), v1.end());
	v2.erase(unique(v2.begin(),v2.end()), v2.end());
	for(int i=0;i<60;i++){
		sort(v1f[i].begin(),v1f[i].end());
		sort(v2f[i].begin(),v2f[i].end());
		v1f[i].erase(unique(v1f[i].begin(),v1f[i].end()), v1f[i].end());
		v2f[i].erase(unique(v2f[i].begin(),v2f[i].end()), v2f[i].end());
		//cout<<i<<' '<<v1f[i].size()<<' '<<v2f[i].size()<<endl;
		//for(auto ct:v1f[i]) cout<<"  "<<ct.first<<' '<<ct.second<<endl;
	}
	//cout<<v1.size()<<' '<<v2.size()<<endl;
	for(int i=0;i<60;i++){
		ll cs = ((1ll)<<i)-1;
		for(auto ct1:v1){
			if(ct1.second-ct1.first != cs)continue;
			for(auto ct2:v2f[i]){
				fin.push_back(make_pair(ct1.first^ct2.first,(ct1.first^ct2.first)+cs));
			}
		}
		for(auto ct1:v2){
			if(ct1.second-ct1.first != cs)continue;
			for(auto ct2:v1f[i]){
				fin.push_back(make_pair(ct1.first^ct2.first,(ct1.first^ct2.first)+cs));
			}
		}
		
	}
	//cout<<fin.size()<<endl;
	sort(fin.begin(),fin.end());
	ll ans = 0,st = fin[0].first,ed = fin[0].second;
	for(auto ct:fin){
		if(ct.first<=ed){
			ed = max(ed,(ll)ct.second);
		}else{
			ans+=(((st+ed)%mod)*((ed-st+1)%mod)%mod)*inv2%mod;
			st = ct.first;
			ed = ct.second;
		}
	}
	ans+=(((st+ed)%mod)*((ed-st+1)%mod)%mod)*inv2%mod;
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}