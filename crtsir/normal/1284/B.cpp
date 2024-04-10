#include<bits/stdc++.h>
using namespace std;
int n;
pair<pair<vector<int>,bool>,pair<int,int> >k;
int mx[100003],mn[100003];
long long ans,cnt,res[100003],cntt;
int solve(int maxn){
	int l=0,r=cnt-1;
	if(maxn<=mn[0])return 0;
	while(l!=r){
		int mid=(l+r)/2;
		if(mn[mid]>=maxn)
			r=mid-1;
		else
			l=mid;
		if(mn[l+1]<maxn)l++;
		if(mn[r]>=maxn)r--;
	}
	return l+1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,minn=2147483647;mn[cnt]=2147483647;k.second.second=2147483647,k.second.first=0;
		cin>>a;bool can=0;
		for(int j=0;j<a;j++){
			int b;
			cin>>b;
			if(minn<b&&!can)can=1,ans=ans+2*(n-cntt++)-1;
			else minn=b;
			k.second.first=max(k.second.first,b);k.second.second=min(k.second.second,b);
		}
		if(!can)mx[cnt]=k.second.first,mn[cnt]=k.second.second,cnt++;
	}
	sort(mn,mn+cnt);
	for(int i=0;i<cnt;i++)ans+=solve(mx[i]);
	cout<<ans;
}