#include <bits/stdc++.h>
using namespace std;

int rev[200010];
long long a[200010],b[200010],st[200010][20];

inline long long gcd(long long x,long long y)
{
	long long t;
	while(y){
		t=x;x=y;y=t%y;
	}
	return x;
}

inline long long query(int l,int r)
{
	int id=rev[r-l+1];
	return gcd(st[l][id],st[r-(1<<id)+1][id]);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++) b[i]=abs(a[i]-a[i+1]);
		int ans=1;
		if(n==1){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<n;i++) st[i][0]=b[i];
		for(int i=0;(1<<i)<=n-1;i++){
			for(int j=(1<<i);j<=min((1<<(i+1))-1,n-1);j++) rev[j]=i;
		}
		for(int i=1;i<20;i++){
			for(int j=1;j+(1<<i)-1<=n-1;j++){
				st[j][i]=gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			}
		}
		for(int i=1;i<n;i++){
			int l=i,r=n-1,cur=i-1;
			while(l<=r){
				int mid=(l+r)/2;
				if(query(i,mid)>1){
					cur=mid;l=mid+1;
				}
				else r=mid-1;
			}
			ans=max(ans,cur-i+1+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}