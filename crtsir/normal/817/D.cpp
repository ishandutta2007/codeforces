#include<bits/stdc++.h>
using namespace std;
long long n,a[1000003];
pair<long long,long long>b[1000003];
long long calc1(){
	for(int i=0;i<n;i++)b[i]=make_pair(-a[i],i);
	sort(b,b+n);
	set<signed>s1;
	s1.insert(-1);s1.insert(n);
	long long ret=0;
	for(int i=0;i<n;i++){
		set<int>::iterator tmpr=s1.lower_bound(b[i].second),tmpl=prev(tmpr);
		ret-=(b[i].second-*tmpl)*(*tmpr-b[i].second)*b[i].first;
		s1.insert(b[i].second);
	}
	return ret;
}
long long calc2(){
	for(int i=0;i<n;i++)b[i]=make_pair(-b[i].first,b[i].second);
	for(int i=0;i<n/2;i++)swap(b[i],b[n-i-1]);
	set<signed>s1;
	s1.insert(-1);s1.insert(n);
	long long ret=0;
	for(int i=0;i<n;i++){
		set<int>::iterator tmpr=s1.lower_bound(b[i].second),tmpl=prev(tmpr);
		ret+=(b[i].second-*tmpl)*(*tmpr-b[i].second)*b[i].first;
		s1.insert(b[i].second);
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	cout<<calc1()-calc2();
}