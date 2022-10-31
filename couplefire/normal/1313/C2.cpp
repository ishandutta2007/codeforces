#include<bits/stdc++.h>
using namespace std;
int n,a[500005],maxp,st[500005],top;
long long maxx=0,f[500005],g[500005];
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>a[i])top--;
		st[++top]=i;
		f[i]=f[st[top-1]]+1ll*(i-st[top-1])*a[i];
	}
	top=0,st[0]=n+1;
	for(int i=n;i>=1;i--){
		while(top&&a[st[top]]>a[i])top--;
		st[++top]=i;
		g[i]=g[st[top-1]]+1ll*(st[top-1]-i)*a[i];
		if(maxx<f[i]+g[i]-a[i])maxx=f[i]+g[i]-a[i],maxp=i;
	}
	int now=a[maxp];
	for(int j=maxp-1; j>0; j--) {
		now=a[j]=min(now,a[j]);
	}
	now=a[maxp];
	for(int j=maxp+1; j<=n; j++) {
		now=a[j]=min(now,a[j]);
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}