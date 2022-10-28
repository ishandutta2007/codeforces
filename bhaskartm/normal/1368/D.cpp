#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	int val[n];
	for(int i=0; i<n; i++){
		val[i]=0;
	}
	
	for(int i=0; i<=20; i++){
		int cnt=0;
		for(int j=0; j<n; j++){
			if((arr[j]&(1<<i))==(1<<i)){
				cnt++;
			}
		}
		
		for(int j=0; j<cnt; j++){
			val[j]+=(1<<i);
		}
	}
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=(val[i])*(val[i]);
	}
	cout<<sum;
	return 0;
}