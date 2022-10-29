#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
			arr[i]+=i;
			arr[i]=(arr[i]%n);
			if(arr[i]<0){
				arr[i]+=n;
			}
		}
		set<int>s;
		for(int i=0; i<n; i++){
			s.insert(arr[i]);
		}
		if(s.size()==n){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}