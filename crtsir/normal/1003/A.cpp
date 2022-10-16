#include<bits/stdc++.h>
using namespace std;
int a,cnt[103],n,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a,
		cnt[a]++;
	for(int i=0;i<103;i++)
		ans=max(ans,cnt[i]);
	cout<<ans;
}