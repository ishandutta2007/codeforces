#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;
const int M=105;
int arr[N];
int cnt[M];
int pre[N];
vector<vector<int>>vec;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int maxi=-1;
	int ind=-1;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		cnt[arr[i]]++;
		if(cnt[arr[i]]>maxi){
			maxi=cnt[arr[i]];
			ind=arr[i];
		}
	}
	
	int ans=0;
	for(int i=1; i<=100; i++){
		if(i==ind){
			continue;
		}
		pre[0]=N;
		int minim=2e5+5;
		for(int j=1; j<=n; j++){
			if(arr[j]==i){
				pre[j]=pre[j-1]-1;
			}
			else if(arr[j]==ind){
				pre[j]=pre[j-1]+1;
			}
			else{
				pre[j]=pre[j-1];
			}
			minim=min(minim, pre[j]);
		}
		vec.clear();
		vec.resize(N);
		for(int j=0; j<=n; j++){
			vec[pre[j]-minim].pb(j);
		}
		for(int i=0; i<N; i++){
			if(int(vec[i].size())<2){
				continue;
			}
			ans=max(ans, vec[i].back()-vec[i][0]);
		}
	}
	cout<<ans;
	
	return 0;
}