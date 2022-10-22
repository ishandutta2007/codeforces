#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[500004],N;
ll s[500004];
vector<ll>all;
int f[500004];
struct Seg{
	int tr[1100000];
	void built(int i,int l,int r){
		tr[i]=-1e9;
		if(l!=r){
			int m=(l+r)>>1;
			built(i<<1,l,m),built(i<<1|1,m+1,r);
		}
	}
	void upd(int i,int l,int r,int p,int x){
		tr[i]=max(tr[i],x);
		if(l!=r){
			int m=(l+r)>>1;
			if(p<=m)upd(i<<1,l,m,p,x);
			else upd(i<<1|1,m+1,r,p,x);
		}
	}
	int qry(int i,int l,int r,int a,int b){
		if(r<a||b<l)return -1e9;
		if(a<=l&&r<=b)return tr[i];
		int m=(l+r)>>1;
		return max(qry(i<<1,l,m,a,b),qry(i<<1|1,m+1,r,a,b));
	}
}tr1,tr2;
int dp[500005];
void sol(){
	scanf("%d",&n);
	all.clear(),all.push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		all.push_back(s[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	N=all.size();
	tr1.built(1,0,N-1);
	tr2.built(1,0,N-1);
	for(int i=0;i<N;i++)dp[i]=-1e9;
	int p=lower_bound(all.begin(),all.end(),0)-all.begin();
	tr1.upd(1,0,N-1,p,0),tr2.upd(1,0,N-1,p,0),dp[p]=0;
	for(int i=1;i<=n;i++){
		int p=lower_bound(all.begin(),all.end(),s[i])-all.begin();
		f[i]=-1e9;
		if(p!=0)f[i]=max(f[i],tr1.qry(1,0,N-1,0,p-1)+i);
		if(p!=N-1)f[i]=max(f[i],tr2.qry(1,0,N-1,p+1,N-1)-i);
		f[i]=max(f[i],dp[p]);
		tr1.upd(1,0,N-1,p,f[i]-i);
		tr2.upd(1,0,N-1,p,f[i]+i);
		dp[p]=max(dp[p],f[i]);
	}
	printf("%d\n",f[n]);
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}