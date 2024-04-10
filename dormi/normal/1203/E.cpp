#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	bool used[150002];
	memset(used,false,sizeof(used));
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		if(!used[arr[i]+1]){
			used[arr[i]+1]=true;
			cnt++;
			continue;
		}
		if(!used[arr[i]]){
			used[arr[i]]=true;
			cnt++;
			continue;
		}
		if(arr[i]-1>0){
			if(!used[arr[i]-1]){
				used[arr[i]-1]=true;
				cnt++;
				continue;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}