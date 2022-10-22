#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[100004];
int main(){
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		ans+=a[i].second;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int j=i;
		long long now=a[i].first+a[i].second;
		while(j<n-1&&now>=a[j+1].first){
			j++;
			now=max(now,(long long)a[j].first+a[j].second);
		}
		i=j;
		if(i<n-1)ans+=a[i+1].first-now;
	}
	cout<<ans;
}