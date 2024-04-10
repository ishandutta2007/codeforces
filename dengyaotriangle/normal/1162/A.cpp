#include<bits/stdc++.h>

using namespace std;

const int maxn=55;

int mx[maxn];
int n,h,m;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>h>>m;
	for(int i=1;i<=n;i++) mx[i]=h;
	for(int i=1;i<=m;i++){
		int l,r,x;cin>>l>>r>>x;
		for(int j=l;j<=r;j++)mx[j]=min(mx[j],x);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=mx[i]*mx[i];
	}
	cout<<ans;
	return 0;
}