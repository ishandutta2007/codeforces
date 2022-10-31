#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn];
int l[maxn],r[maxn];
const int INF = 0x3f3f3f3f;
int maxx=-INF,minn = INF;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
	if (k==1){
		cout<<minn<<endl;
		return 0;
	}
	if (k>=3){
		cout<<maxx<<endl;
		return 0;
	}
	l[0]=a[0];
	for (int i=1;i<n;i++){
		l[i]=min(l[i-1],a[i]);
	}
	r[n-1]=a[n-1];
	for (int i=n-2;i>=0;i--){
		r[i] =min(r[i+1],a[i]);
	}
	int ans = -INF;
	for (int i=0;i<n-1;i++){
		ans = max(ans,max(l[i],r[i+1]));
	}
	cout<<ans<<endl;
	return 0;
}