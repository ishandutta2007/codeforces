#include<bits/stdc++.h>
using namespace std;
long long n,a[500003],k,t,ans,sz;
bool used[500003];
int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	t=log2(n);
	for(int i=0;i<n;i++)
		if(a[i]==-1)
			k=i;
	int T=0;
	while(k)
		k=(k-1)/2,T++;
	T=t-T;sz=n-1;
	while(T--){
		pair<long long,long long>res=make_pair(2147483647,-1);
		for(long long i=sz;i<n;i++)
			if(!used[i]&&a[i]!=-1)
				res=min(res,make_pair(a[i],i));
		ans+=res.first;
		sz=(sz-1)/2;
		used[res.second]=1;
	}
	cout<<ans;
}