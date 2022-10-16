#include<bits/stdc++.h>
using namespace std;
int n,d,m,a[100003];
long long sum[100003],ans,now,lst[100003];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(a[i]<=m)
			v.push_back(a[i]);
	for(int i=1;i<=v.size();i++)
		lst[i]=lst[i-1]+v[i-1];
	for(int i=v.size()+1;i<=n;i++)
		lst[i]=lst[i-1];
	if(a[1]<=m){cout<<sum[n];return 0;}
	for(int i=1;i<=n;i++){//i 
		if(a[i]<=m)break;
		if((i-1)*(d+1)+1>n)break;
		now=sum[i];
		int lsttime=n-(i-1)*(d+1)-1;
		now+=lst[lsttime];
		ans=max(ans,now); 
	}
	cout<<ans;
}