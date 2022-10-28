#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
int sv[10000005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2; i<=10000000; i++){
		if(sv[i]){
			continue;
		}
		for(int j=2*i; j<=10000000; j=j+i){
			if(sv[j]==0){
				sv[j]=i;
			}
		}
	}
	for(int i=2; i<=10000000; i++){
		if(sv[i]==0){
			sv[i]=i;
		}
	}
	int n;
	cin>>n;
	int arr[n];
	int ans1[n];
	int ans2[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		int num=arr[i];
		int val=sv[num];
		if(val==arr[i]){
			ans1[i]=-1;
			ans2[i]=-1;
			continue;
		}
		while(num%val==0){
			num=num/val;
		}
		if(num==1){
			ans1[i]=-1;
			ans2[i]=-1;
		}
		else{
			ans1[i]=val;
			ans2[i]=num;
		}
	}
	for(int i=0; i<n; i++){
		cout<<ans1[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<ans2[i]<<" ";
	}
	return 0;
}