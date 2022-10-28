#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int arr[300005];

int n;
int ans;


bool isma(int i){
	if(i==0){
		if(arr[0]>arr[1]){
			return 1;
		}
	}
	if(i==n-1){
		if(arr[n-1]>arr[n-2]){
			return 1;
		}
	}
	if(arr[i]>arr[i-1 ] && arr[i]>arr[i+1]){
		return 1;
	}
	return 0;
}


bool ismi(int i){
	if(i==0 || i==n-1){
		return 0;
	}
	if(arr[i]<arr[i-1 ] && arr[i]<arr[i+1]){
		return 1;
	}
	return 0;
}

bool che(int i){
	if(i>=0 && i<n){
		return 1;
	}
	return 0;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int  q;
		ans=0;
		
		cin>>n>>q;
	
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		if(n==1){
			cout<<arr[0]<<endl;
			while(q--){
				int l, r;
				cin>>l>>r;
				cout<<arr[0]<<endl;
			}
			continue;
		}
		for(int i=0; i<n; i++){
			bool b=isma(i);
			if(b){
				
				ans+=arr[i];
			}
		}
		for(int i=1; i<n-1; i++){
			bool b=ismi(i);
			if(b){
				
				ans-=arr[i];
			}
		}
		cout<<ans<<endl;
		while(q--){
			int l, r;
			cin>>l>>r;
			l--;
			r--;
			int a1=0;
			set<int>se;
			se.insert(l);
			se.insert(l-1);
			se.insert(l+1);
			se.insert(r);
			se.insert(r-1);
			se.insert(r+1);
			for(auto u:se){
				if(che(u) && isma(u)){
					a1-=arr[u];
				}
			}
			for(auto u:se){
				if(che(u) && ismi(u)){
					a1+=arr[u];
				}
			}
			int temp=arr[l];
			arr[l]=arr[r];
			arr[r]=temp;
			for(auto u:se){
				if(che(u) && isma(u)){
					a1+=arr[u];
				}
			}
			for(auto u:se){
				if(che(u) && ismi(u)){
					a1-=arr[u];
				}
			}
			ans+=a1;
			cout<<ans<<endl;
		}
	}
	return 0;
}