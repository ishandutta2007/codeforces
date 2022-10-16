#include<bits/stdc++.h>
using namespace std;
int n,p,a[100003];
bool check(int x){vector<int>v;
	for(int i=0;i<n;i++)
		if(x+n-1<a[i])return 0;
		else
			v.push_back(min(n-a[i]+x,n));
	sort(v.begin(),v.end());
	long long ret=1;
	for(int i=0;i<n;i++)
		if(v[i]-i>0&&ret)
			ret=ret*(v[i]-i)%p;
		else return 0;
	return 1;
}
bool cmp(int x,int y){return x>y;} 
int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>a[i];vector<int>ans;
	sort(a,a+n,cmp);
	for(int i=1;i<=2000;i++)
		if(check(i))
			ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
}