#include <iostream>
#include <cstdio>
#define int unsigned long long
#define inf 2000000000000000000
using namespace std;
int t,n,a[105],tot;
inline void swp(int &x,int &y){
	int t=x;
	x=y;
	y=t;
	return;
}
inline int asks(int k){
	int len=1,now=9,ans=0;
	while(k>0){
		int tmp=0;
		if (k<=now){
			tmp=k*(k+1)/2;
			now*=10,k=0;
		}
		else{
			tmp=now*(now+1)/2;
			k-=now;
			tmp+=k*now;
		}
		if (tmp>=inf/len)return inf;
		ans+=tmp*len;
		if (ans>=inf)return inf;
		len++,now*=10;
	}
	return ans;
}
inline int asknum(int k){
	int len=1,now=9,ans=0;
	while(k>0){
		if (k<=now){
			ans+=len*k;
			k=0;
		}
		else{
			ans+=len*now;
			k-=now;
			len++,now*=10;
		}
	}
	return ans;
}
inline int erfen1(int now){
	int l=1,r=1e18,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (asks(mid)<now)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
inline int erfen2(int now){
	int l=1,r=1e18,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (asknum(mid)<now)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
//	freopen("1216E2.in","r",stdin);
//	freopen("1216E2.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int s=erfen1(n);
		n-=asks(s);
		int k=erfen2(n);
		n-=asknum(k);
		k++;
		tot=0;
		while(k>0)a[++tot]=k%10,k/=10;
		for (int i=1;i<=tot/2;i++)swp(a[i],a[tot-i+1]);
		cout<<a[n]<<endl;
	}
	return 0;
}