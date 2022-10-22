#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
string s[N+1];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	int ans=0;
	for(int i=0;i<m;i++){
		int cnt[5]={};
		for(int j=1;j<=n;j++)cnt[s[j][i]-'A']++;
		int poi;
		cin>>poi;
		ans+=poi*max(cnt[0],max(cnt[1],max(cnt[2],max(cnt[3],cnt[4]))));
	}
	cout<<ans;
	return 0;
}