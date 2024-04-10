#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
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
	for(int i=0; i<n; i++){
		if(arr[i]==0){
			continue;
		}
		bool b=0;
		if(arr[i]<0){
			arr[i]=-arr[i];
			b=1;
		}
		for(int x=2; x*x<=arr[i]; x++){
			while(arr[i]%(x*x)==0){
				arr[i]=arr[i]/(x*x);
			}
		}
		if(b==1){
			arr[i]=-arr[i];
		}
	}
	
	
	int ind[n];
	int used=1;
	map<int,int>m;
	for(int i=0; i<n; i++){
		if(m[arr[i]]!=0){
			ind[i]=m[arr[i]];
		}
		else{
			ind[i]=used;
			m[arr[i]]=used;
			used++;
		}
	}
	int ans[n+1];
	for(int i=0; i<=n; i++){
		ans[i]=0;
	}
	
	
	for(int i=0; i<n; i++){
		int cnt[5005];
		for(int j=0; j<5005; j++){
			cnt[j]=0;
		}
		int num=0;
		for(int k=i; k<n; k++){
			cnt[ind[k]]++;
			if(cnt[ind[k]]==1){
				if(arr[k]!=0){
					num++;
				}
			}
			if(num==0){
				ans[1]++;
			}
			ans[num]++;
		}
	}
	for(int i=1; i<=n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}