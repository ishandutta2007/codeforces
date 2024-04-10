#include <iostream>
#include <cstdio>
#include <cmath> 
#define int long long
using namespace std;
int xa,ya,xb,yb,x,y;
int n,c[100005],d[100005];
char s[100005];
inline int check(int i){
	return abs(x-(c[i%n]+c[n]*(i/n)))+abs(y-(d[i%n]+d[n]*(i/n)))<=i;
}
signed main(){
	cin>>xa>>ya>>xb>>yb>>n;
	scanf("%s",s+1);
	x=xb-xa,y=yb-ya;
	for (int i=1;i<=n;i++){
		c[i]=c[i-1],d[i]=d[i-1];
		if (s[i]=='U')d[i]++;
		if (s[i]=='D')d[i]--;
		if (s[i]=='L')c[i]--;
		if (s[i]=='R')c[i]++;
	}
	int l=1,r=1e18,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}