#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[300003],b[300003],ans=1;
pair<int,int>c[300003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i],c[i]=make_pair(a[i],b[i]),ans=ans*(i+1)%mod;
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	long long cnt=1,res=1;
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])
			res=res*cnt%mod,
			cnt=1;
		else
			res=res*cnt%mod,
			cnt++;
	res*=cnt;
	res%=mod;
	ans=(ans-res+mod)%mod;
	cnt=1,res=1;
	for(int i=1;i<n;i++)
		if(b[i]!=b[i-1])
			res=res*cnt%mod,
			cnt=1;
		else
			res=res*cnt%mod,
			cnt++;
	res*=cnt;
	res%=mod;
	ans=(ans-res+mod)%mod;
	bool can=1;
	int maxn=c[0].second;
	for(int i=1;i<n;i++)
		if(c[i].second<maxn)
			can=0;
		else
			maxn=c[i].second;
	if(can){
		cnt=1,res=1;
			for(int i=1;i<n;i++)
			if(c[i]!=c[i-1])
				res=res*cnt%mod,
				cnt=1;
			else
				res=res*cnt%mod,
				cnt++;
		res*=cnt;
		res%=mod;
		ans=(ans+res)%mod;
	}
	cout<<ans;
}