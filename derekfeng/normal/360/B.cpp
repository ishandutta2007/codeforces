#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int K,n;
ll a[2003];
vector<ll>v;
int bit[2003];
int ord[2003],cnt;
ll lo[2003],hi[2003];
bool cmp(int A,int B){
	if(lo[A]!=lo[B])return lo[A]<lo[B];
	return hi[A]>hi[B];
}
int get(ll x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int qry(int id){
	int ret=0;
	for(;id<=cnt;id+=id&-id)ret=max(bit[id],ret);
	return ret;
}
void upd(int id,int x){
	for(;id;id-=id&-id)bit[id]=max(bit[id],x);
}
bool check(ll x){
	v.clear();
	for(int i=1;i<=n;i++){
		lo[i]=a[i]-x*(n-i),hi[i]=a[i]+x*(n-i);
		v.push_back(hi[i]); 
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	cnt=(int)v.size();
	for(int i=1;i<=cnt;i++)bit[i]=0;
	for(int i=1;i<=n;i++){
		int x=ord[i];
		int ret=qry(get(hi[x]))+1;
		if(n-ret<=K)return 1;
		upd(get(hi[x]),ret);
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&K);
	if(K>n-2){puts("0");return 0;}
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	ll l=-1,r=2e9+1;
	while(r>l+1){
		ll mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%I64d",r);
}