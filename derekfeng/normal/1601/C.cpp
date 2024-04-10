#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bit[2000005],n,m,T;
int a[1000005],b[1000005];
vector<int>v[1000005];
void solve(int l,int r,int L,int R){
	if(r<l)return;
	int mid=(l+r)>>1;
	int cnt=0,w=1e9,pos;
	for(int i=L;i<=R;i++)if(a[i]<b[mid])cnt++;
	int S=0,B=0;
	for(int i=L;i<=R;i++){
		if(i>L){
			S+=(a[i]<b[mid]);
			B+=(a[i]>b[mid]);
		}
		if(cnt-S+B<w)w=cnt-S+B,pos=i;
	}
	v[pos].push_back(b[mid]);
	solve(l,mid-1,L,pos),solve(mid+1,r,pos,R);
}
void upd(int i){
	for(;i;i-=i&-i)bit[i]++;
}
int got(int i){
	int res=0;
	for(;i<=n+m;i+=i&-i)res+=bit[i];
	return res;
}
void sol(){
	vector<int>all;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)v[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),all.push_back(a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),all.push_back(b[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1;
	for(int i=1;i<=m;i++)b[i]=lower_bound(all.begin(),all.end(),b[i])-all.begin()+1;
	sort(b+1,b+m+1);
	solve(1,m,0,n);
	ll ans=0;
	for(int i=1;i<=n+m;i++)bit[i]=0;
	for(int i=0;i<=n;i++){
		if(i>0)ans+=got(a[i]+1),upd(a[i]);
		sort(v[i].begin(),v[i].end());
		for(auto x:v[i])ans+=got(x+1),upd(x);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}