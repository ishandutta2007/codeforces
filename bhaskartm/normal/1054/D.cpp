#include<bits/stdc++.h>
using namespace std;
map<long long int, long long int>m;
int main() {
	long long int n, k;
	cin>>n>>k;
	long long int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vector<long long int>v;
	long long int val=0;
	v.push_back(val);
	for(long long int i=0; i<n; i++){
		val=(val^(arr[i]));
		v.push_back(val);
	}
	for(int i=0; i<v.size(); i++){
		m[v[i]]++;
	}
	long long int ans=0;
	for(auto it=m.begin(); it!=m.end(); it++){
		long long int val=(it->first);
		long long int num=(it->second);
		long long int val2=((1<<k)-1)^(val);
		long long int num2=m[val2];
		m[val]=(num+num2)/2;
		m[val2]=num+num2-((num+num2)/2);
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		ans=ans+(n+1-(it->second))*(it->second);
	}
	cout<<(ans/2)<<endl;
	return 0;
}