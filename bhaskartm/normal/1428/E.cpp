#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int f(int val, int x){
	int y=val%x;
	int z=x-y;
	int num1=(val/x);
	int num2=(val/x)+1;
	return num2*num2*y+num1*num1*z;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	set<pair<pair<int, int>, pair<int, int>>>se;
	for(int i=0; i<n; i++){
		int val=arr[i];
		int val1=arr[i]/2;
		int val2=arr[i]-val1;
		se.insert({{f(arr[i], 1)-f(arr[i], 2), arr[i]*arr[i]}, {i, 1}});
	}
	while(n!=k){
		n++;
		auto it=se.end();
		it--;
		se.erase((*it));
		int num=(*it).s.s;
		num++;
		int val1=f(arr[(*it).s.f], num);
		int val2=f(arr[(*it).s.f], num+1);
		se.insert({{val1-val2, val1}, {(*it).s.f, num}});
	}
	int ans=0;
	for(auto u:se){
		ans+=(u.f.s);
	}
	cout<<ans;
	return 0;
}