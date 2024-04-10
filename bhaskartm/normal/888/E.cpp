#include <bits/stdc++.h>
using namespace std;
#define int long long int
 main() {
	int n, m;
	cin>>n>>m;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	if(n==1){
		cout<<(arr[0]%m);
		return 0;
	}
	set<int>s1;
	for(int i=0; i<(1LL<<(n/2)); i++){
		int num=0;
		int bits=(n/2);
		for(int j=0; j<(n/2); j++){
			if(((1LL<<((n/2)-1-j)) & i)==(1LL<<((n/2)-1-j))){
				num=num+arr[j];
			}
		}
		num=num%m;
		s1.insert(num);
	}
	
	set<int>s2;
	for(int i=0; i<(1LL<<(n-(n/2))); i++){
		
		int num=0;
		for(int j=0; j<(n-(n/2)); j++){
			if(((1LL<<((n-(n/2))-1-j)) & i)==(1LL<<((n-(n/2))-1-j))){
				num+=arr[(n/2)+j];
			}
		}
		
		num=num%m;
		s2.insert(num);
	}
	
	int maxi=0;
	for(auto it=s1.begin(); it!=s1.end(); it++){
		int val=(*it);
		auto it1=s2.lower_bound(m-val);
		if(it1!=s2.begin()){
			it1--;
		}
		maxi=max(maxi, val+(*it1));
	}
	
	
	auto it1=s1.end();
	it1--;
	auto it2=s2.end();
	it2--;
	maxi=max(maxi, ((*it1)+(*it2))%m);
	cout<<maxi<<endl;
	return 0;
}