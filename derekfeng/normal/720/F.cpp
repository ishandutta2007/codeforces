#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define fi first
#define se second
int n;ll K;
ll p[100004];
int b1[200004],b3[200004];
ll b2[200004];
void upd(int i,ll x,int p){
	for(;i<=2e5;i+=i&-i)b1[i]++,b2[i]+=x,b3[i]=min(b3[i],p);
}
pii qry(int i){
	ll r1=0,r2=0;
	for(;i;i-=i&-i)r1+=b1[i],r2+=b2[i];
	return {r1,r2};
}
int far(int i){
	int r=1e9;
	for(;i;i-=i&-i)r=min(r,b3[i]);
	return r;
}
int d[100004];
pii check(ll w){
	ll num=0,sum=0;
	vector<ll>all;
	for(int i=0;i<=n;i++){
		all.push_back(p[i]);
		all.push_back(p[i]+w);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	int pos=lower_bound(all.begin(),all.end(),0)-all.begin()+1;
	memset(b1,0,sizeof(b1)),memset(b2,0,sizeof(b2)),memset(b3,0x3f,sizeof(b3));
	upd(pos,0,0);
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		pos=lower_bound(all.begin(),all.end(),p[i]+w)-all.begin()+1;
		pii tmp=qry(pos);int Far=far(pos);
		if(Far<i){
			d[Far+1]++,d[i+1]--;
			num+=tmp.fi,sum+=tmp.fi*p[i]-tmp.se;
		}
		pos=lower_bound(all.begin(),all.end(),p[i])-all.begin()+1;
		upd(pos,p[i],i);
	}
	vector<int>T;
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		if(d[i]==0)T.push_back(i);
	}
	if(T.empty())return {num,sum+num*w};
	ll PRE=1e18,SUF=-1e18;
	for(int i=0;i<T[0];i++)PRE=min(PRE,p[i]);
	for(int i=T.back();i<=n;i++)SUF=max(SUF,p[i]);
	num++,sum+=SUF-PRE;
	for(int i=1;i<T.size();i++){
		int L=T[i-1],R=T[i];
		PRE=1e18,SUF=-1e18;
		for(int j=L;j<R;j++){
			PRE=min(PRE,p[j]);
			SUF=max(SUF,p[j]);
		}
		if(SUF-PRE+w>=0)sum+=SUF-PRE,num++;
	}
	return {num,sum+num*w};
}
int main(){
	scanf("%d%lld",&n,&K);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		p[i]=p[i-1]+x;
	}
	ll l=-5e9,r=5e9;
	while(r>l+1){
		ll m=(l+r)/2;
		pii tmp=check(m);
		if(tmp.fi>=K)r=m;
		else l=m;
	}
	pii tmp=check(r);
	printf("%lld",tmp.se-K*r);
}