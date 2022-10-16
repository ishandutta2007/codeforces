#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int x,k;
int tot1,tot2,a[105],b[105]; 
inline void swp(int &x,int &y){
	int t=x;
	x=y;
	y=t;
	return;
}
inline int query(int now){
	tot1=tot2=0ll;
	int s=x;
	while(s)a[++tot1]=s%2ll,s/=2ll;
	for (int i=1ll;i<=tot1/2ll;i++)swp(a[i],a[tot1-i+1ll]);
	int xx=now;
	while(xx)b[++tot2]=xx%2ll,xx/=2ll;
	for (int i=1ll;i<=tot2/2ll;i++)swp(b[i],b[tot2-i+1ll]);
	int ans=0ll;
	for (int i=0ll;i<tot1-tot2;i++)ans+=(1ll<<i);
	int flag=0ll;
	for (int i=1ll;i<=tot2;i++){
		if (a[i]>b[i]){
			flag=1ll;
			break;
		}
		if (a[i]<b[i]){
			flag=2ll;
			break;
		}
	}
	if (flag==0ll){
		int p=0ll;
		for (int i=tot2+1ll;i<=tot1;i++)p=p*2ll+a[i];
		ans+=p+1ll; 
	}
	if (flag==1)ans+=1ll<<(tot1-tot2);
	return ans;
}
inline bool check(int now){
	if (now%2==0ll&&now<=x)return query(now)+query(now+1ll)>=k;
	return query(now)>=k;
} 
signed main(){
	cin>>x>>k;
	int l,r,ans=0ll;
	l=0ll,r=x/2;
	while(l<=r){
		int mid=(l+r)/2ll;
		if (mid*2+1ll<=x&&check(mid*2+1ll))ans=max(ans,mid*2+1ll),l=mid+1ll;
		else r=mid-1;
	}
	l=0ll,r=x/2;
	while(l<=r){
		int mid=(l+r)/2;
		if (mid*2<=x&&check(mid*2))ans=max(ans,mid*2),l=mid+1ll;
		else r=mid-1ll;
	}
	cout<<ans<<endl;
	return 0;
}