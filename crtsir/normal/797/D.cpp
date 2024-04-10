#include<bits/stdc++.h>
using namespace std;
int n,a[100003],l[100003],r[100003],d[100003],ll[100003],rr[100003];
map<int,bool>mp;
void dfs(int x){
	if(ll[x]<=a[x]&&a[x]<=rr[x])
		mp[a[x]]=1;
	if(l[x]!=-2){
		ll[l[x]]=ll[x];
		rr[l[x]]=min(a[x]-1,rr[x]);
		dfs(l[x]);
	}
	if(r[x]!=-2){
		ll[r[x]]=max(a[x]+1,ll[x]);
		rr[r[x]]=rr[x];
		dfs(r[x]);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",a+i,l+i,r+i);
		l[i]--;r[i]--;
		if(l[i]>=0)d[l[i]]++;
		if(r[i]>=0)d[r[i]]++;
	}
	for(int i=0;i<n;i++)
		if(!d[i]){
			ll[i]=-1;
			rr[i]=1000000007;
			dfs(i);
		}
	int ans=n;
	for(int i=0;i<n;i++)
		ans-=mp[a[i]];
	cout<<ans;
}