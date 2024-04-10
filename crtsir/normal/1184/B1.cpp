#include<bits/stdc++.h>
using namespace std;
long long s,b,ans[100003];
pair<long long,long long>x[100003],a[100003];
int main(){
	cin>>s>>b;
	for(long long i=0;i<s;i++)cin>>a[i].first,a[i].second=i;
	for(long long i=1;i<=b;i++)
		cin>>x[i].first>>x[i].second;
	sort(x,x+b+1);
	sort(a,a+s);
	x[0]=make_pair(0,0);
	for(long long i=1;i<=b;i++)x[i].second+=x[i-1].second;
	long long j=0;
	for(long long i=0;i<s;i++)
	{
		for(;a[i].first>=x[j].first&&j<=b;j++);
		j--;
		ans[a[i].second]=x[j].second;
	}
	for(long long i=0;i<s;i++)cout<<ans[i]<<' ';
}