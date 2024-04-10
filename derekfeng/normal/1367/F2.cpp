#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int T,n,a[200005];
vector<pii>all;
int dq[200005];
int s,t;
int bit[200005];
void upd(int i,int x){
	for(;i;i-=i&-i)bit[i]=max(bit[i],x);
}
int qry(int i){
	int res=0;
	for(;i<=n;i+=i&-i)res=max(res,bit[i]);
	return res;
}
int got(int i){
	return max(dq[i],qry(i));
}
void solve(){
	all.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),all.push_back({a[i],i}),bit[i]=0,dq[i]=0;
	sort(all.begin(),all.end());
	int ans=0;
	s=1,t=0;
	for(int i=0,j;i<n;){
		vector<int>pos;
		for(j=i;j<n&&all[i].fi==all[j].fi;j++)pos.push_back(all[j].se);
		ans=max(ans,j-i);
		for(int j=1,k=pos.size()-1;j<=pos.size();j++,k--){
			int x=pos[k];
			if(s<=t&&got(t)<x){
				int ld=s-1,rd=t+1;
				while(ld+1<rd){
					int md=(ld+rd)/2;
					if(got(md)<x)rd=md;
					else ld=md;
				}
				ans=max(ans,t-rd+1+j);
			}
		}
		while(s<=t&&got(s)>pos[0])s++;
		if(s<=t)upd(t,pos.back());
		for(int k=pos.size()-1;~k;k--)dq[++t]=pos[k];
		i=j;
	}
	printf("%d\n",n-ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
}