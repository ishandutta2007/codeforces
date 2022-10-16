#include<bits/stdc++.h>
using namespace std;
long long a[500003],n,qzh[500003],ans[500003];
int main(){
	//freopen("join.out","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)qzh[i+1]=qzh[i]+a[i];
	long long j=0,cnt=0;
	for(long long i=1;i<=n;i++){
		long long l=qzh[n]-qzh[n-i];
		long long r=i*(i-1);
		while(j<n&&a[j]<i)j++;
		cnt++;
		long long up=min(n-i,j*1ll);
		r+=qzh[up]+i*(n-i-up);
		long long bound=a[n-i];
		long long diff=l-r;
		if(diff<=i&&diff<=bound){
			ans[max(diff,0ll)]++;
			ans[bound+1]--;
		}
		l-=a[n-i];
		r+=min(a[n-i],i*1ll);
		diff=r-l;
		if(diff>bound){
			ans[bound+1]++;
			ans[min(diff+1,n+1)]--;
		}
	}
	vector<int>res;
	int num=0;
	for(int i=0;i<=n;i++)
	{
		num+=ans[i];
		if(num==n&&(qzh[n]+i)%2==0)
			res.push_back(i);
	}
	if(res.size()==0){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<res.size();i++)cout<<res[i]<<' ';
}