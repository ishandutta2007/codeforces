#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
lli bit[200001];
int n;
void update(int loc){
	lli add=loc;
	for(;loc<=n;loc+=loc&-loc){
		bit[loc]+=add;
	}
}
lli start(int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc){
		sum+=bit[loc];
	}
	return sum;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	lli arr[n];
	lli sumto[n+1];
	sumto[0]=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sumto[i+1]=sumto[i]+i+1;
	}
	int ans[n];
	for(int i=n-1;i>=0;i--){
		int lo=1;
		int hi=n;
		while(lo!=hi){
			int mid=(lo+hi)/2;
			lli te=start(mid);
			lli te2=start(mid-1);
			if(te!=te2){
				if (sumto[mid] - te <= arr[i])lo = mid+1;
				else hi=mid-1;
			}
			else {
				if (sumto[mid] - te-(lli)mid >= arr[i])hi = mid;
				else lo = mid + 1;
			}
		}
		ans[i]=lo;
		update(lo);
	}
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}