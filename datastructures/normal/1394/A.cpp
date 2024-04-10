#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std; 
int n,d,m,c[100005],a[100005],b[100005],len1,len2,now,ans;
signed main(){
	cin>>n>>d>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if (c[i]<=m)a[++len1]=c[i];
		else b[++len2]=c[i];
	}
	sort(a+1,a+1+len1);
	sort(b+1,b+1+len2);
	int sum1=0,sum2=0;
	for (int i=1;i<=len1;i++)sum1+=a[i];
	int r1=1;
	for (int i=0;i<=len2&&(i-1)*(d+1)<n;i++){
		int del=max(0ll,(i-1)*d-(len2-i));
		sum2+=b[len2-i+1];
		while(r1<=del)sum1-=a[r1],r1++;
		ans=max(ans,sum1+sum2);
	}
	cout<<ans<<endl;
	return 0;
}