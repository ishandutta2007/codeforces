#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200003];
int main(){
	long long T;cin>>T;while(T--){cin>>n>>k;
		for(long long i=0;i<n;i++)scanf("%d",a+i);
		map<long long,long long>mp;
		for(long long i=0;i<n;i++)mp[a[i]%k]++;
		long long ans=-1;
		for(long long i=0;i<n;i++)
			if(a[i]%k!=0)
				ans=max(ans,(mp[a[i]%k]-1)*1ll*k+k-a[i]%k);
		cout<<ans+1<<endl;
	}
}