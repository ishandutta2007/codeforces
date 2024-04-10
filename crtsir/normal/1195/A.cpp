#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[1003],a,ans;
int main(){
	cin>>n>>m;
	m=(n+1)/2;
	for(int i=0;i<n;i++)cin>>a,cnt[a-1]++;
	for(int i=0;i<1003;i++)while(cnt[i]>1&&m)m--,ans+=2,cnt[i]-=2;
	cout<<min(n,ans+m);
}