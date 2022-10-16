#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n,x,a,y,b,k,p[200005];
inline void swp(int &x,int &y){
	int t=x;
	x=y;
	y=t;
	return;
}
inline int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
inline int lcm(int a,int b){
	return a*b/gcd(a,b);
}
inline bool check(int now){
	int la,lb,lab;
	lab=now/lcm(a,b);
	la=now/a-lab,lb=now/b-lab;
	int s=0;
	for (int i=1;i<=lab;i++)s+=(x+y)*p[i];
	for (int i=lab+1;i<=lab+la;i++)s+=x*p[i];
	for (int i=lab+la+1;i<=lab+la+lb;i++)s+=y*p[i];
	return s>=k; 
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%I64d",&p[i]),p[i]/=100;
		cin>>x>>a>>y>>b>>k;
		if (x<y)swp(x,y),swp(a,b);
		sort(p+1,p+1+n);
		for (int i=1;i<=n/2;i++)swp(p[i],p[n-i+1]);
		int l=1,r=n,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if (check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}