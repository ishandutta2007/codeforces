#include<bits/stdc++.h>
using namespace std;
map<long long,bool>mp;
long long n,a,sum,now,ans,m;
int main(){cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",&a);
		sum+=a;mp[sum]=1;
	}cin>>m;
	for(int i=0;i<m;i++){
		scanf("%lld",&a);
		now+=a;ans+=mp[now];
	} 
	if(sum==now)
		cout<<ans;
	else
		cout<<-1;
}