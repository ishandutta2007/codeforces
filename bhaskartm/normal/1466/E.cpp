#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e9+7;

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	int po[61];
	
	po[0]=1;
	for(int i=1; i<=60; i++){
		po[i]=2*po[i-1];
	}
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int cnt[61];
		for(int i=0; i<=60; i++){
			cnt[i]=0;
		}
		for(int i=0; i<n; i++){
			cin>>arr[i];
			for(int j=0; j<=60; j++){
				if((arr[i]&(po[j]))!=0){
					cnt[j]++;
				}
			}
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int sum1=0;
			int sum2=0;
			for(int j=0; j<=60; j++){
				if(!(arr[i]&po[j])){
					continue;
				}
				sum1=(sum1+cnt[j]*(po[j]%N))%N;
			}
			for(int j=0; j<=60; j++){
				if((arr[i]&po[j])){
					sum2=(sum2+n*(po[j]%N))%N;
				}
				else{
					sum2=(sum2+(po[j]%N)*cnt[j])%N;
				}
			}
			ans=(ans+sum1*sum2)%N;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}