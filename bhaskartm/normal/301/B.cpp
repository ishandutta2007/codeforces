#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second

int n, d;
pair<int, int>arr[105];
int cost[105];
int dis[105];

bool f(int x){
	for(int i=1; i<=n; i++){
		dis[i]=-1;
	}
	dis[1]=x;
	for(int i=0; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(j==k){
					continue;
				}
				if(dis[j]>=0 && (dis[j]-d*(abs(arr[j].f-arr[k].f)+abs(arr[j].s-arr[k].s)))>=0 && (dis[j]-d*(abs(arr[j].f-arr[k].f)+abs(arr[j].s-arr[k].s))+cost[k])>=dis[k]){
					dis[k]=dis[j]-d*(abs(arr[j].f-arr[k].f)+abs(arr[j].s-arr[k].s))+cost[k];
				}
			}
		}
	}
	return (dis[n]>=0);
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>d;
	for(int i=2; i<=n-1; i++){
		cin>>cost[i];
	}
	for(int i=1; i<=n; i++){
		cin>>arr[i].f>>arr[i].s;
	}
	int lo=0;
	int hi=1e8;
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(f(mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans;
	return 0;
}